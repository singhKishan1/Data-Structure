#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[5][5];
    int row = -1, col = -1;
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                row = i+1;
                col = j+1;
            }
        }
    }

    cout << abs(3-row)+abs(3-col) << endl;
    return 0;
}