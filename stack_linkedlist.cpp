#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *next;
};

typedef struct node snode;
snode *top = NULL;
class stack{
    public:
snode *createnode() {
    int val;
    cout << endl << "Enter the value inserted at this node=";
    cin >> val;
    snode *newnode = new snode;
    if (newnode == NULL) {
        cout << "Stack is empty";
        return 0;
    }
    else {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}
// insert element in the stack
void push(){
    snode *newnode;
    newnode=createnode();
    if(top==NULL) {
        top=newnode;
        top->next=NULL;
  }
   else {
    newnode->next=top;
    top=newnode;
    cout<<endl<<"The inserted element is ="<<top->value;
   }
}
// pop element from the stack
void pop(){
    snode *temp;
    if(top==NULL){
        cout<<"Stack is empty";
    }
    else{
        temp=top;
        top=top->next;
        cout<<endl<<"the deleted element is ="<<temp->value;
        free(temp);
    }
}
// display the stack
void display(){
    snode *temp;
    temp=top;
    if(top==NULL)
        cout<<"Stack is empty";
    else{
        cout<<endl<<"The elemments of the stack are =";
        while(temp->next!=NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<<temp->value;
    }
}
};
// main function
int main(){
    stack s;
    int choice ;
    do {
        cout<<endl<<"1 for push"<<endl<<"2 for pop"<<endl<<"3 for display"<<endl<<"4 for exit";
        cout<<endl<<"Enter the choice =";
        cin>>choice;
        switch(choice){
            case 1 :
             s.push();
             break;
            case 2 :
             s.pop();
             break;
            case 3 :
             s.display();
             break;
             default:
             cout<<"wrong choice";
        } 
    }   while(choice!=4);
        return 0;
}
