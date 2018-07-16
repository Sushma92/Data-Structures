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
	temp = head;
	Node* current = new Node();
	Node* previous = new Node();
	bool found = 0;
	while (temp != NULL) {
		string fullname = temp->firstname + " " + temp->lastname;
		string name = data[2] + " " + data[1];
		if (data[0] == temp->ani_name &&  name == fullname) {
			current = temp->next;
			previous = temp;
			for (int i = 0; i < data.size(); i++) {
				if (i == 0) {
					previous->next->ani_name = data[i];
				}
				if (i == 1) {

					previous->next->lastname = data[i];
				}
				if (i == 2) {
					previous->next->firstname = data[i];
				}
				if (i == 3) {
					previous->next->species = data[i];
				}
				if (i == 4) {
					previous->next->dob = data[i];
				}
				else if (i > 4) {
					previous->next->treatments.push_back(data[i]);

				}
			}
			previous->next->next = current;
			found = 1;
			break;
		}temp = temp->next;
	}
		if(found == 0) {
			addNewMember(data);
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

void linkedList::modifyExisting(string an, string name, string sp, string db, vector<string> trt) {
	Node *temp = new Node();
	temp = head;
	string newData;
	char usr = ' ';
	bool found = 0;

	while (temp != NULL) {
		string fullname = temp->firstname + " " + temp->lastname;

		if (an == temp->ani_name && name == fullname) {
			ofstream f;
			f.open("animals.dat", ios::out);
			if (f.is_open()) {
				cout << "Please input the name of the species: " << endl;
				cin >> temp->species;
				f << temp->species;
				cout << "Please input the animal's date of birth: " << endl;
				cin >> temp->dob;
				f << temp->dob;
				cout << "Please input the animal's first treatment: "<< endl;
				
					for (int i = 1; i < 11;) {
						cout << endl << "Treatment #" << i << ": ";
						getline(cin, newData);
						if (newData == "q" || newData == "Q")
						{
							break;
						}
						trt.push_back(newData);
					
				}
				f.close();
			}
		}
		temp = temp->next;
	}
		if (found == 0) {
			cout << an << " with owner " << name << " is not found." << endl;
		}
		
}



void linkedList::deleteMember(string an, string name) {
	
	Node* current = new Node();
	Node* previous = new Node();
	previous = head;
	current = previous->next;
	
	while (previous != NULL) {
		string fullname;
		while (an != previous->ani_name && name != fullname) {
			fullname = previous->firstname + " " + previous->lastname;
			previous = previous->next;
		}
	}

		if (previous->next = NULL) {
			current = head;
			while (current->next != NULL) {
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			delete current;
			cout << "The record has been deleted" << endl;
		}


		else if (previous = head) {
			current = previous;
			previous = previous->next;
			delete current;
			cout << "The record has been deleted" << endl;
		}

		else {
			previous = current;
			current = current->next;
			previous->next = current->next;
			delete current;
			cout << "The record has been deleted" << endl;
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

