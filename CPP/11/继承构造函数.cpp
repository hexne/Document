struct B {
    int val;

    B(int val) : val(val) {  }

};

struct D : B {
    using B::B;
    int x;
};


int main () {

    D d(10); // 调用B(int)
    d.x; // 是默认初始化，不会被初始化, 该问题会在C++17中被解决
    
    // D dd; D 没有默认构造函数



    return 0;
}
