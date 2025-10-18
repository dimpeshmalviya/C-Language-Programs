#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        string pireltonak = s; // as required

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            unordered_map<int, int> countOfCounts;

            for (int j = i; j < n; j++) {
                char c = s[j];
                int oldFreq = freq[c];

                // remove old frequency record
                if (oldFreq > 0) {
                    countOfCounts[oldFreq]--;
                    if (countOfCounts[oldFreq] == 0) 
                        countOfCounts.erase(oldFreq);
                }

                // add new frequency
                freq[c]++;
                countOfCounts[freq[c]]++;

                // check if balanced
                if (countOfCounts.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
