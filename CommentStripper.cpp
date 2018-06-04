#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	cout << "start";
	ifstream f;
	ofstream o;
	char ch = ' ', next = ' ';
	string line;
	f.open("InStuff.cpp", ios::in);
	o.open("OutStuff.cpp", ios::out);
	if (f.is_open() && o.is_open()) {
		while(f.get(next)){
			if (ch == '/' && next == '/') {
				ch = ' ';
				getline(f, line);
			}
			else if (ch == '/' && next == '*') {
				while (!(ch == '*' && next == '/')) {
					ch = next;
					f.get(next);
				}
				ch = ' ';
			}
			else {
				o.put(ch);
				ch = next;
			}
		}
		o.put(ch);
	}
	
	f.close();
	o.close();
	return 0;
}
