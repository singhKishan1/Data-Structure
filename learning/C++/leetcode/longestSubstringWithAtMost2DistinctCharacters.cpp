#include <iostream>
// #include <unordered_map>

using namespace std;

int solve(string s)
{
    if (s.size() < 3)
        return s.size();

    int ans = 0;
    int charCount[256] = {0};
    int count = 0;
    for (int left = 0, right = 0; right < s.size(); ++right)
    {

        if (charCount[s[right]] == 0)
        {
            ++count;
        }
        charCount[s[right]]++;
        while (count > 2)
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0)
                --count;

            ++left;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

/*
int solve(string s)
{
    if (s.size() < 3)
        return s.size();

    unordered_map<char, int> charCount;
    int ans = 0;
    for (int left = 0, right = 0; right < s.size(); ++right)
    {
        charCount[s[right]]++;
        while (charCount.size() > 2)
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0)
            {
                charCount.erase(s[left]);
            }
            ++left;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}
    */
int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}