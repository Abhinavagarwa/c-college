#include<iostream>
using namespace std;
int main(){
         int a,b,c;
         cout<<"enter the three numbers\n";
         cin>>a>>b>>c;
         if(a>=b&&a>=c)
            cout<<a<<" is the largest\n";
        else if(b>c)
            cout<<b<<" is the largest\n";
        else
            cout<<c<<" is the largest\n";
}