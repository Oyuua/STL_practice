#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> arr1(4,1);//构造一维动态数组，存放4个整数1
  vector<vector<int>> arr2(2,vrctor<int>(3,1));//构造二维动态数组，存放2行3列整数1 
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
