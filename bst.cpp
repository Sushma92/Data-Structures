
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include"bst.h"

using namespace std;
int found;
bool foundLeft, foundRight;

bst::bst()

	:root(NULL)
	 {
}


bst::~bst() {
}


void bst::comparison(string s, string s1) {
	string str1 = s;
	string str2 = s1;
	int x = str1.compare(str2);
	foundLeft = 0;
	foundRight = 0;
	//cout << str1 << "  " << str2 << endl;
	//cout << x << endl;
	if (x == 0) {
		foundLeft = 1;
	}
	else if (x < 0) {
		foundLeft = 1;
	}
	if (x > 0) {
		foundRight = 1;
	}	
}



bst::Node* bst::getNode(string data)
{
	Node* newData = new Node();
	newData->data = data;
	newData->left = NULL;
	newData->right = NULL;
	return newData;
}



void bst::insert(vector<string> info) {
	ins(info);
}

void bst::ins(vector<string> info) {
	
	
	for (int i = 0; i < info.size(); i++) {
		found = 0;
		if (root == NULL) {
			root = getNode(info[i]);

		}
		else {
			Node* temp = root;
			while (!found) {
				comparison(info[i], temp->data);
				if (foundRight == 1) {
					if (temp->right != NULL) {
						temp = temp->right;
					}
					else {
						temp->right = getNode(info[i]);
						foundRight = 0;
						found = 1;
						temp = root;
					}

					
				}
				else if (foundLeft == 1) {
					if (temp->left != NULL) {
						temp = temp->left;
					}
					else {
						temp->left = getNode(info[i]);
						foundLeft = 0;
						found = 1;
						temp = root;
					}
				}
			}

			
			
		}
	}
			
			

}




void bst::inorder() {
	printInOrder(root);
}

void bst::preorder() {
	printPreOrder(root);
}

void bst::postorder() {
	printPostOrder(root);
}

void bst::printInOrder(Node* ptr) {
	
	if (root == NULL) {
		cout << "Empty" << endl;

	}
	
	else if(root != NULL) {
		
		if (ptr->left != NULL) {
			printInOrder(ptr->left);
		}
		cout << ptr->data << endl;
		if (ptr->right != NULL) {
			printInOrder(ptr->right);
		}
		
	}
	
}

void bst::printPreOrder(Node* ptr) {
	if (root == NULL) {
		cout << "Empty";

	}

	else if (root != NULL) {
		cout << ptr->data << endl;
		if (ptr->left != NULL) {
			printPreOrder(ptr->left);
		}
		
		if (ptr->right != NULL) {
			printPreOrder(ptr->right);
		}

	}
}

void bst::printPostOrder(Node* ptr) {
	if (root == NULL) {
		cout << "Empty";

	}

	else if (root != NULL) {
		if (ptr->left != NULL) {
			printPostOrder(ptr->left);
		}
		
		if (ptr->right != NULL) {
			printPostOrder(ptr->right);
		}
		cout << ptr->data << endl;
	}
}
