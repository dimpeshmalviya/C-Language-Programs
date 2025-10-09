/*
Problem Statement:
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303

Constraints:
1 <= n <= 1015
*/

// Code:
#include <stdio.h>

#define ll long long
#define MOD 1000000007

ll goodNumbers(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return ans;
}

int countGoodNumbers(long long n)
{
    return (int)((goodNumbers(4, n / 2) * goodNumbers(5, n - n / 2)) % MOD);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%d\n", countGoodNumbers(n));
    return 0;
}
