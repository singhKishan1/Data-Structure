#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * You are given two strings s1 and s2 of equal length.
 * A string swap is an operation where you choose two indices in a string (not necessarily different)
 * and swap the characters at these indices.
 * Return true if it is possible to make both strings equal
 * by performing at most one string swap on exactly one of the strings.
 * Otherwise, return false.
 */

bool solve(string s1, string s2){
    int missMatch = 0;
    unordered_map<char, int>mp;
    for(auto x:s1)
        mp[x]++;
    
    bool check = true;
    for(int i=0; i<s1.size(); ++i){
        if(mp.find(s2[i])==mp.end())return false;

        mp[s2[i]]--;
        if(mp[s2[i]]==0)mp.erase(s2[i]);

        if(s1[i]!=s2[i])++missMatch;
    }

    return missMatch==2 || missMatch==0;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << solve(s1, s2) << endl;
    return 0;
}