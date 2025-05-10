#include <iostream>
// alignas 指定类型或对象的对齐要求
// alignof 查询类型的对齐要求
//


// 削弱自然对齐的常量非良构
// struct alignas(3) test1 {  };

// 多个时取最大值
struct alignas(4) alignas(8) test2 {  };

// alignas(0) 始终被忽略


int main() {

//    test1 t1;

    test2 t2;
    std::cout << sizeof(t2) << " , " << alignof(test2) << std::endl;


    return 0;
}
