#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<sstream>
#include "linkedList.h"

using namespace std;



int main() {
	ifstream f;
	ofstream o;
	linkedList* list = new linkedList();
	f.open("animals.dat", ios::in | ios::app);
	o.open("animals.dat", ios::out | ios::app);
	if (f.is_open()) {
		string str;
		while (!f.eof()) {
			getline(f, str);
			string buf;						
			stringstream ss(str);
			vector<string> tokens; 
			while (ss >> buf)
				tokens.push_back(buf);
				for(int i =0; i< tokens.size(); i++)
					cout << tokens[i];
			list->addNewMember(tokens);

		}

		int uin = 0;
		string usr;
		string an, name, sp, db;
		string newData;
		vector<string> trt;
		do {
			cout << "Main Menu:\n";
			cout << "1. Add new member record\n";
			cout << "2. Modify existing member record\n";
			cout << "3. Delete member record\n";
			cout << "4. Display all member records\n";
			cout << "5. Search for a particular member record\n";
			cout << "6. Exit\n";

			cin >> uin;
			if (o.is_open()) {
				switch (uin) {
				case 1:
				{

					cout << "Please input the animal's name: " << endl;
					cin >> newData;
					trt.push_back(newData);
					o << "\n" << newData << "  ";
					cout << "Pleaseinput animal's owner lastname: " << endl;
					cin >> newData;
					o << newData << "  ";
					trt.push_back(newData);
					cout << "Please input the animal's owner firstname: " << endl;
					cin >> newData;
					trt.push_back(newData);
					o << newData << "  ";
					cout << "Please input the animal's species:  " << endl;
					cin >> newData;
					o << newData << "  ";
					trt.push_back(newData);
					cout << "Please input the animal's date of birth: " << endl;
					cin >> newData;
					o << newData << "  ";
					trt.push_back(newData);
					cout << "Please input the animal's first treatment: ";


					for (int i = 0; i < 10; i++)
					{
						cout << endl << "Treatment #" << i << ": ";
						cin >> newData;
						if (newData == "q" || newData == "Q")
						{
							break;
						}
						trt.push_back(newData);
						o << newData << "  ";

					}
					list->insert(trt);
					o << endl;

					break;
				}
				case 2:
					cout << "Please input the name of the animal whose record you wish to modify: ";
					cin >> an;
					cout << "Now please input the name of the owner of the animal: ";
					getchar();
					getline(cin, name);
					list->modifyExisting(an, name, sp, db, trt);
					break;

				case 3:
					cout << "Please input the name of the animal whose record you wish to delete: ";
					cin >> an;
					cout << "Now please input the name of the owner of the animal: ";
					cin >> name;
					list->deleteMember(an, name);
					break;

				case 4:
					list->display();
					break;

				case 5:
					cout << "Please input the name of the animal whose record you wish to display: ";
					cin >> an;
					cout << "Now please input the name of the owner of the animal: ";
					getchar();
					getline(cin, name);
					list->search(an, name);
					break;

				default:
					break;

				}

			} 

		} while (uin != 6);
	}
	f.close();
	o.close();
	getchar();

	return 0;
}
