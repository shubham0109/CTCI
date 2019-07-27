# include <iostream>
# include <stack>
using namespace std;

struct node {
	int data;
	node* next;
};

node* insertNodes(node* head, int num) {

	int i = 1;
	node* ptr = NULL;

	while (i <= num) {
		int data;
		cout << "Enter the data for node" << i << ": ";
		cin >> data;
		//node* newNode = (node*)malloc(sizeof(node));
		node* newNode = new node();
		newNode->data = data;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			ptr = head;
		}
		else {
			(ptr)->next = newNode;
			ptr = ptr->next;
		}
		i++;
	}
	return head;
}

void traverseNodes(node* head) {
	cout << "The linked list is: ";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int getLength(node* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

bool checkPalindromeHelper(node* head, stack <node*> st, int mid, bool* isOdd) {
	if (head == NULL) {
		return true;
	}

	if (mid > 0) {
		st.push(head);
		return checkPalindromeHelper(head->next, st, mid - 1, isOdd);
	}
	else {
		if (*isOdd == true) {
			*isOdd = false;
			return checkPalindromeHelper(head->next, st, mid, isOdd);
		}
		else {
			node* temp = st.top();
			st.pop();

			if (temp->data != head->data) {
				return false;
			}
			else {
				return checkPalindromeHelper(head->next, st, mid, isOdd);
			}
		}
	}
}

void checkPalindrome(node* head) {
	int length = getLength(head);
	int mid = length / 2;
	bool isOdd = false;

	if (length % 2 == 1)isOdd = true;
	
	stack <node*> st;
	bool isPalindrome = checkPalindromeHelper(head, st, mid, &isOdd);

	if (isPalindrome) {
		cout << "It's a Palindrome!!";
	}
	else {
		cout << "Not a Palindrome";
	}
}

int main() {
	node* head = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes: ";
	cin >> num_nodes;

	head = insertNodes(head, num_nodes);
	traverseNodes(head);

	checkPalindrome(head);
}