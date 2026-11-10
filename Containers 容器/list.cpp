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
  lst.reverse();//倒置
  lst.unique();//去重（要先排序）
  
  lst1.merge(lst2);//将lst2合并到lst1，并清空lst2
  //合并前一定要先保证有序，并且顺序一致（统一升序or降序）

  lst1.splice(pos,lst2);//将lst2所有数据迁移到lst1指定位置
  auto it=lst1.begin();
  auto it2=lst2.begin();
  lst1.splice(it,lst2,it2);//将it2位置的lst2元素迁移到lst1的it
  auto it_end=next(it2,3);
  lst1.splice(it,lst2,it2,it_end);//将lst2的it2~it_end这一段数据迁移到lst1的it，不包括it_end
  //也可以对lst1自身进行迁移，但需要迁移的数据段不能包含迁移终点pos
  lst1.splice(pos,lst1,pos1,pos2)//即pos1~pos2不能包含pos

  

  
  
  

return 0;
}

//应用一
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

//应用二
int main(){
    list<int> A{1,2,3,4,5};
    list<int> B{2,3,4,6,7,8,10};
    //方法一
    list<int> C;
for(int e:B){
    if(e%2==0) C.push_back(e);
}
auto it1=A.begin();
A.splice(it1,C);

//方法二
auto it=B.begin();
while(it!=B.end()){
    if(*it%2==0){
        auto p=it;//一定要保存移动前的位置，否则it++在A中移动
        it++;
        A.splice(A.begin(),B,it);
    }
    else it++;
}

//打印A
for(int x:A){
    cout<<x<<endl;
}
return 0;
}

//应用三
 #include <bits/stdc++.h>

 using namespace std;


const int MAXN =100005;
list<int>::iterator it[MAXN];//存储地址
bool de[MAXN];//判断是否删除
int main(){
 int N;
 cin>>N;
 list<int> lst1{1};
 it[1]=lst1.begin();
 for(int i=2;i<=N;i++){
     int k,p;
     cin>>k>>p;

     if(p==0){
         it[i]=lst1.insert(it[k],i);
     }
     else{
        auto pos=next(it[k]);
        it[i]=lst1.insert(pos,i);
     }
    
 }
 //处理删除
int M;
cin>>M;
for(int i=0;i<M;i++){
    int x;
    cin>>x;
    if(!de[x]){
        lst1.remove(x);
        de[x]=true;
    }
    
}
for(int e:lst1){
    cout<<e<<" ";
}


 return 0;

 }



  
