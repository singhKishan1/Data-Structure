#include <iostream>
#include <string>
using namespace std;

/**
 * Return the number word need to add in given string to make valid string.
*/
int minAddToMakeValidString(string str){
    int i=0,j=0,count=0;
    string s="abc";
    while(i<str.size() || j%3!=0){
        if(str[i]!=s[j%3]){
            ++count,++j;
        }else if(str[i]==s[j%3]){
            ++i,++j;
        }
    }
    return count;
}

/**
 * Main Function
*/
int main(){

    string s;
    cin>>s;

    cout << minAddToMakeValidString(s) << endl;
    return 0;
}