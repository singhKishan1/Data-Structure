#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v){
    int n = v.size();
    int  cnt = 0;
    for(int  i=0; i<n; ++i){
        string s1 = to_string(v[i]);
        for(int j=i+1; j<n; ++j){
            string s2 = to_string(v[j]);
            if(s1.size()>s2.size()  && (s1.size()-s2.size())==1 && s1.find('0')>0){
                
                bool check =  false;
                for(int l=0; l<s1.size();++i){
                    if(s1[l]=='0'){
                        string temp = s1;
                        temp.erase(l,1);
                        if(temp==s2){
                            check = true;
                        }
                        break;
                    }
                }

                if(check==true){
                    ++cnt;
                }

            }else if(s2.size()>s1.size() && (s2.size()-s1.size())==1 && s2.find('0')>0){
                bool check = false;
                for(int l=0; l<s2.size(); ++l){
                    if(s2[l]=='0'){
                        string temp = s2;
                        temp.erase(l, 1);
                        if(temp==s1){                                    
                            check = true;
                        }
                        break;
                    }
                }

                if(check==true){
                    ++cnt;
                    break;
                }

            }else if(s1.size() == s2.size()){
                unordered_map<char, int>mp;
                for(auto x:s1){
                    mp[x]++;
                }

                bool digitMissed=false;
                for(auto x:s2){
                    if(mp.find(x)==mp.end()){
                        digitMissed = true;
                        break;
                    }else{
                        mp[x]--;
                        if(mp[x]==0)
                            mp.erase(x);
                    }
                }

                if(digitMissed==false){
                    
                    int misMatchCount =  0;

                    for(int l=0; l<s1.size(); ++l){
                        if(s1[l]!=s2[l])++misMatchCount;
                    }

                    if(misMatchCount<2)++cnt;
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)cin>>v[i];

    cout << solve(v) << endl;
    return 0;
}