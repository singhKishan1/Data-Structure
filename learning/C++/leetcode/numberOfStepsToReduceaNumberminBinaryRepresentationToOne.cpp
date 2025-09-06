#include <iostream>

using namespace std;

int solve(string s){
    int cnt = 0;
    while(s.size()>=1){
        if(s.size()==1 && s[0]=='1')
            break;
        
        if(s[s.size()-1]=='0'){
            s.pop_back();
        }
        else{
            int i=s.size()-1;
            while(i>=0 && s[i]=='1'){
                s[i] = '0';
                --i;
            }

            if(i<0)
                s = "1" + s;
            else
                s[i] = '1';
        }
        ++cnt;
    }

    return cnt;
}

int main(){
    string s;
    cin>>s;

    cout << solve(s) << endl;
    return 0;
}