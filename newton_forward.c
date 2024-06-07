// NEWTON FOWWARD
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    float X,h,u,s,p=1;
    printf("Enter the element size = ");
    scanf("%d",&n);
    float x[n],y[n],F[n][n];

    printf("Enter the x values =");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }

    printf("Enter the y values =");
    for(int i=0;i<n;i++){
        scanf("%f",&y[i]);
    }

    printf("Enter the interpolation point =");
    scanf("%f",&X);

    h=x[1]-x[0];
    u=(X-x[0])/h;
    s=y[0];

    for(int i=0;i<n;i++){
        F[0][i]=y[i];    // first row is filled up
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            F[i][j]=0;
        }
    }

     for(int i=1;i<n;i++){      
        for(int j=0;j<n-i;j++){
            F[i][j]=F[i-1][j+1]-F[i-1][j];   // remaaining rows are filled up
        }
     }
     
     for(int i=1;i<n;i++){
     p=p*((u-i+1)/i);
     s=s+(p*F[i][0]);
     }

     for(int i=1;i<n;i++){      
        for(int j=0;j<n-i;j++){
           printf("%.2f\t",F[i][j]);
        }
            printf("\n");
     }

    printf("The value of interpolation is =%.2f",s);
    return 0;
}