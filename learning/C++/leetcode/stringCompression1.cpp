#include <iostream>
#include <vector>

using namespace std;

void solve(vector<char> arr)
{
    int n = arr.size();
    int i = 0;

    while (i < n)
    {
        char current = arr[i];
        int count = 1;
        int j = i + 1;
        while (j < n && arr[j] == current)
        {
            arr[j] = '\0';
            count++;
            j++;
        }

        if (count > 1 && i + 1 < n)
        {
            string tmpStr = to_string(count);
            cout << "Count: " << tmpStr << endl;
            for (int k = 0; k < tmpStr.size(); ++k)
            {
                arr[i + 1 + k] = tmpStr[k];
            }
            count = 0;
        }
        i = j;
    }

    for (int i = 0; i < n;)
    {
        if (arr[i] == '\0')
        {
            arr.erase(arr.begin() + i);
        }
        else
        {
            i++;
        }
    }

    cout << "Compressed String: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(arr);
    return 0;
}

// a b b b b x x x x x x x x x x x x b b
//  a b b c c