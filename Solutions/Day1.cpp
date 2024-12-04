//DAY 1
//Q. Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.

// Examples:

// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.
// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.
// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist.

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int getSecondLargest(int arr[], int n) {
        if (n < 2) {
            return -1;
        }

        int largest = INT_MIN;   // Initialize the largest element
        int secondLargest = INT_MIN; // Initialize the second largest element

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                // Update second largest before updating largest
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] < largest) {
                // Update second largest if it's less than largest but greater than current second largest
                secondLargest = arr[i];
            }
        }

        // If secondLargest is not updated, return -1
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};

int main() {
    Solution solution;
    int arr[] = {2, 4, 1, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << solution.getSecondLargest(arr, n) << endl;

    return 0;
}
