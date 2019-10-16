 #include<iostream>
using namespace std;
struct student
{
	unsigned int roll;
	char name[20];
	char addr[20];
}*ptr,*temp;

void getData(int n,struct student *ptr)
{
	int i;
	cout<<"\nEnter the records:\n";
	
		for(i=0;i<n;i++)
		{
			cin>>(ptr+i)->roll>>(ptr+i)->name>>(ptr+i)->addr;
		}	
}
void displayData(int n,struct student *ptr)
{
    int i;
    cout<<"\nRollNo\tName\tAddress\n";
    cout<<"--------------------------------------------------";
    for(i=0;i<n;i++)
	{
		cout<<"\n"<<(ptr+i)->roll<<"\t"<<(ptr+i)->name<<"\t"<<(ptr+i)->addr<<"\n";
	}
	cout<<"--------------------------------------------------\n";
}
void sortData(int n,struct student *ptr1)
{
	int i,j;
    cout<<"\n------------------Sorted Records-----------------\n";
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(((ptr1+j)->roll)>((ptr1+(j+1))->roll))
			{
				temp=(ptr1+j);
				(ptr1+j)=(ptr1+(j+1));
				(ptr1+(j+1))=temp;
			}
		}
	}
	displayData(n,ptr1);
}
void searchData(int n,struct student *ptr)
{
	int begin,end,mid,i,j,rno;
	cout<<"\nEnter the roll number to search the record: ";
	cin>>rno;
	begin=0;
	end=n-1;
	mid=(begin+end)/2;
	while(begin<=end)
    {
        if(((ptr+mid)->roll)<rno)
        {
            begin=mid+1;
        }
        else if((ptr+mid)->roll==rno)
        {
            cout<<"\n------------------Record found--------------------\n";
            cout<<"\nRollNo\tName\tAddress\n";
            cout<<"--------------------------------------------------";
            cout<<"\n"<<(ptr+mid)->roll<<"\t"<<(ptr+mid)->name<<"\t"<<(ptr+mid)->addr<<"\n";
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
	int n;
	int choice;
	cout<<"\nEnter the number of records:\t ";
	cin>>n;
	ptr=(struct student*)malloc(n*sizeof(struct student));
	getData(n,ptr);
	do
	{
	    cout<<"\nEnter Your choice:\t";
        cout<<"\n1-Sort Data\n2-Search Data\n3-Display Data\n";
        cin>>choice;
		switch(choice)
		{
			case 1: sortData(n,ptr);
			break;
			case 2: searchData(n,ptr);
			break;
			case 3: displayData(n,ptr);
			break;
			default: cout<<"Wrong Choice!!";
		}
		cout<<"\nPress 1 to continue..\t";
		cin>>choice;
	}while(choice==1);

	return 0;
}
