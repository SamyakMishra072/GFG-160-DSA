//DAY 5
// Q.Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

// Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

// Examples:

// Input: arr = [2, 4, 1, 7, 5, 0]
// Output: [2, 4, 5, 0, 1, 7]
// Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
// Input: arr = [3, 2, 1]
// Output: [1, 2, 3]
// Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
// Input: arr = [3, 4, 2, 5, 1]
// Output: [3, 4, 5, 1, 2]
// Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(int arr[], int n) {
        int i = n - 2;
        // Find the first element from the end that is smaller than its next element
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        
        if (i >= 0) {
            int j = n - 1;
            // Find the smallest element from the end that is greater than arr[i]
            while (arr[j] <= arr[i]) {
                j--;
            }
            // Swap elements at index i and j
            swap(arr[i], arr[j]);
        }
        // Reverse the subarray starting from i + 1 to the end
        reverse(arr + i + 1, arr + n);
    }

private:
    // No need for a separate swap function in C++ as we can use std::swap
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Reverse function to reverse a portion of the array
    void reverse(int arr[], int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    solution.nextPermutation(arr, n);

    // Output the next permutation of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  // Output: 1 3 2

    return 0;
}
