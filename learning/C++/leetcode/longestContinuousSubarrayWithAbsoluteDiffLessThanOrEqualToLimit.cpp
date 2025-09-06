#include <iostream>
#include <vector>
#include <map>


using namespace std;

// typedef pair<int, int> pd;

// void printStack(stack<pd> s){
//     cout << "printing stack: " << endl;
//     while(!s.empty()){
//         cout << s.top().first << " --> " << s.top().second <<endl;
//         s.pop(); 
//     }
//     cout << endl;
// }

// int solve(vector<int> &v, int limit){
//     stack<pd> mn, mx;
//     int ans = 0;
//     for(int i=0; i<v.size(); ++i){
//         while(mn.size()>0 && mn.top().first>v[i])
//             mn.pop();
        
//         mn.push({v[i],i});

//         while(mx.size()>0 &&  mx.top().first<v[i])
//             mx.pop();
        
//         mx.push({v[i],i});


//         if(abs(mx.top().first-mn.top().first)>limit){
//             if(mx.size()>mn.size())
//                 mx.pop();
//             else if(mn.size()>mx.size()){
//                 mn.pop();
//             }
//         }

//         if(mx.size()>mn.size()){
//             ans = max(ans, i-mn.top().second);
//         }else{
//             ans = max(ans, i-mx.top().second);
//         }

//     }

//     printStack(mn);
//     printStack(mx);


//     cout << "Answer: ";
//     return ans;
// }


int solve(vector<int> &v, int limit){

    map<int, int> mp;
    int j=0,i=0;
    int ans = 0,n=v.size();
    while(j<n){
        mp[v[j]]++;

        int lowVal = mp.begin()->first;
        int highVal = mp.rbegin()->first;



        while(mp.size()>0 && (abs(lowVal-highVal)>limit)){
            mp[v[i]]--;
            if(mp[v[i]]==0)
                mp.erase(v[i]);

            ++i;

            if(mp.size()>0){
                lowVal = mp.begin()->first;
                highVal = mp.rbegin()->first;
            }
        }

        if(mp.size()>0){
            lowVal = mp.begin()->first;
            highVal = mp.rbegin()->first;

            if(abs(lowVal-highVal)<=limit)
                ans = max(ans, j-i+1);
        }
        

        ++j;
    }
    
    return ans;

}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)cin>>v[i];

    int limit;
    cin>>limit;
    cout << solve(v,limit) << endl;
    return 0;
}