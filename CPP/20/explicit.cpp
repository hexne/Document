#include <iostream>

struct S1 {
    int value;

    explicit (false) operator int() {
        return value;
    }

};

void func(int val) {
    std::cout << val << std::endl;
}


int main() {

    S1 s{10};
    func(s);

}
