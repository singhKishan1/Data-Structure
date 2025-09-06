#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

/**
 * Taking argument integer value and returning binary-string of that integer.
*/
string intToBin(int num){
    string s = "";
    while(num>0){
        s += to_string(num&1);
        num = num >> 1;
    }
    reverse(s.begin(),s.end());
    return s;
}

unordered_map<string, vector<int>> generateSubstrings(string str) {
    int n = str.length();
    unordered_map<string, vector<int>>mp;

    //remvoing trailing zeros, except last one.
    int len=0;
    for(int i=0; i+1<str.size() && str[i+1]!='1'; ++i){
        ++len;
    }

    if(len>0){
        str = str.substr(0,len);
    }

    // Outer loop for the starting index
    for (int i = 0; i < n; i++) {
        // Inner loop for the length of substring

        for (int len = 1; len <= n - i && len<=30; len++) {
            // Print substring from index i with length len

            string temp = str.substr(i, len);
            if(mp.find(temp)==mp.end()){

                mp[temp] = {i, i+len-1};

            }
        }
    }

    return mp;
}

vector<vector<int>> substringXORQueriest(string s, vector<vector<int>> &queries){
    unordered_map<string, vector<int>>mp = generateSubstrings(s);
    vector<string> v;
    for(auto x:queries){
        int temp = x[0]^x[1];
        v.push_back(intToBin(temp));
    }
    cout << "\n\n\nPrinting binary values|";
    for(auto x:v)
        cout << x << endl;
    
    vector<vector<int>> ans;
    for(auto x:v){
        if(x.find('1')){
            if (mp.find(x) != mp.end()){
                ans.push_back(mp[x]);
            }
            else{
                ans.push_back({-1, -1});
            }
        }
    }
    
    return ans;
}

void display(vector<vector<int>> arr){
    cout << "\n";
    for(auto x:arr)
        cout << x[0] << "\t" << x[1] << endl;
    
}

/**
 * Main Function
*/
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i=0; i<n; ++i){
        cin>>arr[i][0] >> arr[i][1];
    }

    arr = substringXORQueriest(s,arr);
    cout << "\n\nAmsw";
    display(arr);
    return 0;
}