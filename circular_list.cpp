#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *next;
};

typedef struct node snode;
snode *first = NULL, *last = NULL;
class circular{
    public:
    snode *create_node(){
        int val;
        snode *newnode;
        newnode=(snode*)malloc(sizeof (snode));
        cout<<"Enter  the value to  be inserted =";
        cin>>val;
        if (newnode==NULL){
            cout<<endl<<"Memory is not allocated";
            return 0;
        }
        else {
            newnode->value =val;
            newnode->next==NULL;
            return newnode;

        }
    }
// insert the node at first
    void insert_first(){
        snode *temp,*newnode;
        temp=first;
        newnode =create_node();
        if(first==NULL){
            first=newnode;
            first->next=first;
        }
        else {
            while(temp->next!=first){
                temp=temp->next;
            }
            newnode->next=first;
            first=newnode;
            temp->next=first;
         }
    }
    // insert node at the end
    void insert_end(){
        snode *temp,*newnode;
        temp=first;
        newnode =create_node();
        if(first==NULL){
            first=newnode;
            first->next=first;
        }
        else{
            while(temp->next!=first){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=first;
        }
    }
// insert at specific position
    void insert_pos(){
        snode *temp,*prev,*newnode;
        int pos;
        cout<<"Enter the position where you wnt to insert=";
        cin>> pos;
        newnode=create_node();
        int count=1;
        temp=first;
        while(temp->next!=first){
            temp=temp->next;
            count++;
        }
        cout<<"The total no. of nodes in the list is "<<count;
        if(pos>1 && pos< count){
            temp=first;
            for(int i=1;i<=pos;i++){
                prev=temp;
                temp=temp->next;
            }
             prev->next=newnode;
             newnode->next=temp;

        }
    }
    // delete the first node of the list
    void delete_first(){
        snode *temp,*after;
        if(first==NULL)
            cout<<"The list is empty";
        else{
            temp=first;
            while(temp->next!=first){
                temp=temp->next;
            }
            after=first;
            first=first->next;
            temp->next=first;
            cout<<"The deleted element of the ist is="<<after->value;
            free(after);

        }
    }
    // delete at the end of the list
    void delete_end(){
        snode *temp,*prev;
        if(first==NULL)
            cout<<"The list is empty";
        else{
            temp=first;
            while(temp->next!=first){
                prev=temp;
                temp=temp->next;
            }
            prev->next=first;
            cout<<"The deleted element is ="<<temp->value;
            free(temp);
        }
    }
    // delete at specific position of the list
    void delete_specific() {
    int pos, count = 1;
    snode *prev, *temp;
    temp = first;
    cout << "Enter the position=";
    cin >> pos;
    while (temp->next != first){
        temp = temp->next;
        count++;
    }
    cout << endl << "The no. of nodes in the list is =" << count;
    if (pos > 1 && pos < count) {
        temp = first;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        cout << endl<<"the value of prev and temp are =" << prev->value <<" "<< temp->value;
        prev->next = temp->next;
        cout << endl<<"Element is deleted="<<temp->value;
        free(temp);
        return ; 
    }
    else
        cout << "Out of the range";
}
 //  display the list
    void display(){
        snode *temp;
        if(first==NULL)
            cout<<"List is empty";
        else{
            temp=first;
            cout<<endl<<"The element of the lists are =";
            while(temp->next!=first){
                cout<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<" "<<temp->value;
        }
    }
    
};
// The main function 
int main(){
    circular c;
     int choice;
    do {
        cout  <<endl<< "1 for create node" << endl << "2 for inserting a  node" << endl << "3 for deleting a node" << endl << "4 for traversing ";
        cout << endl << "Enter the choice=";
        cin >> choice;
        switch (choice) {
            case 1:
                c.create_node();
                break;
            case 2:
                c.insert_first();
                break;
            case 3:
                c.insert_end();
                break;
            case 4:
                c.insert_pos();
                break;
            case 5:
                c.delete_first();
                break;
            case 6:
                c.delete_end();
                break;
            case 7:
                c.delete_specific();
                break;
            case 8:
                c.display();
                break;
            default:
                cout << "Wrong choice";
                break;
        }
    } while (choice != 9);
    return 0;
}