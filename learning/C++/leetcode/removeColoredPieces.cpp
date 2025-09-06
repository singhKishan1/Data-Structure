#include <iostream>
#include <string>

using namespace std;

bool solve(string s)
{

        int alice = 0, bob = 0;
        while (s.size()>2)
        {
            size_t foundA = s.find("AAA");
            if (s.size() > 2)
            {
                if (foundA != string::npos)
                {
                    ++alice;
                    s.erase(foundA, 1);
                }
            }

            size_t foundB = s.find("BBB");
            if (s.size() > 2)
            {
                
                if (foundB != string::npos)
                {
                    ++bob;
                    s.erase(foundB, 1);
                }
            }

            if(foundA == string::npos && foundB==string::npos)break;
            
        }

        if (alice > bob)
            return true;
        return false;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}