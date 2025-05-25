namespace A::B::C {
    int val{};
}

// 等价于
namespace A {
    namespace B {
        namespace C {
            // int val
        }
    }
}


