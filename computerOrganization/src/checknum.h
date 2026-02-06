/**
 * 数据校验
 */

#pragma once

#include <cstdint>
#include <format>
#include <functional>
#include <string>
#include <tuple>
#include <map>

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
 * CRC校验码，k+r不要超过32bit
 * 参数1是加了校验码的字符串
 * 参数2是加了校验码的数据
 * 参数3是校验码
 */

enum class CRCSTAND {
    CRC3,
    CRC4,
    CRC41,
    CRC42,
    CRC5
};

struct CRCT
{
    std::string name;
    uint32_t G;
    uint32_t checksumLength;
};

std::map<CRCSTAND, CRCT> CRCMAP = {
    {CRCSTAND::CRC3, CRCT{"CRC-3", 0b1011, 3}},
    {CRCSTAND::CRC4, CRCT{"CRC-4", 0b10011, 4}},
    {CRCSTAND::CRC41, CRCT{"CRC-41", 0b11101, 4}},
    {CRCSTAND::CRC42, CRCT{"CRC-42", 0b11001, 4}},
    {CRCSTAND::CRC5, CRCT{"CRC-5", 0b110101, 5}}
};

std::function<std::tuple<std::string, uint32_t, uint32_t>(uint32_t)>
crc(CRCSTAND s)
{
    CRCT c = CRCMAP[s];
    auto f = [c](uint32_t input) {
        const uint32_t G = c.G;
        /**
         * 先左移r位
         */
        uint32_t num = input << c.checksumLength;

        for (size_t shift = 31; shift >= c.checksumLength; shift--)
        {
            /**
             * 当前最高位为0直接跳过，为1进行异或，异或会改变num值，这是num值就是最后的余数
             */
            if ((num & (1 << shift)) == 0)
            {
                continue;
            }
            num ^= (G << (shift - c.checksumLength));
        }

        uint32_t res =  (input << c.checksumLength) | num;
        std::string bstr = std::format("{:032b}", res);
        return std::make_tuple(bstr, res, num);
    };
    return f;
}

auto crc41 = crc(CRCSTAND::CRC41);
auto crc42 = crc(CRCSTAND::CRC42);
auto crc5 = crc(CRCSTAND::CRC5);
} // namespace computerOrganization
