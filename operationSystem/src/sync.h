#pragma once

#include <thread>
#include <chrono>
#include <print>

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
    std::jthread t1([]() {
        while (turn != 0);
        std::println("t1进入临界区");
        turn = 1;
        std::println("t1进入剩余区");
    });
    std::jthread t2([]() {
        while (turn != 1);
        std::println("t2进入临界区");
        turn = 1;
        std::println("t2进入剩余区");
    });
}

void singleFlagFail()
{
    // 违背空闲让进
    static bool turn = 0;
    std::jthread t1([]() {
        // 这里t2也在跑但是无法进入临界区
        std::println("t1空闲了5秒");
        std::this_thread::sleep_for(std::chrono::seconds(5));

        while (turn != 0);
        std::println("t1进入临界区");
        turn = 1;
        std::println("t1进入剩余区");
    });
    std::jthread t2([]() {
        while (turn != 1);
        std::println("t2进入临界区");
        turn = 1;
        std::println("t2进入剩余区");
    });
}
}
