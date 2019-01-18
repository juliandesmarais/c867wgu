#pragma once
#include <string>
#include "student.h"
#include "degree.h"
#include <sstream> 
using namespace std;

const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Julian,DesMarais,juliandesmarais@gmail.com,29,14,14,12,SOFTWARE",
};
const int rosterMax = 5;
const int perStudentInfoMax = 9;

class Roster {
public:
	Roster();
	~Roster();

	Student** getClassRosterArray();
	int rosterStudentIndex = 0;
	void extractStudentData();
	void remove(string studentId);
	void printAll();
	void printDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree::DegreeType degreeProgram);
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeType degreeProgram);

private:
	Student* classRosterArray[rosterMax];
};

int main();
