#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return the index
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    const int size = 8;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8};
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
