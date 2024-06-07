#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *next;
};
typedef struct node snode;
snode *first=NULL,*last=NULL;
class LIST{
    private :
    int x=1,y=1;
    public :
    snode *create_node(){ 
         int val;
        cout<<"Entre the value to be inserted=";
        cin>>val;
        snode *newnode=(snode *) malloc (sizeof (snode));
        if(newnode==NULL){
            cout<<"Memory was not allocated";
            return 0;
        }
        else {
            newnode->value=val;
            newnode->next=NULL;
            return newnode;
        }
    }

    void insert_beg(){
        snode *newnode,*temp;
        newnode=create_node();
        cout<<x;
        if(first==NULL){
            first=last=newnode;
            first->next=NULL;
            newnode->next=first;
        }
        else {
            temp=first;
            while(temp->next!=first){
                temp=temp->next;
            }
            newnode->next=first;
            first=newnode;
            temp->next=first;
        }
    }

    void insert_end(){
        snode *newnode,*temp;
        newnode=create_node();
        if(first==NULL){
            first=last=newnode;
            first->next=first;
        }
        else{
            temp=first;
            while(temp->next!=first){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=first;
        }

    }

    void insert_pos(){
        snode *newnode,*temp,*prev;
        int val,pos,count=1;
        newnode=create_node();
        temp=first;
        while(temp->next!=first){
            temp=temp->next;
            count++;
        }
        cout<<"The no. of nodes is ="<<count;
        cout<<endl<<"Enter the no. of position =";
        cin>>pos;
        if(pos>1 && pos<count){
            temp=first;
            for(int i=1;i<pos;i++){
                prev=temp;
                temp=temp->next;
            }
            prev->next=newnode;
            newnode->next=temp;
        }
        else {
            cout<<"Out of range";
        }
    }

    void traverse() {
    snode *temp;
    temp = first;
    if (first == NULL)
        cout << "List is empty";
    else {
            cout << endl << "The values containing in the list are=";
        while (temp->next != first) {
            cout << temp->value << "->";
            temp = temp->next;
        }
    }
    cout<<temp->value;
}
    void delete_first() {
    snode *temp,*temp1;
    if (first == NULL)
        cout << "The list is empty";
    else {
        temp = first;
        temp1=first;
        while(temp->next!=first){
            temp=temp->next;
        }
        first = first->next;
        temp->next=first;
        cout<<"The deleted element is  :"<<temp1->value;
        free(temp1);
    }
}

void delete_end() {
    snode *prev, *temp;
    temp = first;
    while (temp->next != first) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = first;
    cout<<"The deleted element is  :"<<temp->value;
    free(temp);
}

void delete_specific() {
    int pos, count = 1;
    snode *prev, *temp;
    temp = first;
    cout << "Enter the position=";
    cin >> pos;
    while (temp->next != first) {
        temp = temp->next;
        count++;
    }
    cout  << "The no. of nodes in the list is =" << count;
    if (pos > 1 && pos < count) {
        temp = first;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        cout << endl<<"the value of prev and temp are =" << prev->value <<" " << temp->value;
        prev->next = temp->next;
        cout << endl<<"Element is deleted ="<<temp->value;
        free(temp);
        return;
    }
    else
        cout << "Out of the range";
}
// sorting the list
    void selection_sort(){
        snode *temp,*i,*j;
        int val,count=1;
        temp=first;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        cout<<"The total nop. of nodes is ="<<count;
        for(i=first;i->next!=NULL;i=i->next){
            for(j=i->next;j->next!=NULL;j=j->next){
            if(i->value>j->value){
                    val=i->value;
                    i->value=j->value;
                    j->value=val;
                }
            }
        }
        cout<<endl<<"Selection sort is done successfully";
    }
};

int main(){
     int choice;
     LIST s;
    do {
        cout  <<endl<< "1 for create node" << endl << "2 for inserting a  node" << endl << "3 for deleting a node" << endl << "4 for traversing ";
        cout << endl << "Enter the choice=";
        cin >> choice;
        switch (choice) {
            case 1:
                s.create_node();
                break;
            case 2:
                s.insert_beg();
                break;
            case 3:
                s.insert_end();
                break;
            case 4:
                s.insert_pos();
                break;
            case 5:
                s.delete_first();
                break;
            case 6:
                s.delete_end();
                break;
            case 7:
                s.delete_specific();
                break;
            case 8:
                s.traverse();
                break;
           // case 9:
             //   s.selection_sort();
               // break;
            default:
                cout << "Wrong choice";
                break;
        }
    } while (choice != 10);
    return 0;
}