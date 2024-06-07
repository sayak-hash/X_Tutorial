// REGULA FALSI
#include<stdio.h>   
#include<math.h>
#include<stdlib.h>
float f(float x){
    return ((x*x*x)-(2*x)-5);
}

int main(){
    float a,b,c,h,x;
    int i=1;
    printf("Enter the +ve end point = ");
    scanf("%f",&b);

    printf("Enter the -ve end point = ");
    scanf("%f",&a);

    if((f(a)*f(b))>0)  exit (0);

    else {
        do{
            c=a-((f(a)*(b-a)))/(f(b)-f(a));
            if(f(c)<0)  a=c;
            else        b=c;

            h=a-((f(a)*(b-a)))/(f(b)-f(a));
            printf("The %dth point of h is : %f\n",i,h);
            i++;
        } while (fabs(h-c)>0.0001);
    }

    printf("The final root of the equation is = %.3f",h);
    return 0;

}