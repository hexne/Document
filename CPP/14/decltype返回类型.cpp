#include <iostream>

// 直接推导返回类型，无需再后置返回
decltype(auto) add(int num1, int num2) {
    return num1 + num2;
}
