#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
    {
        cout << "Pattern found at index " << i << endl;
    }
    return;
}

vector<int> match(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();
    int l = 0;
    int r = m;
    vector<int> ans;
    while (r <= n)
    {
        if (!txt.substr(l, m).compare(pat))
        {
            ans.push_back(l);
        }
        r++;
        l++;
    }
    return ans;
}

int main()
{
    string txt, pat;
    cout << "Enter the text: ";
    getline(cin, txt); 
    cout << "Enter the pattern to be searched: ";
    getline(cin, pat);  
    print(match(txt, pat));
}
