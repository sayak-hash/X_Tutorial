#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number=";
    cin >> n;

    if(n < 2) {
        cout << endl << n << " is not a prime number";
    }
    else {
        bool isPrime = true;
        for(int i = 2; i <= n-1; i++) {
            if(n % i == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime) {
            cout << endl << n << " is a prime number";
        } else {
            cout << endl << n << " is not a prime number";
        }
    }

    return 0;
}
