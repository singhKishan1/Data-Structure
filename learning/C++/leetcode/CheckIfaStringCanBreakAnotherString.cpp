#include <iostream>
#include <algorithm>

using namespace std;

bool solve(string s1, string s2){
    bool check = true;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<s1.size(); ++i){
        if(s1[i]<s2[i]){
            check = false;
            break;
        }
    }

    if(check)return true;
    check = true;
    for(int i=0; i<s1.size(); ++i){
        if(s2[i]<s1[i]){
            check = false;
            break;
        }
    }

    return check;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout << solve(s1,s2) <<endl;
    return 0;
}