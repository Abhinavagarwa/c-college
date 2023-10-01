#include<stdio.h>
int linear(int arr[],int tar,int n);
int binary(int arr[],int tar,int n);
int main(){
    int n,tar,a,in=0;
    printf("Enter the limit\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the target\n");
    scanf("%d",&tar);
    printf("enter the the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);  
    }
    printf("enter \n 1.linear search. \n 2.binary search \n");
    scanf("%d",&a);
    switch(a){
        case 1:
            in=linear(arr,tar,n);
            break;
        case 2:
            in=binary(arr,tar,n);
            break;
        default:
            printf("-1 index wrong choice");
            break;

    }
    printf(" number found %d index\n",++in);
    return 0;
}
int linear(int arr[],int tar,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==tar){
            return i;
        }
    }
    return -1;
}
int binary(int arr[],int tar,int n)
{
    int s,e,mid;
    s=0;
    e=n-1;
    while(s<=e){
       mid=s+(e-s)/2;
       if(arr[mid]==tar){
         return mid;
       }
       else if(tar>mid){
        s=mid+1;
       }
       else
        e=mid-1;
    }
    return -1;
}
