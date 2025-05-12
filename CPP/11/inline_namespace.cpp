#include <iostream>

namespace T1 {
    inline namespace T2 {
        struct T2Class {
            int value{};
        };

    }

}

int main() {

    T1::T2Class t2class { .value = 10 };
    std::cout << t2class.value << "\n";


    return 0;
}

