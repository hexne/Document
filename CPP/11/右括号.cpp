#include <vector>

template <typename T>
struct Struct {
    T value;

};

template <typename T>
struct Func {

    // void func(std::vector<Struct<T>>= {}); 仍旧error
    void func(std::vector<Struct<T> > = {});

};


template<typename T>
void Func<T>::func(std::vector<Struct<T>> objs) {
    objs.push_back({});
    objs.front().value = 10;
}


int main() {

    std::vector<Struct<int> > vec1; // c++11 之前这么写
    std::vector<Struct<int>> vec2; // c++11 之前, >> 作为右移符号，产生error


    Func<int> func;
    std::vector<Struct<int>> vecs;
    func.func(vecs);


}



