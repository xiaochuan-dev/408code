/**
 * 数据校验
 */

#pragma once

#include <string>
#include <tuple>
#include <format>
#include <functional>


namespace computerOrganization
{

std::function<std::tuple<int, std::string>(std::string)> make_checksum(bool even = true)
{
    auto generate = [even](std::string str) {

        int checkflag = *(str.begin()) - '0';
        for (auto it = str.begin() + 1; it != str.end(); ++it)
        {
            checkflag ^= ((*it) - '0');
        }
        
        if (!even) checkflag = !checkflag;

        auto res = std::format("{}{}", str, checkflag);
        return std::make_tuple(checkflag, res);
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
