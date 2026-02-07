#pragma once

#include <chrono>
#include <print>
#include <thread>

/**
 * 注意这里的线程会退出，在题目中一般是不会退出一直循环代码的一个服务（代码最外层有一个一直运行的while）
 */

namespace operationSystem
{
/**
 * 但标志法
 * 违反空闲让进
 */
void singleFlag()
{
    // 只适合交替进入
    static bool turn = 0;
    std::jthread t1(
        []()
        {
            while (turn != 0)
                ;
            std::println("t1进入临界区");
            turn = 1;
            std::println("t1进入剩余区");
        });
    std::jthread t2(
        []()
        {
            while (turn != 1)
                ;
            std::println("t2进入临界区");
            turn = 1;
            std::println("t2进入剩余区");
        });
}

void singleFlagFail()
{
    // 违背空闲让进
    static bool turn = 0;
    std::jthread t1(
        []()
        {
            // 这里t2也在跑但是无法进入临界区
            std::println("t1空闲了5秒");
            std::this_thread::sleep_for(std::chrono::seconds(5));

            while (turn != 0)
                ;
            std::println("t1进入临界区");
            turn = 1;
            std::println("t1进入剩余区");
        });
    std::jthread t2(
        []()
        {
            while (turn != 1)
                ;
            std::println("t2进入临界区");
            turn = 1;
            std::println("t2进入剩余区");
        });
}

/**
 * 双标志先检查法
 */
void twoFlagsPreCheck()
{
    static bool flags[] = {false, false};

    std::jthread t1(
        []()
        {
            /**
             * 如果对让正在使用就等待
             */
            while (flags[1])
                ;

            flags[0] = true;
            std::println("t1进入临界区");
            flags[0] = false;

            std::println("t1进入剩余区");
        });
    std::jthread t2(
        []()
        {
            while (flags[0])
                ;

            flags[1] = true;
            std::println("t2进入临界区");
            flags[1] = false;
            std::println("t2进入剩余区");
        });
}

/**
 * 双标志先检查法
 * 违反了忙则等待，下面的代码两个线程可以一起访问临界区
 */
void twoFlagsPreCheckFail()
{
    static bool flags[] = {false, false};

    std::jthread t1(
        []()
        {
            /**
             * 如果对方正在使用就等待
             */
            while (flags[1])
                ;

            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::println("t1被挂起2秒");

            flags[0] = true;
            std::println("t1进入临界区");
            flags[0] = false;

            std::println("t1进入剩余区");
        });
    std::jthread t2(
        []()
        {
            while (flags[0])
                ;

            flags[1] = true;
            std::println("t2进入临界区");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            flags[1] = false;
            std::println("t2进入剩余区");
        });
}

} // namespace operationSystem
