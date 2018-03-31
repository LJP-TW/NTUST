// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 29, 2018
// Last Update: Mar. 29, 2018
// Problem statement: Register and print student's grade
#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class student
{
public:
	void setDetails();
	void getDetails();
private:
	string name;	// student name
	int stuNum;		// student number
	int totalGrade; // student total grade
};

void student::setDetails()
{
	cin >> name >> stuNum >> totalGrade;
}

void student::getDetails()
{
	cout << "Student details:" << endl;
	cout << "Name:" << name << endl;
	cout << "Student Number:" << stuNum << endl;
	cout << "Total:" << totalGrade << endl;

	if (totalGrade > 300)
	{
		cout << "Total scores should be under 300!" << endl;
	}
	cout << "Percentage:" << (double)totalGrade / 3 << endl;
}

int main()
{
	student std[MAX];       //array of objects creation
	int numberOfStudents;

	cout << "Enter total number of students: ";
	cin >> numberOfStudents;

	for (int i = 0; i< numberOfStudents; i++) {
		cout << "Enter details of student " << i + 1 << ":\n";
		std[i].setDetails();
	}

	cout << endl;

	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Details of student " << (i + 1) << ":\n";
		std[i].getDetails();
		cout << endl;
	}

	system("pause");
	return 0;
}