#include <initializer_list>

int main() {

    auto val{10};      // 对于只有一个元素的初始化列表，自动推导将从该条目中推导
    // auto val1 {10, 20};  // 对于包含多个元素的初始化列表，自动推导是不合法的
    
    auto copy = {10}; // 对复制列表初始化，自动推导冒着推导出initializer_list ，否则不合法
    // auto copy1 = { 1, 1.0f }; error


}
