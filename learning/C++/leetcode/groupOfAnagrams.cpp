#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/**
 * following bruteforce approach using.... 
bool isAnagram(string a, string b){
	if(a.size()!=b.size()) return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a==b;
}

vector<vector<string>> groupOfAnagrams(vector<string> &v){
	int n=v.size();
	vector<bool>used(n, false);
	vector<vector<string>>answer;
	for(int i=0; i<n; ++i){

		if(used[i])continue;

		vector<string>group;
		used[i]=true;
		group.push_back(v[i]);

		for(int j=i+1; j<n; ++j){
			if(!used[j] && isAnagram(v[i], v[j])){
				group.push_back(v[j]);
				used[j]=true;
			}
		}

		answer.push_back(group);
	}

	return answer;
}

*/

vector<vector<string>> groupOfAnagrams(vector<string> &strs){
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> mp;
	for(string s: strs){
		string key = s;
		sort(key.begin(), key.end());
		mp[key].push_back(s);
	}

	for(auto &x:mp){
		ans.push_back(x.second);
	}

	return ans;
}


int main(){
	int n;
	cout<<"Enter size:";
	cin>>n;

	cout << "Enter elements in arr:";
	vector<string>v(n);
	for(int i=0;i<n;++i)cin>>v[i];

	
	auto answer = groupOfAnagrams(v) ;
	cout <<"Answer:"<<endl;
	for(auto &grp: answer){
		for(auto &word: grp){
			cout << word << " ";
		}
		cout << endl;
	}

	return 0;
}