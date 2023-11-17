#include<iostream>
void swap(int a,int b)
{
	int c;
	c=a;
	a=b;
	b=c;
	cout<<”swapped=”<<a<<”  “<<b<<endl;
}
void swapwithout(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	cout<<”swapped without using third variable=”<<a<<”  “<<b<<"\n";
}
int main()
{
    int ch,a,b;
    cout<<”enter the choice\n”;
    cin>>ch;
    cout<<”enter the numbers\n”;
    cin>>a>>b;
    if(ch==1)
	    swap(a,b);
    if(ch==2)
	    swapwithout(a,b);
}

