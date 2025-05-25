template <int *p> 
struct X {  };

struct S{
    int v;
    static int sv;
    int arr[10];
    static int sarr[10];
}s;

int main () {

    int val;
    static int sval{};


    // X<&val> x1; error, 非静态
    X<&sval> x2; // ok, 静态

    // X<&s.v> x3; error ,非静态成员
    X<&S::sv> x4;
   
    // X<&s.arr[0]> x5; error 非静态, 且指针为指向数组元素的指针
    // X<&S::sarr[0]> x6; 指向数组元素的指针不能用于常量模板参数, C++ 20 后允许



    return 0;
}
