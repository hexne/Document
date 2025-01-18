#include <iostream>
#include <atomic>


/*******************************************************************************
不同的内存序模式
    memory_order_relaxed
        对于非依赖关系，任意顺序
        对于依赖关系，按照代码顺序

x    memory_order_acquire
        load之后的所有(包含非依赖关系)读写操作，不允许被移动到load前面
        store之前的所有(包含非依赖关系)读写操作，不允许移动到store后面
        如果 store(release)在load(acquire)之前执行了，
            那么store(release)之前的写操作对load(acquire)之后的读写操作可见

x    memory_order_release
        store之前的所有(包含非依赖关系)读写操作，不允许移动到store后面
        load之后的所有(包含非依赖关系)读写操作，不允许被移动到load前面

    memory_order_consume
        基本等同于memory_order_relaxed
        但 线程1 中的依赖关系在 线程2 中依旧可见

    memory_order_acq_rel
        对读写施加release语义
        可见其他线程施加release之前的所有写入，
            同时自己之前所有写入对其他施加acquire语义的线程可见

    memory_order_seq_cst(atomic默认使用该模式)
        除了包含release/acquire的限制，同时还建立了一个对所有原子操作的全局唯一修改顺序
        单线程中按照代码执行，多线程中按照全局统一顺序执行
*******************************************************************************/
int main() {
    int tmp {};
    std::atomic<int> relaxed_ordering {};

    tmp = relaxed_ordering.load(std::memory_order_relaxed);
    relaxed_ordering.store(tmp, std::memory_order_relaxed);

    return 0;
}

