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

void deleteMiddleNode(node* ptr) {
	if (ptr == NULL || ptr->next == NULL) {
		cout << "Invalid node" << endl;
		return;
	}

	while (ptr->next->next != NULL) {
		ptr = ptr->next;
	}

	ptr->data = ptr->next->data;
	node* temp = ptr->next;
	ptr->next = NULL;
	free(temp);
}

int main() {
	int num;
	cout << "Enter the no. of nodes: ";
	cin >> num;

	node* head = NULL;

	// insert nodes into linked list
	head = insertNodes(head, num);

	// traverse the nodes
	traverseNodes(head);

	deleteMiddleNode(head->next);
	traverseNodes(head);

}