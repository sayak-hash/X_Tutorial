#include<iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Check if it is possible to make all elements zero
        bool possible = true;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] < a[i - 1]) {
                possible = false;
                break;
            }
            a[i] = min(a[i], a[i - 1]);
            a[i + 1] -= (a[i] - a[i - 1]);
        }

        // Output the result for the current test case
        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}
