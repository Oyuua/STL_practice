#include <bits/stdc++.h>
//#include <list>

using namespace std;

void printlist(list<int> &l){
  cout << "Address:" << &l <<endl;
  cout << "Size:\t" <<l.size() <<endl;
  cout << "Elements:(address|value)" <<endl;
  int idex = 1;
  for(auto it = l.begin(); it != l.end(); it++)
    cout<<"["<<index++<<"]"<<&(*it)<<","<<*it<<endsl;
}

int main(){
//创建、初始化
  list<int> lst(7,15);
  //list<int> lst{12,34,56,78,100};
  vector<int> v{1,2,3,4,5,6};
  list<int> lst2(v.begin(),v.end());
  printlist(lst);

  //移动迭代器
  auto it=lst.begin();
  for(int i=0;i<3;i++)
    it++;
  advance(it,3);//it自身向后移动3位，it改变
  advance(it,-2);//向前移动2位
  //next、prev返回值为新迭代器，不改变原迭代器
  auto it2 = std::next(it, 3);  // it2 指向 4，it 仍指向 1
  auto it3 = std::next(it);     // 默认走 1 步，指向 2
  auto it = lst.end();
  auto last = std::prev(it);      // 指向最后一个元素 5
  auto p = std::prev(it, 2);      // 指向 4

  //常用接口

  //在头尾插入元素
  lst.push_back(27);
  lst.push_front(11);
  
  //只获取第一和最后的元素
  lst.front();
  lst.back();

  //在指定位置插入元素,不指定位置则在正中间插入
  lst.insert();
  lst.insert(it,3,33);
  
  //lst.erase(位置);//删除指定位置元素
  //lst.remove(item);//删除列表中值为item的元素
  cout<<*it<<endl;

  //条件删除
  lst.remove_if([](int x){return x<6;});//删除小于6的元素，日常使用只需要改return后的条件，其他照抄

  lst.sort();//sort(lst)---错误
  lst.reverse()//倒置
  lst.unique()//去重（要先排序）
  
  
  

return 0;
}

//应用
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    list<int> lst;
    for(int i=1;i<=n;i++){
        lst.push_back(i);
    }
    auto it=lst.begin();
    while(!lst.empty()){
        for(int i=0;i<m-1;i++){
            it++;
        if(it==lst.end()){
            it=lst.begin();
        }
        cout<<*it<<","<<endl;
        it=lst.erase(it);//erase删除后会自动返回下一个位置；
        if(it==lst.end()){
            it=lst.begin();
        }
    }

}
  
