# include <iostream>
# include <map>
using namespace std;

struct node {
	int data;
	node* next;
	node(int d): data{d}, next{NULL}{}
};

node* insertNodes(node* head, int num) {

	int i = 1;
	node* ptr = NULL;

	while (i <= num) {
		int data;
		cout << "Enter the data for node" << i << ": ";
		cin >> data;
		//node* newNode = (node*)malloc(sizeof(node));
		node* newNode = new node(data);
		//newNode->data = data;
		//newNode->next = NULL;

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

void make_loop(node* head) {
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	
	temp->next = head->next->next;
}

int getLength(node* head) {
	int len = 0;
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

node* loopDetection(node* head) {
	map <node*, bool> mp;
	
	while (head != NULL) {
		if (mp.find(head) == mp.end()) {
			mp[head] = true;
			head = head->next;
		}
		else {
			return head;
		}
	}

	return NULL;
}

node* loopDetectionTwoPointers(node* head) {
	node* fast_ptr = head;
	node* slow_ptr = head;

	fast_ptr = fast_ptr->next->next;
	slow_ptr = slow_ptr->next;

	while (fast_ptr != slow_ptr) {
		if (fast_ptr && fast_ptr->next)fast_ptr = fast_ptr->next->next;
		if (slow_ptr)slow_ptr = slow_ptr->next;
	}

	fast_ptr = head;

	while (fast_ptr != slow_ptr) {
		fast_ptr = fast_ptr->next;
		slow_ptr = slow_ptr->next;
	}

	return fast_ptr;
}

int main() {
	node* head = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes: ";
	cin >> num_nodes;

	head = insertNodes(head, num_nodes);
	make_loop(head);

	node* loop_node = loopDetection(head);

	if (!loop_node) {
		cout << "No Loop Detected\n";
	}
	else {
		cout << "Loop detected at: " << loop_node->data << endl;
	}

	loop_node = loopDetectionTwoPointers(head);
	if (!loop_node) {
		cout << "No Loop Detected\n";
	}
	else {
		cout << "Loop detected at: " << loop_node->data << endl;
	}
}