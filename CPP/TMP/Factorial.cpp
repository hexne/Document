#include <cstddef>
#include <iostream>
#include <iterator>

template <size_t N>
struct Factorial {
    constexpr static int value = Factorial<N - 1>::value * N;
};
template <>
struct Factorial<0> {
    constexpr static int value = 1;
};

template <size_t N>
constexpr int factorial_v = Factorial<N>::value;

int main () {

    static_assert(factorial_v<0> == 1);
    static_assert(factorial_v<5> == 120);

}
