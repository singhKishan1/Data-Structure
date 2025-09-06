#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> p;
typedef pair<int, pair<string, int>> p2;


/*Split the string with spaces*/
vector<string> splitStringViaSpaces(string str){
    vector<string> splitedString;
    int i=0,n=str.size();
    string temp= "";
    while(i<n){
        if(str[i]!=' ')
            temp += str[i];
        else{
            if(temp.size()>0){
                splitedString.push_back(temp);
                temp = "";
            }
        }
        ++i;
    }

    /*For last word*/
    if(temp.size()>0)
        splitedString.push_back(temp);
    

    /*Printing splited strings*/
    cout <<"\nPrinting splited strings:\n";
    for(auto x:splitedString)
        cout << x << "\t";
    cout << endl;

    return splitedString;
}

/*Return the name of sender who have largest count of words messages.*/
string senderWithLargestWordCount(vector<string> messages, vector<string> senders){ 
    int n = messages.size();
    
    vector<vector<string>> modifiedMessage(n);
    for(int i=0; i<n; ++i){
        modifiedMessage[i] = splitStringViaSpaces(messages[i]);
    }

    map<string, int> mp;
    for(int i=0; i<n; ++i)
        mp[senders[i]] += modifiedMessage[i].size();
    
    
    cout << "\nPrinting frequency\n";
    for(auto x:mp)
        cout  << x.first << "\t--->\t" << x.second << endl;;


    priority_queue<p, vector<p>, greater<p>>pq;

    for(auto x:mp){
        pq.push({x.second, x.first});
    }

    priority_queue<p2> pq2;
    while(pq.size()){
        if(pq2.size()>0 && pq.top().first==pq2.top().second.second){
            pq2.push({pq.top().second.size(), {pq.top().second, pq.top().first}});
        }else{
            pq2.push({pq.top().second.size(), {pq.top().second, pq.top().first}});
        }

        pq.pop();
    }
    return pq2.top().second.first;
}

/*Main Function*/
int main(){
    int n;
    cin>>n;
    cout << "Enter messages in array:\n";
    vector<string> messages(n);
    for(int i=0; i<n; ++i){
        string temp;
        getline(cin, temp);
        messages[i] = temp;
    }

    cout << "\nEnter sender's name: \n";
    vector<string>senders(n);
    for(int i=0; i<n; ++i)
    
        getline(cin, senders[i]);
    
    cout << "\nResult is:\n" << senderWithLargestWordCount(messages, senders) << endl;
}