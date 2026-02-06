/**
 * 数据校验
 */

#pragma once

#include <cstdint>
#include <format>
#include <functional>
#include <string>
#include <tuple>

namespace computerOrganization
{
/**
 * 这里只实现7位的源数据，加校验位8位
 */
std::function<std::tuple<uint8_t, uint8_t, std::string>(uint8_t)>
make_checksum(bool even = true)
{
    auto generate = [even](uint8_t input)
    {
        uint8_t checkflag = input & 1;
        for (size_t i = 1; i < 8; i++)
        {
            checkflag ^= ((input >> i) & 1);
        }

        if (!even)
            checkflag = !checkflag;

        auto res = std::format("{:07b}{}", input, checkflag);
        return std::make_tuple(checkflag, (input << 1) | checkflag, res);
    };

    return generate;
}

/**
 * 偶校验生成，校验位在最后
 * 这里的输入是二进制字符串
 */
auto generateEven = make_checksum();
auto generateOdd = make_checksum(false);

/**
 * crc校验，这里生成多项式使用 x^4+x^3+x^2+1，即 11101
 * 原始数据长度不超过28bit，即k=28,r=4
 * 参数1是加了校验码的字符串
 * 参数2是加了校验码的数据
 * 参数3是校验码
 */
std::tuple<std::string, uint32_t, uint8_t> crc(uint32_t input)
{
    const uint8_t G = 0b11101;
    uint32_t num = input;

    for (size_t shift = 27; shift > 0; shift--)
    {
        uint32_t shiftNum = num >> shift;

        if ((shiftNum & 0b1000) == 0)
        {
            continue;
        }
        uint32_t temp = shiftNum ^ G;
        num = (temp << shift) | num;
    }

    std::string bstr = std::format("{:027b}{:05b}", input, num);
    return std::make_tuple(bstr, (input << 4) | num, num);
}

} // namespace computerOrganization
