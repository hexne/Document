#include <iostream>

// 其中待执行的下个语句是该 switch 语句的带 case 或 default 标号的语句
int main() {


    int val{};

    switch(val) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            std::cout << val << std::endl;
            [[fallthrough]];    // 创建直落语句，发生直落时编译器不应诊断

        default:
            break;
    }



    return 0;
}
