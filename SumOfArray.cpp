#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    cout << "Sum = " << sum << endl;

    return 0;
}
