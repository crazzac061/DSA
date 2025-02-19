#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int seqBinary(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; 
        }
        if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; 
}

int recBinary(vector<int> &arr, int target, int low, int high) {
    if (low > high) {
        return -1; 
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid; 
    }
    if (target < arr[mid]) {
        return recBinary(arr, target, low, mid - 1);
    } else {
        return recBinary(arr, target, mid + 1, high);
    }
}

int main() {
    vector<int> arr = {1, 4, 3, 2, 7, 6, 5};
    int n = arr.size();
    int target;
    cout << "Enter the target: ";
    cin >> target;


    cout << target << " is found at index " << linearSearch(arr, target) << " using linear search" << endl;


    sort(arr.begin(), arr.end());

    cout << target << " is found at index " << seqBinary(arr, target) << " using sequential binary search" << endl;
    cout << target << " is found at index " << recBinary(arr, target, 0, n - 1) << " using recursive binary search" << endl;

    return 0;
}