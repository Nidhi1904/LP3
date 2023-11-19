#include <bits/stdc++.h>
using namespace std;

// Function to partition the array for quicksort
int partition(int low, int high, vector<int>& arr) {
    int left = low + 1;
    int right = high;
    int pivot = arr[low];
    
    while (left <= right) {
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[right], arr[low]);
    return right;
}

// Quicksort function
void quicksort(int low, int high, vector<int>& arr) {
    if (low < high) {
        int pivot = partition(low, high, arr);
        quicksort(low, pivot, arr);
        quicksort(pivot + 1, high, arr);
    }
}

// Function for choosing a random pivot for quicksort
int rquicksort(int low, int high, vector<int>& arr) {
    srand(0); // Seed for generating random numbers
    int rand1 = low + rand() % (high - low); // Generating random index within range
    swap(arr[low], arr[rand1]); // Swapping random element with the first element
    return partition(low, high, arr); 
}

// Randomized Quicksort function
void randomsort(int low, int high, vector<int>& arr) {
    if (low < high) {
        int pivot = rquicksort(low, high, arr);
        randomsort(low, pivot, arr);
        randomsort(pivot + 1, high, arr);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), arr1(n);
    
    // Input elements for the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr1[i] = arr[i];
    }
    
    auto start1 = clock();
    quicksort(0, n - 1, arr);
    auto end1 = clock();
    
    auto start2 = clock();
    randomsort(0, n - 1, arr1);
    auto end2 = clock();
    
    // Output sorted arrays
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // Output execution times of both sorts
    cout << "Normal Quick Sort " << setprecision(10) << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
    cout << "Random Quick Sort " << setprecision(10) << (float)(end2 - start2) / CLOCKS_PER_SEC << endl;
    
    return 0;
}
