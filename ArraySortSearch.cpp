#include<iostream>
using namespace std;

int arr[100];
void getData(int n)
{
	int i;
	cout<<"\nEnter the Elements in Array: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void displayData(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void linerSearch(int n)
{
	int item,i,flag=0;
	cout<<"\nEnter the Element to be Searched\n";
	cin>>item;
	for(i=0;i<n;i++)
	{
		if(arr[i]==item)
		{
			cout<<"\nElement found at location "<<i+1<<"\n";
			flag=0;
			break;
		}
		else
		{
			flag=1;
		}
	}
	if(flag==1)
	{
		cout<<"\nElement not found\n";
	}
}
void insertionSort(int n)
{
	int i,j,value;

	for(i=1;i<n;i++)
	{
		value=arr[i];
		j=i-1;
		while(j>=0 && arr[j]<value)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=value;
	}
	cout<<"\n------------Sorted Elements Descending------------\n";
	displayData(n);
}
void selectionSort(int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=arr[j];
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	cout<<"\n------------Sorted Elements Ascending------------\n";
	displayData(n);
}

int main()
{
	int n,i,choice;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	getData(n);
	do
	{
		cout<<"\nEnter Your Choice: ";
		cout<<"\n1-Sort Elements in Ascending order\n2-Sort Elements in Descending Order\n";
		cout<<"3-Search Element\n4-Display Elements\n";
		cin>>choice;
		switch(choice)
		{
			case 1:	selectionSort(n);
			break;
			case 2: insertionSort(n);
			break;
			case 3: linerSearch(n);
			break;
			case 4: displayData(n);
			break;
			default: cout<<"\nWrong Choice\n";
		}
		cout<<"\nPress 1 to Continue... ";
		cin>>choice;
	}while(choice==1);
	return 0;
}
