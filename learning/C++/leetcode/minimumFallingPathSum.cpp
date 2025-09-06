#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Function for printing grid's element.*/
void displayGrid(vector<vector<int>> arr){
    cout << "\n Printing Grid's elements:\n";
    for(auto x: arr){
        for(auto y: x)
            cout << y << " ";
        cout << endl;
    }
}

/*Function return minimum sum from top to bottom*/
int minimumFallingPathSum(vector<vector<int>> arr){
    int n = arr.size(); 
    for(int i=1; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j-1>=0 && j+1<n){
                arr[i][j] += min(arr[i-1][j], min(arr[i-1][j-1], arr[i-1][j+1]));
            }else if(j+1<n){
                arr[i][j] += min(arr[i-1][j],arr[i-1][j+1]);
            }else if(j-1>=0){
                arr[i][j] += min(arr[i-1][j], arr[i-1][j-1]);
            }else
                arr[i][j] += arr[i-1][j];
        }
    }

    return *min_element(arr[n-1].begin(), arr[n-1].end());
}


/*Main Function*/
int main(){

    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin>>arr[i][j];
    }

    cout << minimumFallingPathSum(arr) << endl;

    return 0;
}