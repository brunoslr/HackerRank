#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//Insert Node at a given position in a linked list
//head can be NULL
//First element in the linked list is at position 0
//Node is defined as
struct Node
{
	int data;
	struct Node *next;
};

struct node
{
	int data;
	node* left;
	node* right;
};

int height(node * root) {
	if (root == NULL) {
		return -1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}

}

void preOrder(node *root) {


	cout << (root->data) << " ";

	if (root->left != nullptr)
		preOrder(root->left);

	if (root->right != nullptr)
		preOrder(root->right);


}


Node* InsertNth(Node *head, int data, int position)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = nullptr;

	if (position == 0)
	{
		temp->next = head;
		return temp;
	}

	Node *current = head;
	for (int i = 1; i< position; i++)
	{
		current = current->next;

	}
	temp->next = current->next;
	current->next = temp;

	return head;

}

