#include <iostream>
#include <stack>

using namespace std;

string solve(string str){
    string  ans =  "";
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='.'){
            if(i<=str.size()-3  && str.substr(i,3)=="..."){
                ans+="...";
            }else{
                
            }
        }
    }
}

int main(){
    string s;
    cin>>s;
    cout << solve(s) << endl;
    return 0;
}