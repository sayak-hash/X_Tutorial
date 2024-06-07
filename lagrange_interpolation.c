//LAGRANGE INTERPOLATION
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    float xp, yp = 0.0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter the x values: ");
    for(int i = 0; i < n; i++){
        scanf("%f", &x[i]);
    }

    printf("Enter the y values: ");
    for(int i = 0; i < n; i++){
        scanf("%f", &y[i]);
    }

    printf("Enter the interpolation point: ");
    scanf("%f", &xp);

    // Implementing Lagrange interpolation formula
    for(int i = 0; i < n; i++){
        float p = 1.0; // Initialize product term
        for(int j = 0; j < n; j++){
            if(i != j){
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i]; // Add the current term to the interpolation result
    }

    printf("The interpolated value at %.2f is %.2f\n", xp, yp);
    return 0;
}
