#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number\n";
    cin>>n;
    int no=0,sum=0,temp=0,digit=0,power=0;
    no=n;
    while(no>0){
        ++digit;
        no=no/10;
    }
    no=n;
    while(no>0){
        temp=no%10;
        no=no/10;
        power=round(pow(temp,digit));
        sum=sum+power;
    }
    if(sum==n)
      cout<<n<<" number is armstrong\n";
    else
        cout<<n<<" number is not armstrong\n";
}