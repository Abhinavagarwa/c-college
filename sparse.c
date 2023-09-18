#include<stdio.h>
int main()
{
    int n,m,i,j,c=0;
    printf("enter the no of rows and no of columns \n");
    scanf("%d \n%d",&n,&m); 
    int mat[n][m];
    printf("enter the elements of an array\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++){
           scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++){
            if(mat[i][j]!=0)
                c++;
        }
    }
    if(c<n*m){
        printf("sparse matrix");
    }
    else
        printf("not a sparse matrix");    
}