#include <bits/stdc++.h>

using namespace std;


// The function checks if two strings are one edit away
// from each other. It does this by comparing the characters

bool oneEditAway(string s1, string s2)
{
    // Check if the strings are one edit away

    int absVal = abs(static_cast<int>(s1.size()) - static_cast<int>(s2.size()));

    if (absVal > 1){
        return false;
    }

    int i=0,j=0, cnt = 0;
    bool isLeft = false;
    while(i<s1.size() && j<s2.size()){
        if(s1.size()> s2.size()){
            if(s1[i]!=s2[j] && !isLeft){
                isLeft = true;
                ++i;
            }
            else if(s1[i]!=s2[j] && isLeft){
                return false;
            }
            else{
                ++i;
                ++j;
            }


        }else if(s1.size()< s2.size()){
            if(s1[i]!=s2[j] && !isLeft){
                isLeft = true;
                ++j;
            }
            else if(s1[i]!=s2[j] && isLeft){
                return false;
            }
            else{
                ++i;
                ++j;
            }           
        }else{
            if(s1[i]!=s2[j]){
                ++cnt;
                ++i;
                ++j;
            }
            else{   
                ++i;
                ++j;
            }

            if(cnt>1 || cnt==0)return false;
        }
    }

    return true;


}



int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << oneEditAway(s1, s2) << endl;
    return 0;
}