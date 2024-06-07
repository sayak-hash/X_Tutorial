#include<iostream>
using namespace std;
#define max 100
class Stack{
    private :
    int stack[max],top;
    public:
        Stack(){
        top=-1;
    }

    void push (int val) {   // Define push function
        if (top>=max-1) 
            cout<<"Overflow situation";
        else
            stack[++top] =val;
    }

    void pop(){       //Define pop function
        if (top<=-1)
            cout<<"Undcerflow situation";
        else {
            cout<<"The popped elememt is"<<stack[top];
            top --;
            }
    }
    void display(){
        int i=top;
        if (top<=-1)
            cout<<"stack is empty";
        else{
            cout<<"The stack elements are="<<" ";
            for(i=top;i>=0;i--)
            cout<<stack[i] <<" ";

        }
    }
     
     bool empty(){
        return (top == -1);
     }

     int top (){
        if (top<0)
        cout<<"List is empty";
        else
        return stack[top];
     }
};

