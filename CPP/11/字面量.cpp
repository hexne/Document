struct T {

};

// 整数字面量调用决策
// 1、operator ""X(unsigned long long num)
// 2、operator ""X(const char *str)
// 3、operator ""X<'ch1', 'ch2', ..., 'ck'>()


// 浮点数字面量决策
// 1、operator ""X(long_double)
// 2、operator ""X(const char *str)
// 3、operator ""X<'ch1', 'ch2', ..., 'ck'>()


// 字符串字面量决策
// 1、operator ""X<str>;
// 2、operator ""X(const char *str, int len)


// 字符字面量
// 1、operator ""X(char)
