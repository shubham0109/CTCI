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

int length(node* head) {
	int l = 0;
	while (head != NULL) {
		l++;
		head = head->next;
	}
	return l;
}

node* sumListBackward(node* head1, node* head2) {
	int carry = 0;
	node* sum = NULL, * temp;

	while (head1 != NULL && head2 != NULL) {
		int s = head1->data + head2->data + carry;
		int d = s % 10;
		carry = s / 10;

		node* newNode = new node();
		newNode->data = d;
		newNode->next = NULL;

		if (sum == NULL) {
			sum = newNode;
			temp = sum;
		}
		else {
			temp->next = newNode;
			temp = temp->next;
		}

		head1 = head1->next;
		head2 = head2->next;
	}

	while (head1 != NULL) {
		int s = head1->data + carry;
		int d = s % 10;
		carry = s / 10;

		node* newNode = new node();
		newNode->data = d;
		newNode->next = NULL;

		if (sum == NULL) {
			sum = newNode;
			temp = sum;
		}
		else {
			temp->next = newNode;
			temp = temp->next;
		}

		head1 = head1->next;
	}

	while (head2 != NULL) {
		int s = head2->data + carry;
		int d = s % 10;
		carry = s / 10;

		node* newNode = new node();
		newNode->data = d;
		newNode->next = NULL;

		if (sum == NULL) {
			sum = newNode;
			temp = sum;
		}
		else {
			temp->next = newNode;
			temp = temp->next;
		}

		head2 = head2->next;
	}

	if (carry != 0) {
		node* newNode = new node();
		newNode->data = carry;
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
	}

	return sum;
}


node* sumListForward(node* head1, node* head2, int &carry) {
	node* sum = NULL;

	if (head1 == NULL && head2 == NULL) {
		return NULL;
	}

	int s = 0;
	if (head1)s += head1->data;
	if (head2)s += head2->data;

	if (head1 != NULL) {
		head1 = head1->next;
	}
	
	if (head2 != NULL) {
		head2 = head2->next;
	}

	sum = sumListForward(head1, head2, carry);
	s += carry;

	node* newNode = new node();
	newNode->data = s % 10;
	newNode->next = sum;

	sum = newNode;
	carry = s / 10;

	return sum;
}

int main() {
	node* head1 = NULL, *head2 = NULL;
	int num_nodes;

	cout << "Enter the no. of nodes for 1st number: ";
	cin >> num_nodes;

	head1 = insertNodes(head1, num_nodes);

	cout << "Enter the no. of nodes for 2nd number: ";
	cin >> num_nodes;

	head2 = insertNodes(head2, num_nodes);
	
	traverseNodes(head1);
	traverseNodes(head2);
	
	node* sum = sumListBackward(head1, head2);
	traverseNodes(sum);

	int len1 = length(head1);
	int len2 = length(head2);

	if (len1 > len2) {
		int rem = len1 - len2;
		while (rem--) {
			node* temp = new node();
			temp->data = 0;
			temp->next = head2;
			head2 = temp;
		}
	}
	else if (len2 > len1) {
		int rem = len2 - len1;
		while (rem--) {
			node* temp = new node();
			temp->data = 0;
			temp->next = head1;
			head1 = temp;
		}
	}

	int carry = 0;
	sum = sumListForward(head1, head2, carry);
	if (carry > 0) {
		node* newNode = new node();
		newNode->data = carry;
		newNode->next = sum;
		sum = newNode;
	}
	traverseNodes(sum);
}