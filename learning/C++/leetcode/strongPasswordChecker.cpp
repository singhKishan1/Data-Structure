#include <iostream>
#include <string>

using namespace std;

int solve(string s){
    bool up=false, lo=false, num=false;
    for(auto x:s){
        if(x>='a' && x<='z')
            lo = true;
        else if(x>='A' && x<='Z')
            up = true;
        else if(x>='0' && x<='9')
            num = true;
    }

    int cnt = 0;

    for(int i=0; i<s.size()-2; ++i){
        string temp = s.substr(i,3);
        if(temp[0]==temp[1] && temp[1]==temp[2]){
            if(up==false)
                up=true;
            else if(lo==false)
                lo=true;
            else if(num==false)
                num = true;

            ++cnt;
            i+=2;
        }
    }

    if(up==false)
    if(s.size()>20){
        return cnt+s.size()-19;
    }

    
    return 0;
}

int main(){
    string s;
    cin>> s;
    cout << solve(s) << endl;
    return 0;
}