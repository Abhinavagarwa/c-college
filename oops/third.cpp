#include<iostream>
using namespace std;
void swap(int a,int b){
  int temp;
  temp=a;
  a=b;
  b=temp;
  cout<<"the swap nos with the help of third variable are "<<a<<" "<<b<<"\n";
}
void tswap(int a,int b){
  a=a+b;
  b=a-b;
  a=a-b;
  cout<<"the swap nos without the help of third variable are "<<a<<" "<<b<<"\n";
}
int main(){
    int a,b,ch;
    cout<<"enter the choice\n";
    cin>>ch;
    cout<<"enter the two\n";
    cin>>a>>b;
    if(ch==1)
         swap(a,b);
    else if(ch==2)
         tswap(a,b);
    else
         cout<<"wrong choice\n";    
}