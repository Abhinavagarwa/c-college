#include<iostream>
using namespace std;
void swap(int a,int b){
  int temp;
  temp=a;
  a=b;
  b=temp;
  cout<<"the swap nos are "<<a<<" "<<b;
}
int main(){
    int a,b;
    cout<<"enter the two\n";
    cin>>a>>b;
    swap(a,b);
}