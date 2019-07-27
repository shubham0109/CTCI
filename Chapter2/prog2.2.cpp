# include <iostream>
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

node* findElement(node* head, int k) {
	node* slow_ptr = head;
	node* fast_ptr = head;

	while (fast_ptr != NULL && k--) {
		fast_ptr = fast_ptr->next;
	}

	if (k > 0) {
		cout << "Invalid access" << endl;
		return NULL;
	}

	while (fast_ptr != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}

	return slow_ptr;
}

int main() {
	node* head = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes: ";
	cin >> num_nodes;

	head = insertNodes(head, num_nodes);
	traverseNodes(head);

	// returns the kth element from the end
	int k;
	cout << "Enter the value of k: ";
	cin >> k;
	node* element_node = findElement(head, k);
	if (element_node == NULL) {
		cout << "Wrong value of k" << endl;
	}
	else {
		cout << "The " << k << "th element from the end is: " << element_node->data;
	}	
}