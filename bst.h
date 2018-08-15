#pragma once
#include<string>
#include<vector>

using namespace std;

class bst {	
private: 
	struct Node {
		string data;
		Node *left;
		Node *right;
	};
	Node* root;
	
	Node* getNode(string data);

public:
	bst();
	~bst();
	void ins(vector<string> info);
	void comparison(string s, string s1);
	void insert(vector<string> info);
	void inorder();
	void printInOrder(Node* ptr);
	void preorder();
	void printPreOrder(Node* ptr);
	void postorder();
	void printPostOrder(Node* ptr);
		
};