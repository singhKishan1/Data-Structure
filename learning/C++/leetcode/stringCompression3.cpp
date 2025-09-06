#include <bits/stdc++.h>
using namespace std;

string compressedString(string word)
{
    string ans = "";
    int cnt = 0;
    int i = 0;
    while (i < word.size())
    {
        char ch = word[i];
        while (i < word.size() && word[i] == ch && cnt < 9)
        {
            ++cnt;
            ++i;
        }

        ans += to_string(cnt) + ch;

        cnt = 0;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << compressedString(s) << endl;
    return 0;
}