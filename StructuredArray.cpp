#include<iostream>
using namespace std;
struct student
{
	int roll;
	char name[20];
	char addr[20];
}s[100],temp;

void getData(int n)
{
	int i;
	cout<<"\nEnter the records:\n";
	for(i=0;i<n;i++)
	{
		cin>>s[i].roll>>s[i].name>>s[i].addr;
	}
}
void displayData(int n)
{
    int i;
    cout<<"\nRollNo\tName\tAddress\n";
    cout<<"--------------------------------------------------";
    for(i=0;i<n;i++)
	{
		cout<<"\n"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].addr<<"\n";
	}
	cout<<"--------------------------------------------------";
}
void sortData(int n)
{
	int i,j;
    cout<<"\n------------------Sorted Records-----------------\n";
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j].roll>s[j+1].roll)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	displayData(n);
}
void searchData(int n)
{
	int begin,end,mid,i,j,rno;
	cout<<"\nEnter the roll number to search the record: ";
	cin>>rno;
	begin=0;
	end=n-1;
	mid=(begin+end)/2;
	while(begin<=end)
    {
        if(s[mid].roll<rno)
        {
            begin=mid+1;
        }
        else if(s[mid].roll==rno)
        {
            cout<<"\n------------------Record found--------------------\n";
            cout<<"\nRollNo\tName\tAddress\n";
            cout<<"--------------------------------------------------";
            cout<<"\n"<<s[mid].roll<<"\t"<<s[mid].name<<"\t"<<s[mid].addr<<"\n";
            cout<<"--------------------------------------------------";
            break;
        }
        else
        {
            end=mid-1;
        }
        mid=(begin+end)/2;
    }
    if(begin>end)
    {
        cout<<"Record not found";
    }
}
int main()
{
	int n,choice;
	cout<<"\nEnter the number of records:\t ";
	cin>>n;
	getData(n);
	do
	{
	    cout<<"\nEnter Your choice:\t";
        cout<<"\n1-Sort Data\n2-Search Data\n3-Display Data\n";
        cin>>choice;
		switch(choice)
		{
			case 1: sortData(n);
			break;
			case 2: searchData(n);
			break;
			case 3: displayData(n);
			break;
			default: cout<<"Wrong Choice!!";
		}
		cout<<"\nPress 1 to continue..\t";
		cin>>choice;
	}while(choice==1);

	return 0;
}
