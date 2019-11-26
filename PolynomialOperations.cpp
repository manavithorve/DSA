#include<iostream>
using namespace std;
/* Declarations for a polynomial node */

struct pnode
{
	int Exp;
	int Coef;
	struct pnode *next;
};


/*
————————————————————
The show function
Input : head node of the polynomial
Output: none
Calls :none.

————————————————————
*/
void show(struct pnode *head)
{
	struct pnode *Curr ;

	Curr=head;
	if ( Curr == NULL )
	{
		cout<<"The polynomial is empty\n";
		return ;
	}
	do
	{
		if ( Curr ->Exp != 0 )
		{
			cout<<Curr->Coef<<" "<<Curr->Exp;
		}
		else
		{
			cout<<Curr->Coef;
			Curr = Curr -> next;
			if ( Curr != head )
			{
				if ( Curr->Coef > 0)
				{
					cout<<" + ";
				}
			}
		}
	}while( Curr != head );
	cout<<endl;
}


/*
————————————————————
The get function
Input :none
Output: The starting node of the polynomial
Calls :none.

———————————————————–
*/
pnode *get()
{
/* Local declarations here */
	struct pnode *temp, *New, *last;
	int Exp, flag, Coef;

	temp = NULL ;
	flag = 1;
 /* flag to indicate whether a new node
is created for the first time or not */

	cout<<"\nEnter the polynomial in descending order of exponent: ";
	cout<<"\nEnter -99 for exponent to terminate entry\n\n";
	do
	{
		cout<<"\nEnter the Coefficient and Exponent of a term :";
		cin>>Coef>>Exp;
		if ( Exp == -99 ) 
		{
			break;
		}

		/* allocate new node */
		New = new pnode;
		New -> Coef = Coef; /* Set coef, exp & next field */
		New -> Exp = Exp ;
		New -> next = temp;
		if (flag==1) /* Executed only for the first time */
		{
			temp = New;
			last = temp;
			flag = 0;
		}
		else
		{ 
			/* last keeps track of the most recently created node */
			last ->next = New;
			last = New;
		}
	}while(1);

return temp;
}

/*
————————————————————
The Attach function
Input : multiplied coefficient value,
addition of the exponts of the two polynomials,
and a third node
Output: returns the head node of attached node.
Calls :none.
Called by:mul function
————————————————————
*/

pnode * Attach( int Exp, int Coef, struct pnode * third)
{
	pnode *New;
	New = new pnode;
	New->Exp = Exp;
	New->Coef = Coef;
	New->next = third;
	third->next = New;
	third = New;
	return(third);
}

/*
————————————————————
The mul function
Input : head nodes of the first and second polynomials
Output: returns the head node of the
resultant polynomial
Calls :Attach – to connect the to nodes.
Called by:main
————————————————————
*/
pnode* mul(struct pnode* First, struct pnode* Second)
{
	struct pnode *p1, *p2, *third, *dummy, *temp ;
	int Exp, flag;
	int Coef;
	pnode *Attach(int,int,struct pnode*);
	p1 = First;
	third = new pnode;
	third-> next =third;
	dummy = third;
	temp = dummy->next;
	temp->next=temp;	
	do
	{
		p2 = Second;	
		do
		{
			Coef = p1->Coef * p2->Coef;
			Exp = p1->Exp + p2 ->Exp;
			temp = dummy->next;
			flag = 0;
			do
			{
				if ( temp -> Exp == Exp )
				{
					flag = 1;
				}
				else
				{
					temp = temp -> next;
				}
			}while ( temp!= dummy->next && !flag );
			
			if ( flag==1)
			{
				temp->Coef = temp ->Coef + Coef;
			}			
			else
			{
				third = Attach(Exp, Coef, third);
				third->next=dummy->next;
			}
			p2 = p2 -> next;
		}while ( p2 != Second);

		p1 = p1 -> next;
	}while ( p1 != First);

	third ->next = dummy -> next;
	third = dummy -> next;
	delete(dummy);
	return(third);
}
/*
————————————————————
The add function
Input : head nodes of the first and second polynomials
Output: returns the head node of the
resultant polynomial
Calls :Attach – to connect the to nodes.
Called by:main
————————————————————
*/
pnode* add(struct pnode* First, struct pnode* Second)
{
	struct pnode *p1, *p2, *third, *dummy ;
	int Coef;
	struct pnode *Attach(int,int,struct pnode *);
	p1 = First;
	p2 = Second;
	third = new pnode;
	third-> next =third;
	dummy = third;
	do
	{
		if( p1->Exp==p2->Exp)
		{
			Coef = p1->Coef + p2->Coef;
			third = Attach(p1->Exp,Coef,third);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if( p1->Exp < p2->Exp)
		{
			third =Attach(p2->Exp, p2->Coef, third);
			p2 = p2 -> next ;
		}
		else if( p1->Exp > p2->Exp)
		{
			third =Attach(p1->Exp, p1->Coef,third);
			p1 = p1 -> next ;
		}

	}while ( p1 != First || p2 != Second );
	while ( p1 != First )
	{
		third = Attach(p1->Exp, p1->Coef, third);
		p1 = p1 -> next;
	}
	while ( p2 != Second )	
	{
		third = Attach(p2->Exp, p2->Coef,third);
		p2 = p2 -> next;
	}
	third ->next = dummy -> next;
	third = dummy -> next;
	delete(dummy);
	return( third);
}

/*
————————————————————
The main function
Input : None
Output: None
Parameter Passing Method : None
Calls : get(), show() and mul()
to read, print and Multiply the two polynomials.
————————————————————
*/

int main()
{
	struct pnode *First, *Second, *ans;
	cout<<"Reading details of the first polynomial\n\n";
	First = get();

	cout<<"Reading details of the Second polynomial\n\n";
	Second = get();

	cout<<"\nFirst Polynomial: ";
	show(First);
	cout<<"\nSecond Polynomial : ";
	show(Second);

	ans = mul(First, Second);
	cout<<"\nMultiplication of polynomial is: ";
	show(ans);
	ans = add(First, Second);
	cout<<"\nAdditon of Polynomials is : ";
	show(ans);
	return 0;
}

