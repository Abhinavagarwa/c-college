#include<iostream>
using namespace std;
void swap(int a,int b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"the swapped nos are "<<a<<" "<<b;  
}
int main(){
    int a,b;
    cout<<"enter the two nos\n";
    cin>>a>>b;
    swap(a,b);
    return 0;
}