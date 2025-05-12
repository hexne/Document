
template <int num1, int num2, bool = true>
struct find_max_number_impl {
    constexpr static int max_value = num1;
};
template <int num1, int num2>
struct find_max_number_impl<num1, num2, num1 <= num2> {
    constexpr static int max_value = num2;
};

template <int ... Numbers>
struct find_max_number;

template <int num1, int num2, int ... Other>
struct find_max_number<num1, num2, Other...> {
    constexpr static int max_value
        = find_max_number<find_max_number_impl<num1, num2>::max_value, Other...>::max_value;
};
template <int num1, int num2>
struct find_max_number<num1, num2> {
    constexpr static int max_value = find_max_number_impl<num1, num2>::max_value;
};

template <int number>
struct find_max_number<number> {
    constexpr static int max_value = number;
};


int main() {

    static_assert(find_max_number<1,3,9>::max_value == 9);


}


