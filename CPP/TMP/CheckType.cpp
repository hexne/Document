/********************************************************************************
* @Author : hexne
* @Date   : 2025/05/11 19:44:51
********************************************************************************/
#include <type_traits>

template <typename T>
struct is_pointer {
    constexpr static bool value = false;
};
template <typename T>
struct is_pointer<T *> {
    constexpr static bool value = true;
};

static_assert(is_pointer<int>::value == false);
static_assert(is_pointer<int *>::value == true);
static_assert(is_pointer<int **>::value == true);
