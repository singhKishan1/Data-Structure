#include <iostream>
#include <unordered_set>

using namespace std;

int solve(string s)
{
    int n = s.size();
    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int len=1; len<=n-i; ++len){
            int cnt = 0;
            string tmp = s.substr(i, len);
            for(int k=0; k<tmp.size()-1; ++k){
                if(tmp[k]==tmp[k+1])++cnt;
            }

            if(cnt<=1)
                ans = max(ans, len);
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}