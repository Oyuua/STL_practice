#include <iostream>
#include <stack>

using namespace std;

int main(){
//创建栈
  stack<int> st;
//进栈
for(int i=1;i<=10;i++) st.push(i); 
while(st.size()){
  cout << st.top() << endl;
  st.pop();
}
return 0;
}
