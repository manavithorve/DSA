#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=NULL,*temp,*ptr,*new_node;

void createList()
{
	int ch=0;
	do
	{
		new_node=new node();
		cout<<"\nEnter Data: ";
		cin>>new_node->data;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new_node;
		}
		cout<<"Press 1 to Continue Creating ";
		cin>>ch;
	}while(ch==1);
}

void displayList()
{
	cout<<"\n------------------------------List------------------------------\n";
	temp=head;
	if(head==NULL)
	{
		cout<<"\nList Empty!";
	}
	while(temp!=NULL)
	{
		cout<<"\n|Data: "<<temp->data<<"| Address: "<<temp->next<<"|\n";
		temp=temp->next;
	}
}

void insertBegin()
{
	new_node=new node;
	cout<<"\nEnter data: ";
	cin>>new_node->data;
	new_node->next=head;
	head=new_node;
	cout<<"Insert Successful";
	displayList();
}

void insertLast()
{
	new_node=new node;
	cout<<"\nEnter data: ";
	cin>>new_node->data;
	new_node->next=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	cout<<"Insert Successful";
	displayList();
}

void insertPosition()
{
	int position,i=0;
	new_node=new node;
	cout<<"\nEnter data: ";
	cin>>new_node->data;
	new_node->next=NULL;
	cout<<"\nEnter the position where you want to insert: ";
	cin>>position;
	temp=head;
	while(i<position)
	{
		temp=temp->next;
		i++;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	cout<<"Insert Successful";
	displayList();
}
void deleteBegin()
{
	if(head==NULL)
	{
		cout<<"\nNo data to delete!";
	}
	else
	{
		temp=head;
		head=head->next;
		temp->next=NULL;
		delete(temp);
		cout<<"Delete Successful";
		displayList();
	}
}

void deleteLast()
{
	if(head==NULL)
	{
		cout<<"\nNo data to delete!";
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		delete(temp);
		cout<<"Delete Successful";
		displayList();
	}
}

void deletePosition()
{
	int position,i=1;
	if(head==NULL)
	{
		cout<<"\nNo data to delete!";
	}
	else
	{
		cout<<"\nEnter the position at which you want to delete: ";
		cin>>position;
		temp=head;
		while(i<position)
		{
			ptr=temp;
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;
		temp->next=NULL;
		delete(temp);
		cout<<"Delete Successful";
		displayList();
	}
}


void insertOperations()
{
	int ch;
	do
	{
		cout<<"Enter your choice";
		cout<<"\n1-Insert Begin\n2-Insert Last\n3-Insert at position\n0-Quit";
		cin>>ch;
		switch(ch)
		{
			case 1: insertBegin();
			break;
			case 2: insertLast();
			break;
			case 3: insertPosition();
			break;
			case 0:
			break;
			default: cout<<"\nWrong choice!!";
		}
		cout<<"\nPress 1 to continue insert: ";
		cin>>ch;
	}while(ch==1);
}

void deleteOperations()
{
	int ch;
	do
	{
		cout<<"Enter your choice";
		cout<<"\n1-Delete Begin\n2-Delete Last\n3-Delete at position\n0-Quit";
		cin>>ch;
		switch(ch)
		{
			case 1: deleteBegin();
			break;
			case 2: deleteLast();
			break;
			case 3: deletePosition();
			break;
			case 0:
			break;
			default: cout<<"\nWrong choice!!";
		}
		cout<<"\nPress 1 to continue delete: ";
		cin>>ch;
	}while(ch==1);
}

void searchData(int searchItem)
{
    int counter=0;
    bool flag=false;
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==searchItem)
        {
            cout<<"\nSearch Item fount at location: "<<counter+1;
            cout<<"\n|Data: "<<temp->data<<"| Address: "<<temp->next<<"|\n";
            flag=true;
            break;
        }
        counter++;
        temp=temp->next;
    }
    if(flag==false)
    {
        cout<<"\nSearch Item is not present in the list!";
    }
}

void updateData(int new_data,int pos)
{
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    cout<<"Replacing "<<temp->data<<" with new data...";
    temp->data=new_data;
    cout<<"\nUpdate Successful!";
    cout<<"\n|Data: "<<temp->data<<"| Address: "<<temp->next<<"|\n";
}

void reverseList()
{
    struct node* prev;
    if(head!=NULL)
    {
        prev=head;
        temp=head->next;
        head=head->next;
        prev->next=NULL;
    }
    while(head!=NULL)
    {
        head=head->next;
        temp->next=prev;
        prev=temp;
        temp=head;
    }
    head=prev;
    cout<<"\nList Reversed!";
    displayList();
}
int main()
{
	int choice=0,element,position;
	do
	{
		cout<<"\nEnter your choice:";
		cout<<"\n1-Display List\n2-Create List\n3-Insert\n4-Delete\n5-Search\n6-Update\n7-Reverse\n0-Exit:  ";
  		cin>>choice;
  		switch(choice)
  		{
 			case 1: displayList();
 			break;
 			case 2: createList();
 			break;
 			case 3: insertOperations();
 			break;
 			case 4: deleteOperations();
 			break;
 			case 5: cout<<"\nEnter the item to be searched: ";
                    cin>>element;
                    searchData(element);
 			break;
 			case 6: cout<<"\nEnter new data: ";
                    cin>>element;
                    cout<<"\nEnter the position at which you want to update the data: ";
                    cin>>position;
                    updateData(element,position);
 			break;
 			case 7: reverseList();
 			break;
 			case 0: cout<<"\nThank you!!";
 			break;
 			default: cout<<"\nWrong choice!!";
  		}
  		cout<<"\nPress 1 to continue: ";
  		cin>>choice;

	}while(choice==1);

	return 0;
}
