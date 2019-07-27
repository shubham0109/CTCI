# include <iostream>
# include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int d) : data{ d }, next{ nullptr } { }
};

/*
Node* insertNodes(Node* head, int num) {

	int i = 1;
	Node* ptr = NULL;

	while (i <= num) {
		int data;
		cout << "Enter the data for node" << i << ": ";
		cin >> data;
		//node* newNode = (node*)malloc(sizeof(node));.

		Node* newNode = new Node();
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
*/
void traverseNodes(Node* head) {
	cout << "The linked list is: ";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int getLength(Node* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

Node* findIntersection(Node* head1, Node* head2) {
	if (head1 == NULL || head2 == NULL) {
		return NULL;
	}
	int len1 = getLength(head1);
	int len2 = getLength(head2);

	Node* large, * small;

	if (len1 > len2) {
		large = head1;
		small = head2;
	}
	else {
		large = head2;
		small = head1;
		swap(len1, len2);
	}

	while (large && len1 != len2) {
		large = large->next;
		len1--;
	}

	while (large != NULL) {
		if (large == small) {
			return large;
		}
		else {
			large = large->next;
			small = small->next;
		}
	}

	return NULL;
}

int main() {
	/*node* head1 = NULL, *head2 = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes for list 1: ";
	cin >> num_nodes;
	head1 = insertNodes(head1, num_nodes);

	cout << "Enter the no. of nodes for list 2: ";
	cin >> num_nodes;
	head2 = insertNodes(head2, num_nodes);
	*/

	Node* list1 = new Node(3);
	list1->next = new Node(6);
	list1->next->next = new Node(9);
	list1->next->next->next = new Node(12);
	list1->next->next->next->next = new Node(15);
	list1->next->next->next->next->next = new Node(18);

	Node* list2 = new Node(7);
	list2->next = new Node(10);
	list2->next->next = list1->next->next->next;
	
	traverseNodes(list1);
	traverseNodes(list2);

	Node* intersection_node = findIntersection(list1, list2);

	if (!intersection_node) {
		cout << "No intersection found\n";
	}
	else {
		cout << "The intersection node is: " << intersection_node->data << endl;
	}

	return 0;
}