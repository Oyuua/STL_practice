#include <iostream>
#include <vector>
using namespace std;

void printv(const vector<int> &v){
  cout<< "address:\t" << &v <<endl;
  cout<< "data:\t" << v.data() <<endl;
  cout<< "size:\t" << v.size() <<endl;
  cout<< "capacity:\t" << v.capacity() <<endl;
  cout<< "Elements:(address,value)\t" <<endl;
  for(int i=0;i<v.size();i++){
    cout<< "add:"<<&v[i]<<","<<v[i]<<endl;
  }
  
}
int main(){
  vector<int> arr1(4,1);//构造一维动态数组，存放4个整数1
  vector<vector<int>> arr2(2,vrctor<int>(3,1));//构造二维动态数组，存放2行3列整数1 

  //数组对向量v初始化
  int a[]={11,22,33,44,55,66,77}；
  vector<int> v1(a,a+7)；
  //向量对向量初始化
  vector<int> v2(v1.data,v1.data+7);
  printv(v2);//打印

  vector<int> v3(1,10);
  v3.push_back(20);//先生成再封装
  v3.push_back(30);
  v3.push_back(40);
  v3.emplace_back(50);//直接在后面加地址,更快

  cout<<v3[-1];//可以访问整个vector，包括size、data等
  cout<<v3.at(0);//.at()只能访问data的元素
  //resize
  v3.resize(3);//只保留v3前三个元素,v3={10,20,30,40,50}
  v3.resize(5);//重新加载，v3={10,20,30}

  v3.reserve(100);//预先预留100个内存空间，只改变capacity，不改变size，且只能扩容，不能缩容
  
}

//一个例题（判断素数）
/*
#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;

    if(n<2){
        cout<<0<<endl;
        return 0;//直接结束
    }

    vector<bool> is_Prime(n+1,true);
    is_Prime[0] = is_Prime[1] = false;

    for(int i = 2; (long long)i * i <= n; i++) {
        if(is_Prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_Prime[j] = false;
            }
        }
    }

for(int i=0;i<is_Prime.size();i++){
    if(is_Prime[i]) count++;
}
    
    cout << count << endl;
    return 0;
}
*/
