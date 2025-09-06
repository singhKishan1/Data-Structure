#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> arr, int r1, int c1, int r2, int c2){
    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> prefSum;
    for(int i=0; i<m; ++i){
        vector<int> temp(n);
        for(int j=0; j<n; ++j){
            if(j==0)
                temp[j] = arr[i][j];
            else
                temp[j] = temp[j-1] + arr[i][j];
        }
        prefSum.push_back(temp);
    }

    for(int j=0; j<n; ++j){
        for(int i=0; i<m; ++i){
            if(i!=0)
                prefSum[i][j] += prefSum[i-1][j];
        }
    }



    cout <<"\nPref Sum\n";
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout << prefSum[i][j] << "\t";
        cout  << endl;
    }

    if(r1-1>=0 && c1-1>=0)  {
        cout << "Firs condition: ";
        return prefSum[r2][c2]-prefSum[r2][c1-1]-prefSum[r1-1][c2];
    }
    else if(r1-1>=0){
        cout << "2nd condition: ";
        return prefSum[r2][c2]-prefSum[r1-1][c2];}
    else if(c1-1>=0){
        cout << "3rd condition: ";
        return prefSum[r2][c2]-prefSum[r2][c1-1];
    }
    cout << "last condition: ";
    return prefSum[r2][c2];
}


/*Main Function*/
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cin>>arr[i][j];
    }

    cout << "Enter ranges:\n";
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    cout << solve(arr, r1, c1, r2, c2) << endl;
    return 0;
}