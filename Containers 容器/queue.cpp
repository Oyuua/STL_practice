### 10.1 队列 queue
支持先进先出的线性数据结构。没有迭代器。内部是 $deque$。
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>q;
    q.push(10);q.push(20);q.push(30);q.push(40);
    q.front();//10,队头
    q.pop();//删除队头元素{20,30,40}
}


### 10.3 双端队列 deque
$stack$ 和 $queue$ 的底层容器，支持两头的插入删除。内部是指针数组。
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    dq.push_back(30);//{30}
    dq.push_back(40);//{30,40}
    dq.push_front(20);//{20,30,40}
    dq.push_front(10);//{10,20,30,40}
    dq.front();//10,队头
    dq.back();//40,队尾
    dq.pop_front();//删除队头元素{20,30,40}
    dq.pop_back();//删除队尾元素{20,30}
}
```
附加操作均为 $O(n)$。
```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    dq.push_back(30);//{30}
    dq.push_back(40);//{30,40}
    dq.push_front(20);//{20,30,40}
    dq.push_front(15);//{15,20,30,40}
    dq[0]=10;//下标0位置改为10,{10,20,30,40}
    dq.insert(dq.begin()+2,25);//在下标2位置插入25,{10,20,25,30,40}
    dq.erase(dq.begin()+2);//删除下标2位置元素25,{10,20,30,40}
    for(auto& i:dq){}//迭代器 i=[10,20,30,40]
}
```
