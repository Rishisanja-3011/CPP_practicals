#include <iostream>
#include <ctime> // For measuring execution time
using namespace std;

// Recursive function to compute sum
int recursiveSum(int arr[], int start, int end) {
    if (start > end)
        return 0;
    if (start == end)
        return arr[start];

    int mid = (start + end) / 2;
    return recursiveSum(arr, start, mid) + recursiveSum(arr, mid + 1, end);
}

// Iterative function to compute sum
int iterativeSum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamic array allocation
    int* arr = new int[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Measure recursive sum execution time
    clock_t startTime = clock();
    int recSum = recursiveSum(arr, 0, n - 1);
    clock_t endTime = clock();
    double recTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    // Measure iterative sum execution time
    startTime = clock();
    int iterSum = iterativeSum(arr, n);
    endTime = clock();
    double iterTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "\n--- Results ---\n";
    cout << "Recursive Sum: " << recSum << "\n";
    cout << "Iterative Sum: " << iterSum << "\n";

    cout << "\n--- Performance ---\n";
    cout << "Recursive Execution Time: " << recTime << " seconds\n";
    cout << "Iterative Execution Time: " << iterTime << " seconds\n";

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}

