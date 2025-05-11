#include <type_traits>
#include <utility>
// 函数模板的重载决议中才会应用SFINAE
// C++ 11 之前
struct X {
    typedef int type;
    using type_size = int;
    using void_type = void;
};
struct Y {
    using type_size = char;
};

/*******************************************************************************
* 根据返回类型
*******************************************************************************/
template <typename T>
typename T::type check_return_type(int) {
    return 0;
}
template <typename T>
char check_return_type(...) {
    return 0;
}
static_assert(sizeof(check_return_type<X>(0)) == 4);
static_assert(sizeof(check_return_type<Y>(1)) == 1);


/*******************************************************************************
* 根据函数参数
*******************************************************************************/
template <typename T>
int check_arg_type(typename T::type arg) {
    return 0;
}
template <typename T>
char check_arg_type(...) {
    return 0;
}
static_assert(sizeof(check_arg_type<X>(0)) == 4);
static_assert(sizeof(check_arg_type<Y>(0)) == 1);



/*******************************************************************************
* 默认模板参数SFINAE
*******************************************************************************/
struct true_type {
    enum { value = 1};
};
struct false_type {
    enum { value = 0};
};
template <typename T, typename U = typename T::type>
consteval int check_tmp_arg(int) {
    return 1;
}

template <typename T>
consteval int check_tmp_arg(double) {
    return 0;
}
static_assert(check_tmp_arg<X>(1) == true);
static_assert(check_tmp_arg<Y>(1) == false);


/*******************************************************************************
* 大小检查 SFINAE
*******************************************************************************/
template <typename T, typename U = typename T::type, bool = sizeof(U) == 4>
constexpr bool check_type_size(int) {
    return true;
}
template <typename T>
constexpr bool check_type_size(double) {
    return false;
}
static_assert(check_type_size<X>(1) == true);
static_assert(check_type_size<Y>(1) == false);

/*******************************************************************************
 * C++ 11 新增, 此处只说库和函数
*******************************************************************************/
// 类型特征
static_assert(std::is_same<int,int>() == true);
// ......
// enable_if<bool, T> 参数1为true时，有type T
template <typename T, typename SFINAE = std::enable_if<std::is_same_v<int, T>>::type>
void enable_if_func(T val) {  }

// decltype
template <typename T>
auto decltype_func(T val1, T val2) -> decltype(val1 + val2) { return val1 + val2;  }

// declval, 在不求值语境下 不构造对象但表达式使用该对象的成员
template <typename T, typename SFINAE = decltype(std::declval<T>() + std::declval<T>())>
void declval_func(T, T) {  }

/*******************************************************************************
* 类的部分特化 SFINAE C++14
*******************************************************************************/
// 此处的void是精心选择的，当特化版本出现<T, void> 时，优先级比默认的void高，因此才会使用特化版本
template <typename T, typename = void>
struct CheckVoidClass {
    enum { value = 0 };
};
template <typename T>
struct CheckVoidClass<T, typename T::void_type> {
    enum { value = 1};
};

static_assert(CheckVoidClass<X>::value == true);
static_assert(CheckVoidClass<Y>::value == false);


/*******************************************************************************
* C++ 17
*******************************************************************************/
// void_t
template <typename T, typename SFINAE = std::void_t<T::type>>
void void_t_func() {  }


int main() {



    return 0;
}