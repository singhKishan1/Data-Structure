#include <iostream>


using namespace std;

int editDistance(string &s1, string &s2, int i, int j){
    if(i==0 || j==0)return i+j;
    if(s1[i-1]==s2[j-1])return editDistance(s1, s2, i-1, j-1);
    else{
        return 1 + min(min(editDistance(s1, s2, i-1, j), editDistance(s1, s2, i, j-1)), editDistance(s1, s2, i-1, j-1));
    }
}

int main(){
    string s1, s2;
    cin>>s1>>s2;

    cout << editDistance(s1, s2, s1.size()-1, s2.size()-1) << endl;
    return 0;
}