//SIMPSON ONR THIRD
#include<stdio.h>
#include<stdlib.h>
//#define f(x)  1/(1+(x*x))  // Define the function to be integrated

 float f (float x){
    return (1/(1+x*x));
}

int main(){
    float a, b, h, integ=0.0 ;
    int n;

    printf("Enter the upper limit: ");
    scanf("%f", &b);

    printf("Enter the lower limit: ");
    scanf("%f", &a);

    printf("Enter the number of sub-intervals (must be even): ");
    scanf("%d", &n);

    // Check if the number of sub-intervals is even
    if (n % 2 != 0) {
        printf("Number of sub-intervals must be even.\n");
        return 1;
    }

    h = (b - a) / n;  // Calculate the step size

    // Apply Simpson's 1/3 rule
    for(int i = 1; i < n; i++){
        if(i % 2 == 0) {
            integ += 2 * f(a + i * h);
        } else {
            integ += 4 * f(a + i * h);
        }
    }

    integ = (h / 3) * (f(a) + f(b) + integ);
    printf("The value of the integration is = %.4f\n", integ);

    return 0;
}
