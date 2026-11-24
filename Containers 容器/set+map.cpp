#include <bits/stdc++.h>
using namespace std;
//#set
//与 map 类似，支持储存有序的，不可重复的数据。内部也是红黑树(靠红黑树维持有序)
//set不能改数据，数据都是只读，只能先删再插入
//新增数据不能指定位置
//数据不重复，会自动去重

//初始化
int main()
{
set<int> st{1,2,3};//直接初始化

vector<int> v{1,2,3,3,4,5};
set<int> st2(v.begin(),v.end());

st.insert(6);
//st.erase();//可以通过地址删除或元素删除
auto p=st.find(1);//返回迭代器
//st.clear();
//st.count();//出现的次数，只能为0或1

st.lower_bound(15);//返回第一个不小于15的迭代器
st.upper_bound(15);//返回第一个大于15的迭代器


multiset<int> st3;
//multiset:数据可重复，erase(3)会删除所有3，其他与set一样
//若想只删除一个：
  st3.erase(st.find(3));

//#map key->value
map<int,int> mp1{{1.1},{2.4},{5,25}};
mp1.insert({6,36});
mp1.insert({2,3});//无效,2->4
//insert不能改变原有数据
//但可以直接改值:
mp1[2]=15;
//查找
auto it =mp1.find(9);
if(it!=mp1.end()){
    cout<<"Yes"<<endl;
}
else{
    cout<<"NO"<<endl;
}
//错误方式：


//打印


  return 0;
}

//应用#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long C;
    if(!(cin >> N >> C)) return 0;
    map<long long,long long> cnt;//存储每个元素出现的次数，可重复，初始值为0
    for(int i = 0; i < N; i++){
        long long a; cin >> a;
        cnt[a]++;//自动创建{a，0}
    }
    long long ans = 0;
    for(auto &p : cnt){
        long long A = p.first;
        auto it = cnt.find(A - C);
        if(it != cnt.end()) ans += p.second * it->second;
    }
    cout << ans << '\n';
    return 0;
}


