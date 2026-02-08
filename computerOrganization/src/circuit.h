/**
 * 本文件表示运算的电路表示，运算中只能用位运算
 */


#pragma once

#include <cstdint>
#include <tuple>
#include <bitset>

namespace computerOrganization
{
/**
 * 全加器
 * x 数1
 * y 数2
 * c 输入进位
 */
std::tuple<uint32_t, uint32_t> fullAdder(uint32_t x, uint32_t y, uint32_t c)
{
    uint32_t xnor = x ^ y;

    uint32_t s = xnor ^ c;

    /**
     * next_c1表示xy都为1，两个1相加已经产生进位了
     */
    uint32_t next_c1 = x & y;
    /**
     * next_c2表示c为1，同时xnor为1（即x或者y中有一个为1），这时也有进位
     */
    uint32_t next_c2 = c & xnor;

    /**
     * 进位有两个值 或， 一个是 x & y (xy) ,一个是 x ^ y ^ c ()
     */
    uint32_t next_c = next_c1 | next_c2;
    return {s, next_c};
}

/**
 * 4位串行加法器
 */
std::tuple<std::bitset<4>, uint32_t> serialAdder(std::bitset<4> input1, std::bitset<4> input2, uint32_t c0)
{
    std::bitset<4> s;

    auto [s1, c1] = fullAdder(input1[0], input2[0], c0);
    s.set(0, s1);
    auto [s2, c2] = fullAdder(input1[1], input2[1], c1);
    s.set(1, s2);
    auto [s3, c3] = fullAdder(input1[2], input2[2], c2);
    s.set(2, s3);
    auto [s4, c4] = fullAdder(input1[3], input2[3], c3);
    s.set(3, s4);

    return {s, c4};
}

/**
 * 先行进位加法器，进位是有下面的递推公式的，可以直接通过递推公式得到结果
 * 先行进位加法器不能用全加器实现，得把全加器拆开引出内部的两个重要输出
 * 进位Ci = G_{i-1}+C_{i-1}P{i-1}   G_{i-1} = X_{i-1}Y_{i-1} , P{i-1}=X_{i-1}^Y{i-1}
 */
std::tuple<std::bitset<4>, uint32_t> parallelAdder(std::bitset<4> input1, std::bitset<4> input2, uint32_t C0)
{
    uint32_t x0 = input1[0];
    uint32_t x1 = input1[1];
    uint32_t x2 = input1[2];
    uint32_t x3 = input1[3];

    uint32_t y0 = input2[0];
    uint32_t y1 = input2[1];
    uint32_t y2 = input2[2];
    uint32_t y3 = input2[3];

    // 开始第一轮时序
    auto G0 = x0 & y0;
    auto G1 = x1 & y1;
    auto G2 = x2 & y2;
    auto G3 = x3 & y3;

    auto P0 = x0 ^ y0;
    auto P1 = x1 ^ y1;
    auto P2 = x2 ^ y2;
    auto P3 = x3 ^ y3;
    // 开始第二轮时序, 注意这里能一次输出最终的结果所有只要一轮时序就可以完成并输出4个
    auto C1 = G0 | (C0 & P0);
    auto C2 = G1 | (C1 & P1);
    auto C3 = G2 | (C2 & P2);
    auto C4 = G3 | (C3 & P3);
    // 开始第三轮时序
    // 这是计算当前位的和，直接二进制模2加法也就是异或就行了
    auto s0 = P0 ^ C0;
    auto s1 = P1 ^ C1;
    auto s2 = P2 ^ C2;
    auto s3 = P3 ^ C3;

    std::bitset<4> s;
    s.set(0, s0);
    s.set(1, s1);
    s.set(2, s2);
    s.set(3, s3);
    return {s, C4};
}
}
