#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (const auto& element : collection) {
        if (element > maxVal) {
            maxVal = element;
        }
    }
    return maxVal;
}


template <typename T>
void reverseCollection(vector<T>& collection) {
    reverse(collection.begin(), collection.end());
}


template <typename T>
void displayCollection(const vector<T>& collection) {
    for (const auto& element : collection) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {

    vector<int> intCollection = {1, 5, 3, 9, 7};
    cout << "Integer Collection: ";
    displayCollection(intCollection);

    cout << "Maximum value in integer collection: " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    cout << "Reversed integer collection: ";
    displayCollection(intCollection);


    vector<float> floatCollection = {1.1, 3.5, 7.2, 9.8, 2.3};
    cout << "\nFloat Collection: ";
    displayCollection(floatCollection);

    cout << "Maximum value in float collection: " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    cout << "Reversed float collection: ";
    displayCollection(floatCollection);


    vector<char> charCollection = {'a', 'z', 'r', 'b', 'm'};
    cout << "\nCharacter Collection: ";
    displayCollection(charCollection);

    cout << "Maximum value in character collection: " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    cout << "Reversed character collection: ";
    displayCollection(charCollection);

    return 0;
}
