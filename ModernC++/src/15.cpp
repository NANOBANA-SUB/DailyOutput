/*IPv4データ型を定義する問題*/
#include <array>
#include <string>
#include <sstream>
#include <istream>
#include <ostream>

class IPv4
{
    std::array<unsigned char, 4> data;

public:
    constexpr IPv4():IPv4(0, 0, 0, 0) {}
    constexpr IPv4(unsigned char const a, unsigned char const b,
    unsigned char const c, unsigned char const d):
    data{{a, b, c, d}} {}
    explicit constexpr IPv4(unsigned long a)
    :   IPv4(static_cast<unsigned char>((a >> 24) & 0xFF), // 24ビット分シフトし、0xFFをマスクすることによって第一オクテットを取得
             static_cast<unsigned char>((a >> 16) & 0xFF),
             static_cast<unsigned char>((a >> 8) & 0xFF),
             static_cast<unsigned char>(a & 0xFF)) {}
    IPv4(IPv4 const& other) noexcept : data(other.data) {}

    IPv4& operator=(const IPv4& other) noexcept
    {
        data = other.data;
        return *this;
    }
    
    std::string to_string() const
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    constexpr unsigned long to_ulong() const noexcept
    {
        return
        (static_cast<unsigned long>(data[0]) << 24) |
        (static_cast<unsigned long>(data[1]) << 16) |
        (static_cast<unsigned long>(data[2]) << 8) |
        (static_cast<unsigned long>(data[3])) ;
    }

    
};