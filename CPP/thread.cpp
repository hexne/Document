#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

long long func(long long n) {
	
	if (n < 2)
		return n;
	return func(n - 1) + func(n - 2);
	
}

struct Func {
    int operator()() {
        int i = 10;
        while (i--)
            std::cout << i << ' ';
        std::cout << "\nFucn operator ()" << std::endl;
        return 0;
    }
};


int main() {

    // 默认构造函数没有关联线程，不会启动线程执行任务
    std::thread t;

	int n = 42;
	// 线程函数为func,参数为n,传值
	thread t1(func,n);
	// 同t1,但是参数传递为引用
	
	thread t2(func, ref(n));

	
	// t3 运行func,t2不再是线程
	thread t3(move(t2));

    std::thread t4(Func{});
	
	thread::id id1 = t1.get_id();
	thread::id id3 = t3.get_id();
	cout << "thread 1 id : " << id1 << endl;
	cout << "thread 3 id : " << id3 << endl;

	cout << "thread 1 handle: " << t1.native_handle() << endl;
	cout << "支持的并发线程数" << std::thread::hardware_concurrency() << endl;

	// t1.join();
	// Detach 线程。 将当前线程对象所代表的执行实例与该线程对象分离，使得线程的执行可以单独进行。一旦线程执行完毕，它所分配的资源将会被释放。
	t1.detach();
	// 检查当前的线程对象是否表示了一个活动的执行线程,是否可被join
	if (t2.joinable()) {
		t2.join();
	}
	// 立即放弃当前线程,系统调用另一线程继续执行
	this_thread::yield();
	t3.join();

	auto cur_time = chrono::system_clock::now();
	// using std::chrono::milliseconds;
	auto s = cur_time + 2s;
	// 线程休眠至某个指定的时刻(time point)，该线程才被重新唤醒。
	this_thread::sleep_until(s);

	// 线程休眠某个指定的时间片(time span)，该线程才被重新唤醒
	chrono::seconds sf(3);
	this_thread::sleep_for(sf);


	return 0;
}
