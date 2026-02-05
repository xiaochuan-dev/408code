/**
 * 整数与浮点的编码
 */

#include <climits>
#include <cfloat>
#include <tuple>
#include <string>
#include <format>
#include <bitset>

namespace computerOrganization
{

/**
 * 这里只给出16位的整数的内存内容，32位64位依次
 */
std::tuple<std::string, std::string, std::string, std::string> getInt16Duration()
{
    short num1 = INT16_MAX;

    std::string hex1 = std::format("{:04x}", num1);
    std::string b1 = std::format("{:016b}", std::bit_cast<unsigned short>(num1));

    short num2 = INT16_MIN;
    auto _num2 = std::bit_cast<unsigned short>(num2);

    std::string hex2 = std::format("{:04x}", _num2);
    std::string b2 = std::format("{:016b}", _num2);

    return std::make_tuple(hex1, b1, hex2, b2);
}

/**
 * 获取float的最大值和最小值，double一样的逻辑这里不实现
 */
std::tuple<std::string, std::string, std::string, std::string> getFloatDuration()
{

    float _max = FLT_MAX;
    auto _max_num = std::bit_cast<unsigned int>(_max);
    std::string hex1 = std::format("{:08x}", _max_num);
    std::string b1 = std::format("{:032b}", _max_num);

    float _min = FLT_MIN;
    auto _min_num = std::bit_cast<unsigned int>(_min);
    std::string hex2 = std::format("{:08x}", _min_num);
    std::string b2 = std::format("{:032b}", _min_num);

    return std::make_tuple(hex1, b1, hex2, b2);
}
}

