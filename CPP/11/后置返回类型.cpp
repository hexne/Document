#include <iostream>

// decltype(num1 + num2), 此时num1 和 num2还没有定义，使用auto占位
auto add(int num1, int num2) -> decltype(num1 + num2) {
    return num1 + num2;
}

