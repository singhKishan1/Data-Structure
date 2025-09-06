#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> arr;

bool checkPallindrome(string s){
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp==s;
}


void solve(string s, vector<string> &v, int id){
    if(id>=s.size()){
        arr.push_back(v);
        return;
    }
    
    string temp ="";
    for(int i=id; i<s.size(); ++i){
        temp += s[i];
        if(checkPallindrome(temp)){
            cout << "hit" << endl;
            v.push_back(temp);
            solve(s, v, i+1);
            v.pop_back();
        }
    }

    return;
}

int main(){
    string s;
    cin>>s;

    vector<string> v;
    solve(s, v, 0);

    cout << arr.size() << endl;
    for(auto x: arr){
        for(auto y:x)
            cout << y << " ";
        cout << endl;
    }

    return 0;
}