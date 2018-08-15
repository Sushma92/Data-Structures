#include"q.h"
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;


q::q()
:total_transactions(0),
customers(0),
avg(0.0),front(NULL), rear(NULL){

}

q::~q() {

}

void q::enterQueue(vector<string> data) {
	Node* n = new Node();
	for (int i = 0; i < data.size(); i++) {

		if (i % 2 == 0) {
			n->ntransactions = data[i];
		}
		else {
			n->cname = data[i];
		}
	}
	if (front == NULL) {
		front = n;
		rear = n;
	}
	else {
		rear->next = n;
		rear = n;
		rear->next = NULL;
	}
}

void q::enq(Node* t) {
	if (t->cname == "no_cust") {
		cout << "No more customers." << endl;
	}
	else {
		bank.push(t->cname);
	cout << "Customer: " << t->cname << " arrives with " << t->ntransactions << " transactions." << endl;
	}

}

void q::transactions(Node* t) {
	count = t->ntransactions;
	total_transactions += stoi(count);
	customers += 1;
	for (int j = stoi(count); j > 0; j--) {
		cout << "Current customer " << t->cname << " now has " << j << " transactions remaining." << endl;

	}
	
}


void q::deq(Node * t)
{
	cout << "Customer " << t->cname << " has completed all his/her transactions and has exited the bank." << endl;
	
	
}



void q::display() {
	Node* temp = new Node();
	Node* prev = new Node();
	temp = front;
		
	while (temp->cname!= "no_cust"  && temp!= NULL) {
		enq(temp);
		cout << "Customer " << temp->cname << " with " << temp->ntransactions << " transactions is now the current customer handled by the teller." << endl;
		transactions(temp);
		deq(temp);
		temp = temp->next;
		
		
	}

	avg = (total_transactions) / customers;

	if (front == rear == NULL) {
		cout << "The total ttransactions: " << total_transactions << endl;
		cout << "The total number of customers: " << customers << endl;
		cout << "The average number of transactions: " << avg << endl;
	}
}



