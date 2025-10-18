include <bits/stdc++.h>
using namespace std;

/*
 * armstrong_number.cpp
 *
 * A program to check if a number is an Armstrong number.
 * Example:
 *   Input: 153
 *   Output: Armstrong Number
 */

int main() {
    int n;
    cin >> n;

    int temp = n, sum = 0;
    int digits = to_string(n).size();

    while (temp > 0) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }

    if (sum == n)
        cout << "Armstrong Number";
    else
        cout << "Not an Armstrong Number";

    return 0;
}
