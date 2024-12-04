//DAY 2
//Q. Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in place.

// Examples:

// Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
// Output: [1, 2, 4, 3, 5, 0, 0, 0]
// Explanation: There are three 0s that are moved to the end.
// Input: arr[] = [10, 20, 30]
// Output: [10, 20, 30]
// Explanation: No change in array as there are no 0s.
// Input: arr[] = [0, 0]
// Output: [0, 0]
// Explanation: No change in array as there are all 0s.
#include <iostream>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(int arr[], int n) {
        // code here
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[index] = arr[i];
                index++;
            }
        }
        while (index < n) {
            arr[index] = 0;
            index++;
        }
    }
};

int main() {
    Solution solution;
    int arr[] = {0, 1, 9, 8, 0, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    solution.pushZerosToEnd(arr, n);
    
    // Output the modified array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Output: 1 9 8 4 5 0 0

    return 0;
}
