#include<iostream>
using namespace std;

#define max 50

class MergeSort {
public:
    void input(int a[], int n) {
        int i;
        cout << endl << "Enter the elements: ";
        for(i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void merge(int a[], int p, int q, int r){
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], R[n2], i, j, k;

        for(i = 0; i < n1; i++){
            L[i] = a[p + i];
        }

        for(j = 0; j < n2; j++){
            R[j] = a[q + 1 + j];
        }

        i = 0;
        j = 0;
        k = p;

        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                a[k] = L[i];
                i++;
            }
            else {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        while(i < n1){
            a[k] = L[i];
            i++;
            k++;
        }

        while(j < n2){
            a[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int a[], int p, int r) {
        if(p < r) {
            int q = (p + r) / 2;
            mergeSort(a, p, q);
            mergeSort(a, q + 1, r);
            merge(a, p, q, r);
        }
    }

    void display(int a[], int n) {
        cout << "The elements are: ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MergeSort i;
    int a[max];
    int choice, n;

    cout << "Enter number of elements: ";
    cin >> n;

    do {
        cout << endl << "1 for input" << endl << "2 for sorting" << endl << "3 for display" << endl << "5 for exit" << endl;
        cout << "Enter the choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                i.input(a, n);
                break;
            case 2:
                i.mergeSort(a, 0, n - 1);
                cout << "Merge sort has been done successfully" << endl;
                break;
            case 3:
                i.display(a,n);
                break;
            case 5:
                break;
            default:
                cout << "Wrong choice ";
        }
    } while(choice != 5);

    return 0;
}
