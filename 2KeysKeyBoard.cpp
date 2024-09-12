#include <iostream>


using namespace std;

int solve(int num){
	int  ans = 0 ;
	
	while(num>0){
		ans +=  1;
		if(num%2==1)
			++ans;

		num = num/2+num%2;
	}
	
	return  ans;

}

int main(){
	int n;
	cin>>n;

	cout << solve(n) << endl;
	return  0;
}
