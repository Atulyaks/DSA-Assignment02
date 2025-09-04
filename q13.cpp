#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int possibleDups = 0;
    int last = n - 1;

    // Count how many 2s can be duplicated
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
            // Edge case: 2 at the boundary
            if (i == last - possibleDups) {
                arr[last] = 2;  // Just copy it once
                last--;
                break;
            }
            possibleDups++;
        }
    }

    int i = last - possibleDups;  // Start from rightmost element to process
    for (; i >= 0; i--) {
        if (arr[i] == 2) {
            arr[i + possibleDups] = 2;
            possibleDups--;
            arr[i + possibleDups] = 2;  // Duplicate
        } else {
            arr[i + possibleDups] = arr[i];
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 2, 5};

    duplicateTwos(arr);

    cout << "Modified array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
