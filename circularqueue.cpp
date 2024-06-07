#include<iostream>
using namespace std;
#define max 5
int cq[max],front=-1, rear =-1;

    void enqueue(int val){
        if (rear==-1 && front ==-1){ 
                front=rear=0;
                cq[rear]=val;
        }
        else if((rear+1)%max==front){
            cout<<"The circular queue is full";
        }
        else{
            rear =(rear+1)%max;
            cq[rear]=val;
        }
        
    }

    void dequeue(){
        if (rear==-1 && front ==-1){ 
            cout<<"The queue is empty";
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            cout<<"The deleted element is"<<cq[front];
            front= (front+1)%max;
        }
    }

    void peek(){
        if (rear==-1 && front ==-1){ 
            cout<<"The queue is empty";
        }
        else{
            cout<<"The fronted element is"<<cq[front];
        }
    }

    void display(){
        int i=front;
        if (rear==-1 && front ==-1){ 
            cout<<"The queue is empty";
        }
        else{
            cout<<"The circlar queue elements are = "<<" ";
            while(i!=rear){
                cout<< cq[i]<<" ";
                i=(i+1)%max;
            }
            cout<<cq[rear];
            }
        }

    int  main(){
        int val,ch;
        do
        {
        cout<<endl<<"1 for enqueue"<<endl;
        cout<<"2 for dequeue "<<endl;
        cout<<"3 for display"<<endl;
        cout<<"4 for peek"<<endl;
        cout<<"5 for exit"<<endl;
        cout<<"Enter the choice ";
        cin>> ch;
        switch(ch){
            case 1:
                cout<<"Enter the value to be inserted=";
                cin>>val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
        case 5:
                exit(0);
                break;
            default:
            cout<<"Wrong choice";
        }
        }

while (ch!= 5);
return 0 ; 

        }
    
    
    