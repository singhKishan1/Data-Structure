#include <iostream>
#include <experimental/unordered_set>

using namespace std;

class Node{
	public:
		int value;
		Node* next;

		Node(int val){
			value = val;
			next = nullptr;
		}
};

Node* insertion(Node* head, int val){
	if(head==nullptr){
		return head = new Node(val);
	}

	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next;
	}

	temp->next = new Node(val);
	return head;
}


void display(Node* head){
	Node* temp = head;
	while(temp!=nullptr){
		cout << temp->value << "-->";
		temp = temp->next;
	}
	cout<<"X\n"<<endl;
}


// with O(n) space complexity
/*Node* intersectionOfTwoLinkedList(Node* head1, Node* head2){
	unordered_set<int> st;
	Node* temp1 = head1;
	while(temp1!=nullptr){
		st.insert(temp1->val);
		temp1 = temp1->next;
	}

	Node* newHead=nullptr;
	Node* tempNewHead=nullptr;
	Node* temp2 = head2;
	while(temp2 !=nullptr){
		if(st.find(temp2->val)!=st.end()){
			if(newHead==nullptr){
				newHead = new Node(temp2->val);
				tempNewHead = newHead;
			}

			tempNewHead->next = new Node(temp2->val);
			tempNewHead = tempNewHead->next;
		}

		temp2 = temp2->next;
	}

	return newHead;


}*/


Node* returnIntersection(Node* head1, Node* head2){
	while(head1 && head2 && head1!=head2){
		head1 = head1->next;
		head2 = head2->next;
	}

	return head1;
}


// with O(1) space complexity
Node* intersectionOfTwoLinkedList(Node* head1, Node* head2){
	int len1=0, len2=0;
	Node* temp1 = head1;
	Node* temp2 = head2;

	while(temp1){
		++len1;
		temp1 = temp1->next;
	}

	while(temp2){
		++len2;
		temp2 = temp2->next;
	}

	if(len1>len2){
		temp1=head1;
		while(temp1 && len1>len2){
			--len1;
			temp1 = temp1->next;
		}

		return returnIntersection(temp1, head2);
	}else{
		temp2 = head2;
		while(temp2 && len2>len1){
			temp2 = temp2->next;
			--len2;
		}

		return returnIntersection(temp2,head1);
	}

}




int main(){

	int arr[5]={1,2,3,4,5};
	Node* head = nullptr;
	for(int i=0; i<5;++i){
		head = insertion(head, arr[i]);
	}

	display(head);

}