#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &arr){
	
	vector<int> v;
	for(int i=0; i<arr.size(); ++i){
		int val = arr[i];
		if(val>=0)
			v.push_back(val);
		else if(val<0){
			bool isExploded = false;
			while(!v.empty() && v.back()>0){
				if(abs(v.back())>abs(val)){
					isExploded = true;
					break;
				}else if(abs(v.back())==abs(val)){
					v.pop_back();
					isExploded = true;
					break;
				}else if(abs(v.back())<abs(val)){
					v.pop_back();
				}
			}
			
			if(!isExploded)
				v.push_back(val);		

		}
	}



	for(int i=0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

}

int main(){
	vector<int> v = {-5, 5, -10};
	solve(v);
	return 0;
}
