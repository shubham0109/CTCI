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

void partition_x(node* head, int x) {
	node* low = head;
	node* high = head;

	while (high != NULL && high->data < x) {
		high = high->next;
	}
	low = high;

	while (low != NULL) {
		if (low->data < x) {
			swap(high->data, low->data);
			while (high != NULL && high->data < x) {
				high = high->next;
			}
			low = high;
		}
		else {
			low = low->next;
		}
	}
}

int main() {
	node* head = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes: ";
	cin >> num_nodes;

	head = insertNodes(head, num_nodes);
	traverseNodes(head);

	int x;
	cout << "Enter the number to partition: ";
	cin >> x;

	partition_x(head, x);
	traverseNodes(head);
}