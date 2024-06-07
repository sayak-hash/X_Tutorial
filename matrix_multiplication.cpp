#include<iostream>
using namespace std;
class Matrix{
    int matrix[10][10];
    public:
        void getdata(int rows,int cols){
           for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cout<<"Enter element ["<<i<<"]"<<"["<<j<<"] :";
                    cin>>matrix[i][j];
                }
            } 
        }
        void display_result(int r1,int c1,int r2,int c2){
            if(c1==r2){
            cout<<"The multiplied matriux is :";
            for(int i=0;i<r1;i++){
                for(int j=0;j<c2;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl<<"\t\t"<<"\t"<<"  ";
            }
            }
            else {
                cout<<"Matrices can not be miltiplied";
            }
        }

        void display(int r,int c){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl<<"\t"<<"\t"<<"  ";
            }
      }
        void multiplication(Matrix mm1,Matrix mm2,int r1,int c1,int r2,int c2){
            if(c1==r2){
                for(int i=0;i<r1;i++){
                    for(int j=0;j<c2;j++){
                        matrix[i][j]=0;
                        for(int k=0;k<r2;k++){
                            matrix[i][j]+=mm1.matrix[i][k]*mm2.matrix[k][j];
                        }   
                    }
                 }
                  cout<<"Multiplication has been done succesfully";
            }
            else {
                cout<<"multiplication can not be done";
            }
        }
};
int main(){
    Matrix mm1,mm2,mm3;
    int row1,col1;
    int row2,col2;
    int ch;
    cout<<"Enter the row and column of first matrix:";
    cin>>row1>>col1;
    cout<<"Enter the row and column of second matrix:";
    cin>>row2>>col2;
    do {
        cout<<endl<<"1 for getdata for m1"<<endl<<"2 for getdata for m2"<<endl<<"3 for matrix display"<<endl<<"4 for multiplication"<<endl<<"5 for resultant matrix display"<<endl<<"6 for exit";
        cout<<endl<<"Enter your choice =";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter data for first matrix:"<<endl;
                mm1.getdata(row1,col1);
                break;
            case 2:
                 cout<<"Enter data for second matrix:"<<endl;
                 mm2.getdata(row2,col2);
                 break;
            case 3 :
                cout<<"The first matrix is :";
                mm1.display(row1,col1);
                cout<<"The second matrix is :";
                mm2.display(row2,col2);
                break;
            case 4:
                 mm3.multiplication(mm1,mm2,row1,col1,row2,col2);
                 break;
            case 5 :
                mm3.display_result(row1,col1,row2,col2);
                break;
            default:
                cout<<"wrong choice";
                break;
        }
    }while(ch !=6);
    return 0;
}