#pragma once
#include<string>
#include<vector>
#include<queue>

using namespace std;
struct Node {
	string ntransactions;
	string cname;
	Node* next;

};
class q {
public:
	q();
	~q();
	void enterQueue(vector<string> data);
	void display();
	void enq(Node* t);
	void deq(Node* t);
	void transactions(Node* t);
private:

	int total_transactions, customers;
	float avg;
	queue<string> bank;
	string count;
	
	Node *front, *rear;

};