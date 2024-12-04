//DAY 6
// Q.You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: []
// Explanation: no candidate occur more than n/3 times.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMajority(int arr[], int n) {
        vector<int> result;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        int count1 = 0, count2 = 0;

        // First pass: Find the two potential majority candidates
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate1) {
                count1++;
            } else if (arr[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = arr[i];
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = arr[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Verify the actual counts of the candidates
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate1) {
                count1++;
            } else if (arr[i] == candidate2) {
                count2++;
            }
        }

        // Add the valid majority elements to result
        if (count1 > n / 3) {
            result.push_back(candidate1);
        }
        if (count2 > n / 3) {
            result.push_back(candidate2);
        }

        // Sort the result in ascending order
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution;
    int arr[] = {3, 1, 3, 3, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = solution.findMajority(arr, n);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;  // Output: 3

    return 0;
}

