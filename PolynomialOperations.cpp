#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
             int coeff;
             int expon;
             struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
            NODE x;
            x = new node;
            return x;
}

NODE attach(int coeff, int expon, NODE head)
{
            NODE temp, cur;
            temp = getnode();
            temp->coeff = coeff;
            temp->expon = expon;
            cur = head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
            temp->link = head;
            return head;
}

NODE  read_poly(NODE head)
{
            int i = 1, coeff, expon;
            cout<<"\nEnter the coefficient as -999 to end the polynomial ";
            while(1)
            {
                        cout<<"\nEnter the "<<i++<<" term:\n";
                        cout<<"\n\tCoeff = ";
                        cin>>coeff;
                        if(coeff == -999)
                                    break;
                        cout<<"\n\tPow x = ";
                        cin>>expon;
                        head = attach(coeff, expon, head);
            }
              return head;
}

NODE poly_add(NODE head1, NODE head2, NODE head3)
{
            NODE a,b;
            int coeff;
            a = head1->link;
            b = head2->link;
            while(a != head1 && b != head2)
            {
                        if(a->expon == b->expon)
                        {
                                    coeff = a->coeff + b->coeff;
                                    if(coeff != 0)
                                                head3 = attach(coeff, a->expon, head3);
                                    a = a->link;
                                    b = b->link;
                        }
                        else if(a->expon > b->expon)
                        {
                                     head3 = attach(a->coeff, a->expon, head3);
                                    a = a->link;
                        }
                        else
                        {
                                    head3 = attach(b->coeff, b->expon, head3);
                                    b = b->link;
                        }
            }
            while(a != head1)
            {
                        head3 = attach(a->coeff, a->expon, head3);
                        a = a->link;
            }
            while(b != head2)
            {
                        head3 = attach(b->coeff, b->expon, head3);
                        b = b->link;
            }
            return head3;
}


NODE poly_mult(NODE head1, NODE head2, NODE head3)
{
            NODE cur1, cur2;
            if(head1->link == head1 || head2->link == head2)
            {
                        cout<<"\nMultiplied polynomial is zero polynomial";
                        return 0;
            }
            cur1 = head1->link;
            while(cur1 != head1)
            {
                        cur2 = head2->link;
                        while(cur2!=head2)
                        {
                                    head3 =attach(cur1->coeff*cur2->coeff, cur1->expon+cur2->expon, head3);
                                   cur2=cur2->link;
                        }
                        cur1=cur1->link;
            }
            return head3;
}

void display(NODE head)
{
            NODE temp;
            if(head->link == head)
            {
                         cout<<"\nPolynomial does not exist";
                         return;
            }
            temp = head->link;
            while(temp != head)
            {
                         cout<<temp->coeff<<"x^"<<temp->expon;
                         temp = temp->link;
                         if(temp != head)
                                    cout<<" + ";
            }
}


int main()
{
            NODE head1, head2, head3,head4;
            head1 = getnode();
            head2 = getnode();
            head3 = getnode();
            head4 = getnode();
            head1->link=head1;
            head2->link=head2;
            head3->link=head3;
            head4->link=head4;

            cout<<"\nEnter the first polynomial \n";
            head1 = read_poly(head1);
            cout<<"\nEnter the second polynomial \n";
            head2 = read_poly(head2);

            head3 = poly_add(head1, head2, head3);

            head4=poly_mult(head1, head2, head4);

            cout<<"\nPolynomial 1:\t";
            display(head1);
            cout<<"\nPolynomial 2:\t";
            display(head2);
            cout<<"\nPolynomial Addition Result:\t";
            display(head3);
            cout<<"\nPolynomial Multiplication Result:\t";
            display(head4);
            return 0;
}
