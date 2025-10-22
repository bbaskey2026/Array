#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 1, 9, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = arr[0], minVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    cout << "Max = " << maxVal << endl;
    cout << "Min = " << minVal << endl;

    return 0;
}
