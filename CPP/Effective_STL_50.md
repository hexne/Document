## 涉及效率的建议  
#### 使用empty代替size() == 0  
例如list的stl库，自带的splice方法存在范围重载，也就是说使用splice的时候可能不会更新size成员，此时size方法的时间复杂度为O(n)  
  
#### 使用成员区间函数代替单元素兄弟  
单元素成员函数在多次插入或者删除时，可能存在多次对内存的分配和对元素的拷贝
成员区间函数调用方便且意图更加明显  

#### 使用reserver来避免不必要的重新分配  
reserver开辟不小于参数的大小，可以避免多次插入或者删除时多次对内存的操作和对元素的拷贝  

#### string实现的多样性  
由于string的实现不同.所以string在不同的平台上会有一些不同  
* sizeof(string)可能从1到至少7倍char *指针的大小  
* 不同实现对于最小化字符缓冲区的配置器有不同策略，也就是说新字符串的建立可能需要0、1、2次的内存分配
* string 对象可能共享或者不共享字符串的大小和容量信息（取决于是否有引用计数，这通常可以通过宏关闭）
* string 可能支持或不支持每对象配置器

#### 使用有序vector代替关联容器
当操作很少设计插入和删除，绝大多数在查找时，使用vector往往更好，一方面关联容器会造成更多的缺页，另一方面对关联容器的操作往往隐含着其他操作（例如平衡旋转等）

#### 对于关联容器考虑使用insert还是operator []
* 如果要更新的对象不在关联容器中，则应使用insert,因为operator 也会调用insert并再赋值
* 如果要更新的对象在关联容器中，则应使用operator [],因为insert涉及临时对象的创建和析构，而operator []只赋值

#### 熟悉非标准库的散列容器  
STL本身缺乏散列容器可以使用SGI或者STLport的散列容器实现  

#### 需要一个字符一个字符输入时，考虑使用istreambuf_iterator  
istream_iterator 默认使用>>进行输入，需要格式化，效率较低,可使用istreambuf_iterator代替，只获取下一个字符，无格式化检测等操作

#### 合理选择排序算法
* 常见的排序算法需要双向迭代器，因此不应对list容器使用（list容器内置sort方法）
* 对所有元素排序，使用sort、stable_sort
* 选出前n个元素（有序），使用partial_sort
* 选出前n个元素（无序），使用nth_element
* 将元素分隔为满足特定条件和不满足特定条件，使用partition、stable_partition(满足条件的会被移动到前面)
* 效率排序 partition stable_partition nth_element partial_sort sort stable_sort

#### 使用成员函数代替同名算法
* 成员函数更快
* 成员函数和算法有更高的适配性
* 关联容器的成员函数使用等价进行判断，非成员STL算法使用相等进行判断，成员函数使用了和容器一致的行为，但是非成员函数则不能提供这样一致的行为（例如对set、map的find,成员函数调用operator < ,非成员函数调用 operator == ）

#### 使用函数对象代替函数做算法的参数
* 函数指针会抑制内联优化，函数对象的调用则可能被内联
* 让程序更健壮(有时传递函数指针，编译时存在歧义)




## 其他建议  

#### 相等和等价的区别
* 相等基于operator ==,如果 x == y返回true，说明x和y有相等的值
* 等价基于operator < ，如果x < y 为假 && y < x 为假，则说明x和y有等价的值
