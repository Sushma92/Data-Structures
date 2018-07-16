#pragma once
#include<string>
#include<vector>

using namespace std;
class linkedList {
public:
	linkedList();
	~linkedList();
	
	void insert(vector<string> data);
	void addNewMember(vector<string> data);
	void modifyExisting(string an, string name, string sp, string db, vector<string> trt);
	void deleteMember(string an, string name);

	void display();

	void search(string an, string name);
private:
	struct Node {
		string ani_name;
		string lastname;
		string firstname;
		string species;
		string dob;
		vector<string> treatments;

		Node* next;
	};
	Node newNode;

	Node *head, *tail;

};
