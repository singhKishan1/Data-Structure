
#include <iostream>
#include <vector>

using namespace std;

pair<int, bool> ciel_binarySearch(vector<int> &v, int ele)
{
    pair<int, bool> pd = {-1, false};
    int l = 0, h = v.size() - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (v[mid] == ele)
        {
            pd.first = mid;
            pd.second = true;
            return pd; // exact match found
        }
        else if (v[mid] < ele)
        {
            l = mid + 1; // move right
        }
        else
        {
            h = mid - 1; // move left
        }
    }

    // if not found, ceiling is at index l (if in range)
    if (l < (int)v.size())
    {
        pd.first = l;
        pd.second = false; // not exact match, but ceiling found
    }

    return pd;
}

int main(){
    vector<int>v={1,7};
    int ele=11;
    pair<int,bool>pd=ciel_binarySearch(v,ele);
    cout<<pd.first<<" "<<pd.second<<endl;
    return 0;
}