#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = 0; // pointer for non-zero

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "After moving zeroes: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
