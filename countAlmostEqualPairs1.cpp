/**
 * You are given an array nums consisting of positive integers.
 * We call two integers x and y in this problem almost equal
 * if both integers can become equal after performing the following operation at most once:
 * Choose either x or y and swap any two digits within the chosen number.
 * Return the number of indices i and j in nums where i < j such that nums[i]
 * and nums[j] are almost equal.
 * Note that it is allowed for an integer to have leading zeros after performing an operation.
 */

#include <bits/stdc++.h>
using namespace std;

bool solve2(string s1, string s2)
{
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] == '0')
        {
            string temp = s1;
            temp.erase(i, 1);
            if (temp == s2)
                return true;
        }
    }

    return false;
}

bool solve(string s1, string s2)
{
    int missMatch = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s1.size(); ++i)
        mp[s1[i]]++;

    bool isPresentCharacter = true;
    for (int i = 0; i < s1.size(); ++i)
    {
        if (mp.find(s2[i]) == mp.end())
        {
            return false;
        }

        mp[s2[i]]--;
        if (mp[s2[i]] == 0)
            mp.erase(s2[i]);

        if (s1[i] != s2[i])
            ++missMatch;
    }

    if (missMatch == 2 || missMatch == 0)
        return true;
    return false;
}

int countPairs(vector<int> &v)
{
    int n = v.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string s1 = to_string(v[i]);
        for (int j = i + 1; j < n; ++j)
        {
            string s2 = to_string(v[j]);
            int x = s1.size(), y = s2.size();
            int mx = max(x, y);

            while (x != mx)
            {
                s1 = "0" + s1;
                ++x;
            }

            while (y != mx)
            {
                s2 = "0" + s2;
                ++y;
            }

            if (solve(s1, s2))
            {
                ++cnt;
            }
        }
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << countPairs(v) << endl;
    return 0;
}