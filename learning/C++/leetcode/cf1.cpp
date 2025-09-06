#include <iostream>
#include <vector>
using namespace std;

string solve(vector<vector<int>> mtx)
{
    
    bool check = true;
    for(int c=0;  c<3; ++c){
        for(int r=1; r<mtx.size(); ++r)
            mtx[r][c] += mtx[r-1][c];
        

        if(mtx[mtx.size()-1][c]!=0){
            check =false;
            break;
        }
    }

    if(check)return "YES";
    else return "NO";

}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mtx;
    for (int i = 0; i < n; ++i)
    {
        vector<int> v(3);
        for (int j = 0; j < 3; ++j)
            cin >> v[j];

        mtx.push_back(v);
    }

    cout << solve(mtx) << endl;
    return 0;
}