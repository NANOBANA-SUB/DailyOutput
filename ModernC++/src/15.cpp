/*IPv4データ型を定義する問題*/
#include <array>

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
};