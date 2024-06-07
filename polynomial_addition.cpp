#include<iostream>
using namespace std;

struct node {
    float coff;
    int expo;
    struct node *next;
};
 typedef struct node snode;
 class Polynomial{
    public :
    struct node *insert(snode *head,float co,int ex){
        struct node *temp;
        struct node *newnode=(snode*) malloc (sizeof (snode));
        newnode->coff=co;
        newnode->expo=ex;
        newnode->next=NULL;

        if(head==NULL || ex>head->expo){
            newnode->next=head;
            head=newnode;
        }
        else {
            temp=head;
            while(temp->next!=NULL && temp->next->expo>ex){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        return head;
    }

    snode *create(snode *head){
        int n,i;
        float coff;
        int expo;
        cout<<endl<<"Enter the no. of terms =";
        cin >>n;

        for(i=0;i<n;i++){
            cout<<"Enter the coefficient for the "<< i+1 <<" term =";
            cin>>coff;

            cout<<"Enter the exponent for the "<< i+1 <<" term =";
            cin>>expo;
            cout<<endl;
            head=insert(head,coff,expo);
        }
        return head;
    }

    snode* poly_Add(snode *head1,snode *head2){

        snode *ptr1=head1;
        snode *ptr2=head2;
        snode *head3=NULL;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->expo == ptr2->expo){
                head3=insert(head3,ptr1->coff+ptr2->coff,ptr1->expo);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else if(ptr1->expo> ptr2->expo){
                head3=insert(head3,ptr1->coff,ptr1->expo);
                ptr1=ptr1->next;

            }
            else if(ptr1->expo<ptr2->expo){
                head3=insert(head3,ptr2->coff,ptr2->expo);
                ptr2=ptr2->next;

            }
        }
        while (ptr1!=NULL){
            head3=insert(head3,ptr1->coff,ptr1->expo);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
            head3=insert(head3,ptr2->coff,ptr2->expo);
            ptr2=ptr2->next;
        }
       return head3;
    }

    void print(snode *head){
        if(head==NULL){
            cout<<"No polynomial exits";
        }
        else {
            snode *temp=head;
            while(temp!=NULL){
                cout<<temp->coff<<"x^"<<temp->expo;
                temp=temp->next;
                if(temp!=NULL){
                    cout<<" + ";
                }
                else  cout<<endl;
            }
        }

    }
 };
int main(){
     Polynomial p;
     snode *head1=NULL;
     snode *head2=NULL;
     cout<<"Enter the first polynomial";
     head1=p.create(head1);
     cout<<endl<<"First polynomial is =";
     p.print(head1);
     cout<<endl<<"Enter the second polynomial";
     head2=p.create(head2);
     cout<<endl<<"Second polynomial is =";
     p.print(head2);
     snode *head3=p.poly_Add(head1,head2);
     cout<<endl<<"Added polynomial is =";
    p. print(head3);
     return 0;
}
