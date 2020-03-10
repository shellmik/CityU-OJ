#include<iostream>
#include<stdio.h>
using namespace std;

class node
{
public:
	node(int, int);
	int weight;
	int distance;
	node* left;
	node* right;
};

node::node(int w, int d)
{
	weight = w;
	distance = d;
}

void construct(node* curr)
{
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	curr->left = new node(w1, d1);
	curr->right = new node(w2, d2);
	if (w1 == 0)
	{
		construct(curr->left);
	}
	if (w2 == 0)
	{
		construct(curr->right);
	}
	curr->weight = curr->left->weight + curr->right->weight;
}

bool evaluate(node* root)
{
	if (root->left == NULL || root->right == NULL){ return true;}
	if (root->left->weight * root->left->distance == root->right->weight * root->right->distance)
	{
		return (evaluate(root->left) && evaluate(root->right));
	}
	return false;
}

int main()
{
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	int T;
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++)
	{
		node* root = new node(0,0);
		construct(root);
		if (i != 0)
			printf("\n");
		if (evaluate(root)) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	//freopen_s(&stream, "output.txt", "w", stdout);
}