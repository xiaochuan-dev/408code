/**
 * 数据校验
 */

#pragma once

#include <string>
#include <tuple>
#include <format>
#include <functional>
#include <cstdint>

namespace computerOrganization
{
/**
 * 这里只实现7位的源数据，加校验位8位
 */
std::function<std::tuple<uint8_t, uint8_t, std::string>(uint8_t)> make_checksum(bool even = true)
{
    auto generate = [even](uint8_t input) {

        uint8_t checkflag = input & 1;
        for (size_t i = 1; i < 8; i++)
        {
            checkflag ^= ((input >> i) & 1);
        }
        
        if (!even) checkflag = !checkflag;

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
} // namespace computerOrganization
