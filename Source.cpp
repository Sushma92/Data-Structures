#include<stdio.h>
#include"q.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>


#include<sstream>

using namespace std;

int main() {
	ifstream f;
	f.open("infile.dat", ios::in);
	q* list = new q();
	if (f.is_open()) {
		string str;
		while (!f.eof()) {
			getline(f, str);
			string buf;                 // Have a buffer string
			stringstream ss(str);
			vector<string> tokens; // Create vector to hold our words
			while (ss >> buf)
				tokens.push_back(buf);
			list->enterQueue(tokens);
		}
		
			{
				cout << "Starting the operation..." << endl;
				list->display();
				
			}
		
	}
	f.close();
	getchar();
	return 0;
}
