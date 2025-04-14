#include <iostream>
using namespace std;

int recursiveSum(int arr[], int index, int size) {
    if (index == size)  
        return 0;
    return arr[index] + recursiveSum(arr, index + 1, size);
}


int iterativeSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    
    int* arr = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    
    int sum_recursive = recursiveSum(arr, 0, size);

    
    int sum_iterative = iterativeSum(arr, size);

    
    cout << "\nSum using Recursive Approach: " << sum_recursive << endl;
    cout << "Sum using Iterative Approach: " << sum_iterative << endl;

    
    delete[] arr;

    return 0;
}

