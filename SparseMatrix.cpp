using namespace std;
#include<iostream>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int m[10][10],spm[10][10];
    int i,j;
    int r,c,nonZero=0,k=1;
    cout<<"\nEnter the number of rows in the matrix: ";
    cin>>r;
    cout<<"\nEnter the number of Columns in the matrix: ";
    cin>>c;
    cout<<"Enter the Elements in the matrix: ";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>m[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                nonZero++;
            }
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                spm[k][0]=i;
                spm[k][1]=j;
                spm[k][2]=m[i][j];
                k++;
            }
        }
    }
    spm[0][0]=k;
    spm[0][1]=3;
    spm[0][2]=nonZero;

    for(i=0;i<=nonZero;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<spm[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
