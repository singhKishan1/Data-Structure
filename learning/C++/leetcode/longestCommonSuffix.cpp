#include <bits/stdc++.h>
using namespace std;

unordered_set<string> getSuffixes(vector<string> arr)
{
    unordered_set<string> s;
    for (int i = 0; i < arr.size(); ++i)
    {
        string num = arr[i];
        for(int j=0; j<num.length(); ++j){
            s.insert(num.substr(j,num.length()-j));
        }
    }

    return s;
}

vector<int> solve(vector<string> wordsContainer, vector<string> queries)
{
    unordered_set<string> st = getSuffixes(wordsContainer);
    cout << "\nGenereated Prefixes  ==>\n";
    for(auto x: st){
        cout << x << endl;
    }cout << endl;


    vector<int> ans;
    for (int i = 0; i < queries.size(); ++i)
    {
        string str = queries[i];
        string s = str;
        int mx = 0;
        while (st.find(str) != st.end())
        {
            mx = max(mx, static_cast<int>(str.length()));
            str += s;
        }
        cout <<"string ==> "<< str << endl;
        ans.push_back(mx);
    }
    return ans;
}

int main()
{
    vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
    vector<string> queries = {"cd", "bcd", "xyz"};

    vector<int> ans = solve(wordsContainer, queries);
    for(auto x: ans)
        cout << x << " ";
    cout << endl;
    return 0;
}