#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 33;

    int start = 0, currSum = 0;
    bool found = false;

    for (int end = 0; end < n; end++) {
        currSum += arr[end];

        // Shrink window from left if sum > target
        while (currSum > target && start <= end)
            currSum -= arr[start++];

        if (currSum == target) {
            cout << "Subarray found from index " << start
                 << " to " << end << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No subarray with given sum." << endl;

    return 0;
}
