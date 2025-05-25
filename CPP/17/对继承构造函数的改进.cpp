struct B {
    int val;
    B(int val) : val(val) {  }
};

struct D : B { 
    using B::B;
    int x;
};


int main () {

    D d(10); // 调用B(int), 继承的构造函数还会默认初始化所有派生类成员


    return 0;
}
