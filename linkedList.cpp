#include"linkedList.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
linkedList::linkedList()
:head(NULL),
tail(NULL){

}
linkedList::~linkedList() {

}


void linkedList::addNewMember(vector<string> data)
{
	Node* node1 = new Node();
	for (int i = 0; i < data.size(); i++) {
		if (i == 0) {
			node1->ani_name = data[i];
		}
		if (i == 1) {
			
			node1->lastname = data[i];
		}
		if (i == 2) {
			node1->firstname = data[i];
		}
		if (i == 3) {
			node1->species = data[i];
		}
		if (i == 4) {
			node1->dob = data[i];
		}
		else if(i>4){
			node1->treatments.push_back(data[i]);

		}
	}
	
	if (head == NULL) {
		head = node1;
		tail = node1;
	}
	else {
		tail->next = node1;
		tail = node1;
		tail->next = NULL;
	}
}

void linkedList::insert(vector<string> data) {
	Node *temp = new Node();
	
	Node* current = new Node();
	Node* previous = new Node();
	previous = head;
	bool found = 0;
	while (previous != NULL) {
		string fullname = previous->firstname + " " + previous->lastname;
		string name = data[2] + " " + data[1];
		if (data[0] == previous->ani_name &&  name == fullname) {
			current = previous->next;
			for (int i = 0; i < data.size(); i++) {
				if (i == 0) {
					temp->ani_name = data[i];
				}
				if (i == 1) {

					temp->lastname = data[i];
				}
				if (i == 2) {
					temp->firstname = data[i];
				}
				if (i == 3) {
					temp->species = data[i];
				}
				if (i == 4) {
					temp->dob = data[i];
				}
				else if (i > 4) {
					temp->treatments.push_back(data[i]);

				}
			}
			previous->next = temp;
			temp->next = current;

			found = 1;
			break;
		}previous = previous->next;
	}
	if (found == 0) {
		Node* t = new Node();
		Node* p = new Node();

		int i=0;
		
			t = head;
			while (t->next != NULL) {
				
				t = t->next;
			}
						
			p->ani_name = data[0];
			p->lastname = data[1];
			p->firstname = data[2];
			p->species= data[3];
			p->dob = data[4];
			if(i > 4) {
				p->treatments.push_back(data[i]);
			}
			t->next = p;
			tail = p;
			
			
			
	}
}

void linkedList::search(string an, string name) {
	Node* temp = new Node();
	temp = head;
	bool found = 0;
	
	while (temp!= NULL ) {
		string fullname = temp->firstname + " " + temp->lastname;
		
		if (an == temp->ani_name && name == fullname) {
			cout << an << " with owner " << name << " is found." << endl;
			cout << "Animal's name: " << temp->ani_name << endl;
			cout << "Animal's owner: " << fullname << endl;
			cout << "Species: " << temp->species << endl;
			cout << "Date-of-Birth: " << temp->dob << endl;
			cout << "Treatments: " << endl;
			for (int i = 0; i < temp->treatments.size(); i++) {
				cout << temp->treatments[i] << endl;
			}
			found = 1;
			break;
		}
		
		temp = temp->next;
	}
	if (found == 0) {
		cout << an << " with owner " << name << " is not found." << endl;
	}
}



void linkedList::modifyExisting(string an, string name) {
	Node *temp = new Node();
	temp = head;
	string newData;
	char usr = ' ';
	bool found = 0;

	while (temp != NULL) {
		string fullname = temp->firstname + " " + temp->lastname;

		if (an == temp->ani_name && name == fullname) {
			found = 1;
			break;
		}temp = temp->next;
	}
	if (found == 1) {
		cout << "Please input the name of the species: " << endl;
		cin >> temp->species;
			
			cout << "Please input the animal's date of birth: " << endl;
			cin >> temp->dob;
			
			cout << "Please input the animal's first treatment: " << endl;

			for (int i = 0; i < 12; i++) {
				cout << "Treatment #" << i << ": ";
				
				getline(cin, newData);
				if (newData == "q" || newData == "Q")
				{
					break;
				}
				temp->treatments.push_back(newData);

			}
			
		
	}
		
		if (found == 0) {
			cout << an << " with owner " << name << " is not found." << endl;
		}
		
}



void linkedList::deleteMember(string an, string name) {
	
	Node* current = new Node();
	Node* previous = new Node();
	Node* temp = new Node();
	Node* a = new Node();
	previous = head;
	
	int found = 0;
	while (previous != NULL) {
		string fullname= previous->firstname + " " + previous->lastname;;
		if (an == previous->ani_name && name == fullname) {
			found = 1;
			break;
		}
			previous = previous->next;
		
	}
	if (found == 1) {
		if (previous->next== NULL) {
			current = head;
			while (current != previous) {
				temp = current;
				current = current->next;
			}
			tail = temp;
			tail->next = NULL;
			delete current;
			cout << "The record has been deleted" << endl;
		}

		else if (previous == head) {
			temp = previous;
			previous = previous->next;
			head = previous;
			delete temp;
			cout << "The record has been deleted" << endl;
		}

		else {
			current = head;
			while (current != previous) {
				temp = current;
				current = current->next;
			}
			temp->next = current->next;
			delete current;
			cout << "The record has been deleted" << endl;
		}
	}
	else if (found == 0) {
		cout << an << " with owner " << name << " is not found." << endl;
	}

	
}

void linkedList::display() {
	Node *temp = new Node();
	temp = head;
	while (temp != NULL) {
		cout << "Animal's name: " << temp->ani_name << endl;
		cout << "Animal's owner: " << temp->firstname << " " << temp->lastname << endl;
		cout << "Animal's species: " << temp->species << endl;
		cout << "Date-of-birth: " << temp->dob << endl;
		cout << "Treatments: " << endl;
		for (int i = 0; i < temp->treatments.size(); i++) {
			cout << temp->treatments[i] << endl;
		}
		temp = temp->next;
		
	}
}
