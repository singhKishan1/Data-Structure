#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> v){
    for(auto x:v)
        cout << x << "\t";
    cout << endl;
}

vector<int> solve(vector<int>nums1, vector<int> nums2, vector<vector<int>>queries){
    vector<int> ans;
    for(int i=0;i<queries.size(); ++i){
        int sum  = -1;
        for(int j=0; j<nums1.size(); ++j){
            if(nums1[j]>queries[i][0] && nums2[j]>queries[i][1])
                sum = max(sum, nums1[j]+nums2[j]);
        }

        ans.push_back(sum);
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> nums1(n), nums2(n);
    for(int i=0; i<n; ++i)
        cin>>nums1[i];
    
    for(int i=0; i<n; ++i)
        cin>>nums2[i];


    int k;cin>>k;
    cout<< "Enter queries\n";
    vector<vector<int>> queries(k,vector<int>(2));

    for(int i=0; i<k; ++i)
        cin>>queries[i][0]>>queries[i][1];

    display( solve(nums1, nums2, queries));
    return 0;
}