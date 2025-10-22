#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {10, 20, 4, 45, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        cout << "No second largest element\n";
    else
        cout << "Second largest element: " << second << endl;

    return 0;
}
