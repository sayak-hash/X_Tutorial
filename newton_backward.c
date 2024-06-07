//NEWTON BACKWARD
#include<stdio.h>
#include<stdlib.h>
int main(){
    float xp,p=1.00,u,h,s;
    int n;
    printf("Enter the size : ");
    scanf("%d",&n);

    float x[n],y[n],f[n][n];

    printf("Enter the x values = ");
    for(int i=0;i<n;i++){
        scanf("%f",&x[i]);
    }

     printf("Enter the y values = ");
    for(int i=0;i<n;i++){
        scanf("%f",&y[i]);
    }

    printf("Enter the interpolation point =");
    scanf("%f",&xp);
     h=x[1]-x[0];
     u=(xp-x[n-1])/h;
     s=y[n-1];

     for(int i=0;i<n;i++){
        f[0][i]=y[i];
     }

     for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            f[i][j-1]=f[i-1][j]-f[i-1][j-1];
        }
     }

     for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n-i;j++ ){
            printf("%.4f\t",f[i][j]);
        }
     }
       for(int i=1;i<n;i++){
        
     p=p*((u+i-1)/i);
     s=s+(p*f[i][n-i-1]);
     }


    printf("The value of interpolation is =%.4f",s);
    return 0;

}