using namespace std;
#include<iostream>
using namespace std;

int m[10][10],spm[10][10];
int i,j;
int r,c,nonZero=0,k=1,choice=0;

void sparseMatrix(bool display)
{
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
    spm[0][0]=r;
    spm[0][1]=c;
    spm[0][2]=nonZero;

	if(display)
	{
		cout<<"\n*****************Sparsed Matrix*******************\n";	
    	for(i=0;i<=nonZero;i++)
    	{
        	for(j=0;j<3;j++)
        	{
        	    cout<<spm[i][j]<<"\t";
       		}
        	cout<<"\n";
    	}
	}
}

void simpleTranspose()
{
	int t=1,simple[10][10];

	for(j=0;j<c;j++)
	{
		for(i=1;i<=nonZero;i++)
		{
			if(spm[i][1]==j)
			{
				simple[t][1]=spm[i][0];
				simple[t][0]=spm[i][1];
				simple[t][2]=spm[i][2];
				t++;
			}
		}
	}	
	simple[0][0]=spm[0][1];
	simple[0][1]=spm[0][0];
	simple[0][2]=spm[0][2];	

	cout<<"\n*******************Simple Transpose******************"<<nonZero<<"\n";	
	for(i=0;i<=nonZero;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<simple[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void fastTranspose()
{
	int i,j;
	int freq[nonZero],pos[nonZero],fast[10][10];
	for(i=0;i<=nonZero;i++)
	{
		freq[i]=0;
	}
	for(i=1;i<=nonZero;i++)
	{
		freq[spm[i][1]]++;
	}
	pos[0]=1;
	for(i=1;i<=nonZero;i++)
	{
		pos[i]=(pos[i-1])+(freq[i-1]);
	}
	for(i=0;i<=nonZero;i++)
	{
		j=pos[spm[i][1]];
		fast[j][0]=spm[i][1];
		fast[j][1]=spm[i][0];
		fast[j][2]=spm[i][2];
		pos[spm[i][1]]++;
	}
	fast[0][0]=spm[0][1];
	fast[0][1]=spm[0][0];
	fast[0][2]=spm[0][2];
	
	cout<<"\n*******************Fast Transpose******************\n";	
	for(i=0;i<=nonZero;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<fast[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int main()
{
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
			if(m[i][j]!=0)
            {
                nonZero++;
            }
        }
    }
	do
	{
		cout<<"\nEnter your choice";
		cout<<"\n1-Sparse Matrix\n2-Simple Transpose\n3-Fast Transpose:  ";		
		cin>>choice;
		switch(choice)
		{
			case 1: sparseMatrix(true);
			break;
			case 2: sparseMatrix(false);
					simpleTranspose();
			break;
			case 3: fastTranspose();
			break;
			default: cout<<"\nWrong choice!!";			
		}
		cout<<"\nPress 1 to continue: ";
		cin>>choice;
	}while(choice==1);
    return 0;
}
