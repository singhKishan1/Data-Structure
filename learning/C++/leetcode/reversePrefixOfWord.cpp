#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*Return the solution which are explain on leetCode.*/
string solve(string word, char ch){
    int idx = word.find(ch);
    if(idx <0)
        return word;
    
    reverse(word.begin(), word.begin()+idx+1);
    return word;
}

/*Main Function*/
int main(){
    string word;
    cin>>word;
    char ch;
    cin>>ch;

    cout << solve(word, ch) << endl;
    return 0;
}