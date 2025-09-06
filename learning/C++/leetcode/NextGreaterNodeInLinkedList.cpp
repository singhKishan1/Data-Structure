#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Node{
	public:
		int val;
		Node* next;

		Node(int value){
			val = value;
			next = NULL;
		}
};


class Solution{

	public:
		Node* head = NULL;

		Node* insertion(int val){
		
			if(head==NULL){
				return head = new Node(val);
			}

			Node* temp = head;
			while(temp->next != NULL) temp = temp->next;

			temp->next = new Node(val);
			return head;
		
		}
		
		Node* reverseList(Node* head){
			Node* prev=NULL;
			Node* curr = head;
			Node* nextPtr = NULL;

			while(curr!=NULL){
				nextPtr = curr->next;
				curr->next = prev;

				prev = curr;
				curr = nextPtr;
			}

			return prev;
		}

		void displayList(Node* head){
			while(head!=NULL){
				cout << head->val << " ";
				head = head->next;
			}
			cout << endl;
		}

		vector<int> nextLargerNodes(ListNode* head) {
			stack<Node*> st;
			head = reverseList(head);
			vector<int> ans;
			while(head!=NULL){
			
				while(!st.empty() && st.top()->val<= head->val)st.pop();

				ans.push_back(st.empty() ? -1 : st.top()->val);
				st.push(head);
				head = head->next;
			}		

			return ans;
    		}
};



int main(){

	return 0;
}
