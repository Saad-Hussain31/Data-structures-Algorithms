#include <bits/stdc++.h>
//using namespace std;

struct Node {
public:
	int data;
	Node *next;
};

void push(Node **head_ref, int new_data) {
	Node *new_node  = new Node();
	new_node->data = new_data;
	new_node->next =  (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data) {
	Node *new_node = new Node(); //new rets address of new Node which is then stored in *new_node pointer.
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node **head_ref, int new_data) {
	Node *new_node  = new Node();
	Node *last = (*head_ref);
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	
	while (last->next != NULL) {
		last = last->next;
		return;
	}
	
	last->next = new_node;
	return;
}




void printList(Node *n) {
	while (n != NULL) {
	std::cout << n->data << "\n" ;
	n = n->next;
	}
}

/*void printAddOff(Node *n) {
	while (n!= NULL) {
	cout << &n->data << "\n";
	n = n->next;
	}
}
*/

int main() {

/*
	Node *head = NULL;
	Node *sec = NULL;
	Node *thd = NULL;

	head = new Node();
	sec = new Node();
	thd  = new Node();

	head->data = 1;
	head->next = sec;

	sec->data = 2;
	sec->next = thd;
	
	thd->data  = 3;
	thd->next  = NULL;
	
	printList(head);
	printAddOff(head);
	return 0;
*/
	Node *head = NULL;
	append(&head, 6);
	push(&head,7);
	push(&head,1);
	append(&head,4);
	insertAfter(head->next,8);
	std::cout<< "Created LinkedList is: "<< "\n";
	printList(head);
	return 0;
}

	
