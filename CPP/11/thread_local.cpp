#include <iostream>
#include <thread>

struct Stu {
    Stu() {
        std::cout << "stu" << std::endl;
    }
    ~Stu() {
        std::cout << "~stu" << std::endl;
    }

};

int main() {

    bool flag{};

    std::thread thread([&flag]{
            thread_local Stu stu;
            std::cout << "while" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds{2});
            std::cout << "thread end" << std::endl;
        });


    thread.join();

    std::cout << "main end" << std::endl;



    return 0;
}

