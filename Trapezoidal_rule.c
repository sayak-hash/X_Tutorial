//TRAPEZOIDAL
#include<stdio.h>
#include<stdlib.h>
#define f(x) x

int main(){
    float a, b, h, integ = 0.0, temp = 0.0;
    int n;

    printf("Enter the upper limit = ");
    scanf("%f", &b);

    printf("Enter the lower limit = ");
    scanf("%f", &a);

    printf("Enter the sub-interval size = ");
    scanf("%d", &n);

    h = (b - a) / n;  // Calculate the step size

    // Apply the trapezoidal rule
    for(int i = 1; i < n; i++){
        integ += f(a + i * h);
    }

    temp = (h / 2) * (f(a) + f(b) + 2 * integ);
    printf("The value of that integration is = %.2f\n", temp);

    return 0;
}
