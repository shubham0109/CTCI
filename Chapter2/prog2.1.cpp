# include <iostream>
# include <map>

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

void removeDuplicates1(node* head) {
	map <int, bool> mp;

	node* temp = head, *prev = NULL;
	while (head != NULL) {
		if (!mp[head->data]) {
			mp[head->data] = true;
			prev = head;
			head = head->next;
		}
		else {
			prev->next = head->next;
			free(head);
			head = prev->next;
		}
	}
}

void removeDuplicates2(node* head) {
	
	node* temp = head;

	while (temp != NULL) {
		node* second_ptr = temp->next;
		node* prev = temp;
		while (second_ptr != NULL) {
			if (second_ptr->data == temp->data) {
				prev->next = second_ptr->next;
				free(second_ptr);
				second_ptr = prev->next;
			}
			else {
				prev = second_ptr;
				second_ptr = second_ptr->next;
			}
		}
		temp = temp->next;
	}
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

	// remove duplicates in the linked list
	// Method1: Use a hash map. Time:O(N). Space:O(N).
	
	removeDuplicates1(head);
	cout << "After removal of duplicates(method1): " << endl;
	traverseNodes(head);
	
	// Method2: Not using any buffer. Time:O(N^2). Space:O(1).
	/*
	removeDuplicates2(head);
	cout << "After removal of duplicates(method2): " << endl;
	traverseNodes(head);
	*/
}