#include <iostream>
#include <string>
using namespace std;


int superDigit(int n) {

    if (n < 10) {
        return n;
    }

    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }


    return superDigit(sum);
}


int findSuperDigit(string n, int k) {

    int digitSum = 0;
    for (char digit : n) {
        digitSum += digit - '0';
    }


    int initialSum = digitSum * k;


    return superDigit(initialSum);
}

int main() {
    string n;
    int k;


    cout << "Enter the number n (as a string): ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;


    int result = findSuperDigit(n, k);
    cout << "The super digit is: " << result << endl;

    return 0;
}

