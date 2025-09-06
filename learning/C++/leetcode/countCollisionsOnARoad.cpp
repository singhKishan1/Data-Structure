#include <iostream>
#include <vector>

using namespace std;

int solve(string s){
	int cnt =  0;
	vector<char> st;
	for(int i=0; i<s.size(); ++i){
		char ch = s[i];
		if(ch=='R')
			st.push_back(ch);
		else if(ch=='S'){
			while(!st.empty() && st.back()!='S'){
				++cnt;
				st.pop_back();
			}
			st.push_back(ch);
		}else if(ch=='L'){
		
			if(!st.empty() && st.back()=='R'){
				cnt += 2;
				st.pop_back();
				while(!st.empty() && st.back()!='S'){
					++cnt;
					st.pop_back();
				}
				
				if(st.empty())
					st.push_back('S');

			}else if(!st.empty() && st.back()=='S'){
				++cnt;
			}
		}
	}

	return cnt;
}

int main(){
	string s;
	while(cin >> s){
		cout << solve(s) << endl;
	}
	return 0;
}
