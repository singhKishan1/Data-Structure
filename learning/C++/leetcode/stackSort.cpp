#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the right place in a sorted stack
void insertAtRightPlace(stack<int> &st, int &x)
{

    if (st.empty() || st.top() > x)
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtRightPlace(st, x);
    st.push(temp);
}

// Function to sort a stack using another stack
void sortStack(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int x = st.top();
    st.pop();
    sortStack(st);
    insertAtRightPlace(st, x);
    return;
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    }

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}