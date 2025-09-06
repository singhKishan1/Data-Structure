#include <iostream>
#include <string>

using namespace std;

// Function to decode a string
// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the length of the string
// The function uses recursion to decode the string
// string solve(string &s, int &i){
//     string result = "";
//     string num="";
//     while(i<s.size()){
//         if(s[i]>='a' && s[i]<='z'){
//             result += s[i];
//             ++i;
//         }else if(s[i]>='0' && s[i]<='9'){
//             num += s[i];
//             ++i;
//         }else if(s[i]=='['){
//             ++i;
//             string temp = solve(s, i);
//             int n = stoi(num);
//             for(int j=0; j<n;  ++j){
//                 result += temp;
//             }
//             num = "";
//         }else if(s[i]==']'){
//             ++i;
//             break;
//         }
//     }

//     return result;
// }


string solve(string &s, int &i){
    string result = "", num="";

    while(i<s.size()){
        if(s[i]>='a' && s[i]<='z'){
            result += s[i];
            ++i;
        }else if(s[i]>='0' && s[i]<='9'){
            num += s[i];
            ++i;
        }else if(s[i]=='['){
            ++i;
            string temp = solve(s, i);
            int n = stoi(num);
            while(n>0){
                result += temp;
                --n;
            }
            num="";
        }else if(s[i]==']'){
            ++i;
            break;
        }
    }

    return result;
}


int main(){
    cout << "Enter string:";
    string s;
    cin>>s;

    int i=0;
    cout << solve(s, i) << endl;
    return 0;
}