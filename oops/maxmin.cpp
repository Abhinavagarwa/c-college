#include<iostream>
using namespace std;
inline int max(int a,int b) {return (a>b)?a:b;}
inline int min(int a,int b) {return (a<b)?a:b;}
int main()
{
    int ma,mi,a,b;
    cout<<"enter the nos\n";
    cin>>a>>b;
    ma=max(a,b);
    mi=min(a,b);
    cout<<"max is="<<ma<<"\n";
    cout<<"min is="<<mi<<"\n";
}