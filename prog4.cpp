#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<sstream>
#include"bst.h"

using namespace std;

bst* tree = new bst;
vector<string> list;
int main() {
	ifstream f;
	f.open("names.dat", ios::in | ios::app);
	if (f.is_open()) {
		string str;
		while (!f.eof()) {
			getline(f, str);
			string buf;
			stringstream ss(str);
			vector<string> tokens;
			if (str != "")
			{
				while (ss >> buf) {
					tokens.push_back(buf);
					list.push_back(buf);
				}
				//for (int i = 0; i < tokens.size(); i++)
					//cout << tokens[i] << endl;
				tree->insert(tokens);
				
			}
		}
	}
	int uin = 0;
	do {
		cout << "Main Menu:\n";
		cout << "1. View Data\n";
		cout << "2. Inorder Traversal\n";
		cout << "3. Preorder Traversal\n";
		cout << "4. Postorder Traversal\n";
		cout << "5. Exit\n";
		cin >> uin;

		switch (uin) {
		case 1:
		{
			for (int i = 0; i < list.size(); i++)
				cout << list[i] << endl;
			break;
		}

		case 2:
		{
			tree->inorder();
			break;
		}

		case 3:
		{
			tree->preorder();
			break;
		}

		case 4:
		{
			tree->postorder();
			break;
		}

		default:
			break;

		}

	} while (uin != 5);
	
	getchar();
	f.close();
	return 0;
}