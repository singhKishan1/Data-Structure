#include <iostream>
#include <vector>
using namespace std;

int solve(int val, vector<vector<int>> &arr, int i, int j){
    int m = arr.size(), n = arr[0].size();
    if(j>n || j<0)
        return -1;
    
    if(i==m)
        return j;
    
    if(val>0 && arr[i][j]<0 && arr[i][j-1]){
        return -1;
    }else if (val < 0 && arr[i][j]>0 && arr[i][j+1]<0){
        return -1;
    }
    
    if(val>0){
        return solve(arr[i][j], arr, i+1, j+1);
    }else{
        return solve(arr[i][j],arr, i+1, j-1);  
    }
}

void whereWillBallFall(vector<vector<int>> arr){
    for(int i=0; i<arr.size(); ++i){
        if(arr[0][i]>0)
            cout << solve(arr[0][i], arr, 1, i+1) << "\t";
        else
            cout << solve(arr[0][i], arr, 1, i-1) << "\t";
    }
}


/*Main Function*/
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter element:\n";
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>matrix[i][j];


    whereWillBallFall(matrix);
    return 0;
}