#include <iostream>
#include <future>
#include <atomic>

int main () {

    int flag{};
    // 对于普通变量来说，flag += 1分为以下三个步骤
    // movl flag, %eax
    // incl %eax
    // movl %eax, flag
    flag += 1;

    // 对于atomic类型来说，这些操作是原子的，不可分割的
    std::atomic<int> flag_atomic{};
    flag_atomic += 1;

    // 检查原子对象是否免锁
    flag_atomic.is_lock_free();

    // 使用参数1 原子地替换当前值，并按照参数2指定内存序, 默认为 memory_order_seq_cst
    flag_atomic.store(10,std::memory_order_seq_cst);
    
    // 原子地加载并返回当前原子变量的当前值，按照参数指定内存序，默认为 memory_order_seq_cst 
    flag_atomic.load(std::memory_order_seq_cst);








    return 0;
}
