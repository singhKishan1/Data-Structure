#include  <iostream>
#include  <vector>
#include  <algorithm>
#include  <string>

using namespace std;

void addCarry(int &carry, vector<int>&v, int pos){
    while(pos<v.size() && carry>0){
        int val =  v[pos] + carry;
        v[pos] = val%10;
        carry = val/10;
        ++pos;
    }

    while(carry>0){
        v.push_back(carry%10);
        carry = carry/10;
    }
}

string solve(string s1, string s2){

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int n = s2.size();

    vector<int> v(n);
    for(int i=0; i<s1.size();  ++i){
        int pos = i;
        for(int j=0;  j<s2.size();  ++j){
            int carry = (s2[j]-'0')*(s1[i]-'0');
            addCarry(carry, v, pos);
            ++pos;
        }
    }

    reverse(v.begin(), v.end());

    string ans = "";
    for(auto x:v)
        ans += to_string(x);
    return  ans;

}

int main(){
    string num1, num2;
    cin>>num1>>num2;

    cout<<solve(num1, num2) << endl;

    return 0;
}