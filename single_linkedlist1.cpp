#include<iostream>
using namespace std;

struct node {
    int value;
    struct node *next;
};

typedef struct node snode;
snode *first = NULL, *last = NULL;

snode *createnode() {
    int val;
    cout << endl << "Enter the value inserted at this node=";
    cin >> val;
    snode *newnode = new snode;
    if (newnode == NULL) {
        cout << "Memory is not allocated";
        return 0;
    }
    else {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

void create_list() {
    int n, i;
    snode *temp, *newnode;
    cout << endl << "Enter the no. of nodes to be inserted=";
    cin >> n;
    for (i = 0; i < n; i++) {
        newnode = createnode();
        if (first == NULL) {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else {
            temp = first;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void insert_first() {
    snode *newnode, *temp;
    newnode = createnode();
    if (first == NULL) {
        first = newnode;
        first->next = NULL;
    }
    else {
        temp = first;
        first = newnode;
        first->next = temp;
    }
}

void insert_end() {
    snode *temp, *newnode;
    newnode = createnode();
    if (first == NULL) {
        first = newnode;
        first->next = NULL;
    }
    else {
        temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_specific() {
    int pos, count = 1;
    snode *newnode, *temp, *prev;
    cout << "Enter the position =";
    cin >> pos;
    newnode = createnode();
    temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    cout << endl << "The total no. of nodes is = " << count;
    if (pos > 1 && pos < count) {
        temp = first;
        for (int i = 1; i <= pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else
        cout << "Out of the range";
}

void delete_first() {
    snode *temp;
    if (first == NULL)
        cout << "The list is empty";
    else {
        temp = first;
        first = first->next;
        free(temp);
    }
}

void delete_end() {
    snode *prev, *temp;
    temp = first;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_specific() {
    int pos, count = 1;
    snode *prev, *temp;
    temp = first;
    cout << "Enter the position=";
    cin >> pos;
    while (temp->next != NULL) {
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

void traverse() {
    snode *temp;
    temp = first;
    if (first == NULL)
        cout << "List is empty";
    else {
            cout << endl << "The values containing in the list are=";
        while (temp->next != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
    cout<<temp->value;
}

int main(){
     int choice;
    do {
        cout  <<endl<< "1 for create node" << endl << "2 for inserting a  node" << endl << "3 for deleting a node" << endl << "4 for traversing ";
        cout << endl << "Enter the choice=";
        cin >> choice;
        switch (choice) {
            case 1:
                createnode();
                break;
            case 2:
                insert_first();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_specific();
                break;
            case 5:
                delete_first();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_specific();
                break;
            case 8:
                traverse();
                break;
            case 9:
                selection_sort();
                break;
            default:
                cout << "Wrong choice";
                break;
        }
    } while (choice != 10);
    return 0;
}