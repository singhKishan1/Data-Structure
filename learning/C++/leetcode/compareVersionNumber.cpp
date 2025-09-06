#include <iostream>
#include <vector>
using namespace std;

string removingLeadingZeros(string s){
    size_t pos = s.find_first_not_of('0');
    if(pos == string::npos)
        return "0";
    
    return s.substr(pos);
}

vector<int> convertVersionIntoInteger(string s){
    vector<int> v;
    string temp = "";
    
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='.'){
            if(temp.size()>0){
                // cout  << "\n"<< temp << endl;
                temp = removingLeadingZeros(temp);
                // cout  << temp << endl;
                v.push_back(stoi(temp));
            }
            
            temp = "";
        }else{
            temp += s[i];
        }
    }
    return v;
}

int solve(string version1, string version2){
    version1 += ".";
    version2 += ".";
    
    vector<int> v1 = convertVersionIntoInteger(version1);
    vector<int> v2 = convertVersionIntoInteger(version2);
    while(v1.size()>1 && v1[v1.size()-1]==0)
        v1.pop_back();
    
    while(v2.size()>1 && v2[v2.size()-1]==0)
        v2.pop_back();

    int i=0;
    while(i<v1.size() && i<v2.size()){
        if(v1[i]>v2[i])
            return 1;
        else if(v1[i]<v2[i])
            return -1;
        
        ++i;
    }

    if(i<v1.size())
        return 1;
    
    if(i<v2.size())
        return -1;
    
    return 0;
}

int main(){
    string s1, s2;
    cin>>s1 >> s2;

    // cout << stoi(s1) << endl;

    cout << solve(s1, s2) << endl;
    return 0;
}