#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class StudentCourseGrade {
public:
	string cName; //Class name
	string cNum; // class number
	string grade;
	
	static float calqp(string grade) { //Converting the grade to quality points
		if (grade == "A")
			return 4.0;
		else if (grade == "B")
			return 3.0;
		else if (grade == "C")
			return 2.0;
		else if (grade == "D")
			return 1.0;
		else if (grade == "F")
			return 0.0;
	}
};

class StudentRecord {
public:
	string firstName;
	string lastName;
	string gpa;
	StudentCourseGrade grades[5];
	
	void StudentRecord::currentgrades() { //current semester grades are displayed
		cout << firstName << " " << lastName << " " << gpa << " ";
		for (int i = 0; i < 5; i++) {
			cout << grades[i].cNum << grades[i].cName;
			cout << " " << grades[i].grade << " ";
		}
		cout << endl << endl;
	}

	float StudentRecord::overallGpa() { // Gpa for 2 semesters
		float previous = stof(gpa) * 12;
		float current = 0.0;
		for (int j = 0; j < 5; j++) {
			current += 3 * StudentCourseGrade::calqp(grades[j].grade);
		}
		currentgrades();
		float ovGpa = (previous + current) / 27;
		return ovGpa;
	}
};

class Main{
public:
	void listOfAllStudentNames(StudentRecord *data) { // prints list of all student names
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			cout << data[i].firstName << " " << data[i].lastName << endl;
		}
	}

	void listOfAllStudentNamesAndGpa(StudentRecord *data) { //prints list of all student names + current Gpa
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			cout << data[i].firstName << " " << data[i].lastName << " " << data[i].gpa << endl;
		}
	}
	
	void studentInfo_SameLastName(StudentRecord *data, string ln) { //select student with last name and print info on all students with same last name
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			if (data[i].lastName == ln)
				data[i].currentgrades();
		}
	}
	
	void studentInfo_FullName(StudentRecord *data, string fn, string ln) { //slect student by name and print info of that student
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			if (data[i].firstName == fn && data[i].lastName == ln)
				data[i].currentgrades();
		}
	}
	
	
	void studentNewGpa(StudentRecord *data, string fn, string ln) { //select student and calculate new gpa
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			if (data[i].firstName == fn && data[i].lastName == ln)
				cout << "Overall Gpa: " << data[i].overallGpa();
		}
	}
	
	void studentInfo(StudentRecord *data) { //print list of all student names + new gpa
		for (int i = 0; i < 10; i++) {
			if (data[i].firstName.empty())
				break;
			cout << data[i].firstName << " " << data[i].lastName << " " 
				<< data[i].overallGpa() << " " << endl;
			
		}
	}
	
};

int main() {
	cout << "Please select the options:" << endl;
	StudentRecord record[10];
	string line;
	ifstream f;
	f.open("InData.txt", ios::out);
	if (f.is_open()) {
		for (int k = 0; k < 10; k++) {
			if (!getline(f, line))
				break;
			record[k].firstName = line;
			getline(f, line);
			record[k].lastName = line;
			getline(f, line);
			record[k].gpa = line;

			int i = 0;
			StudentCourseGrade scg;
			int count = 1;
			int course = 1;
			while (course <= 15 && getline(f, line)) {
				switch (count) {
				case 1:
					scg.cNum = line;
					break;
				case 2:
					scg.cName = line;
					break;
				case 3:
					scg.grade = line;
					count = 0;
					record[k].grades[i] = scg;
					i++;
					break;
				default:
					break;


				}
				count++;
				course++;
			}
		}
	}

	cout << "Data stored" << endl;
	char userInput = ' ';
	Main m;
	cout << endl;
	do {
		cout << "Options:" << endl;
		cout << "1.Print all Student names" << endl;
		cout << "2. print all student names and current gpa" << endl;
		cout << "3. enter lastname" << endl;
		cout << "4. enter full name" << endl;
		cout << "5. enter gpa" << endl;
		cout << "6. Information of all Students" << endl;
		cout << "Your option:";
		cin >> userInput;
		if (userInput != 'd') {
			int val = userInput - '0';
			string fn = "", ln = "";
			switch (val)
			{
			case 1:
				m.listOfAllStudentNames(record);
				break;
			case 2:
				m.listOfAllStudentNamesAndGpa(record);
				break;
			case 3:
				cout << "enter last name: ";
				cin >> ln;
				m.studentInfo_SameLastName(record, ln);
				break;
			case 4:
				cout << "enter first name: ";
				cin >> fn;
				cout << "enter last name: ";
				cin >> ln;
				m.studentInfo_FullName(record, fn, ln);
				break;
			case 5:
				cout << "enter first name: ";
				cin >> fn;
				cout << "enter last name: ";
				cin >> ln;
				m.studentNewGpa(record, fn, ln);
				break;
			case 6:
				m.studentInfo(record);
				break;

			default:
				break;
			}
		}
		
		
	} while (userInput != 'd');
	cout << "exit" << endl;
	int a;
	cin >> a;
	return 0;
}