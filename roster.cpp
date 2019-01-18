#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

int main() {
	cout << "==> Course title: SCRIPTING AND PROGRAMMING APPLICATIONS — C867" << endl;
	cout << "==> Programming language used: C++" << endl;
	cout << "==> Student ID: 000728862" << endl;
	cout << "==> Student name: Julian Des Marais" << endl;

	Roster classRoster;
	classRoster.extractStudentData();
	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < rosterMax; i++) {
		classRoster.printDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentId());
	}

	classRoster.printByDegreeProgram(Degree::SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	classRoster.printAll();

	classRoster.~Roster();
	return 0;
}

Roster::Roster() {
}

Roster::~Roster() {
}

Student ** Roster::getClassRosterArray()
{
	return classRosterArray;
}

void Roster::extractStudentData() {
	for (int i = 0; i < rosterMax; i++) {
		int tempAge, tempDaysInCourse1, tempDaysInCourse2, tempDaysInCourse3;
		vector<string> studentDataSplit;
		string splitByDelimiter;
		char delimiter = ',';
		istringstream stringStream(studentData[i]);

		while (getline(stringStream, splitByDelimiter, delimiter)) {
			cout << splitByDelimiter << endl;
			studentDataSplit.push_back(splitByDelimiter);
		}

		Degree::DegreeType tempDegree;
		string tempDegreeString = studentDataSplit[8];
		
		if (tempDegreeString == "NETWORK") {
			tempDegree = Degree::NETWORK;
		}
		else if (tempDegreeString == "SECURITY") {
			tempDegree = Degree::SECURITY;
		}
		else if (tempDegreeString == "SOFTWARE") {
			tempDegree = Degree::SOFTWARE;
		}
		else {
			throw exception("Degree type did not match known degree types. Check studentData table and DegreeType enum.");
		}

		tempAge = stoi(studentDataSplit[4]);
		tempDaysInCourse1 = stoi(studentDataSplit[5]);
		tempDaysInCourse2 = stoi(studentDataSplit[6]);
		tempDaysInCourse3 = stoi(studentDataSplit[7]);

		add(studentDataSplit[0], studentDataSplit[1], studentDataSplit[2], studentDataSplit[3], tempAge,
			tempDaysInCourse1, tempDaysInCourse2, tempDaysInCourse3, tempDegree);
	}
}

void Roster::remove(string studentId)
{
	cout << "==> Attempting to remove student from classRosterArray with ID: " << studentId << endl;
	for (int i = 0; i < rosterMax; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentId() == studentId) {
				classRosterArray[i] = nullptr;
				cout << "==> Removed student with ID: " << studentId << endl;
				return;
			}
		}
	}

	cout << "==> Unable to find any students to remove with ID: " + studentId << endl;
}

void Roster::printAll()
{
	cout << "==> Printing all student data" << endl;
	for (int i = 0; i < rosterMax; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << "==> Finished printing all student data" << endl;
}

void Roster::printDaysInCourse(string studentId)
{
	for (int i = 0; i < rosterMax; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			int* tempDays = classRosterArray[i]->getDaysToCompleteEachCourse();
			int averageDays = (tempDays[0] + tempDays[1] + tempDays[2]) / 3;
			cout << "\n==> Average number of days in classes for student with ID: " << studentId << " is: " << averageDays << "\n" << endl;
			break;
		}
	}
}

void Roster::printInvalidEmails()
{
	vector<string> invalidEmails;
	for (int i = 0; i < rosterMax; i++) {
		string tempEmail = classRosterArray[i]->getEmailAddress();
		bool hasSpace = false;
		bool hasAtChar = tempEmail.find("@") != string::npos;
		bool hasPeriodChar = tempEmail.find(".") != string::npos;

		for (char c : tempEmail) {
			if (isspace(c)) {
				hasSpace = true;
				break;
			}
		}

		bool validEmail = hasAtChar && hasPeriodChar && !hasSpace;

		if (!validEmail) {
			invalidEmails.push_back(tempEmail);
		}
	}

	if (invalidEmails.size() > 0) {
		cout << "==> Invalid emails found: \n" << endl;
		for (string invalidEmail : invalidEmails) {
			cout << invalidEmail << "\n" << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree::DegreeType degreeProgram)
{
	for (int i = 0; i < rosterMax; i++) {
		Degree::DegreeType currentDegreeProgram = classRosterArray[i]->getDegreeProgram();

		if (currentDegreeProgram == degreeProgram) {
			cout << "==> " << classRosterArray[i]->getDegreeProgramString() << " program student found: ";
			classRosterArray[i]->print();
			cout << "\n" << endl;
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeType degreeProgram) {
	if (rosterStudentIndex < rosterMax) {
		int tempDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		switch (degreeProgram)
		{
		case Degree::SECURITY:
			classRosterArray[rosterStudentIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse);
			rosterStudentIndex++;
			break;
		case Degree::NETWORK:
			classRosterArray[rosterStudentIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse);
			rosterStudentIndex++;
			break;
		case Degree::SOFTWARE:
			classRosterArray[rosterStudentIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse);
			rosterStudentIndex++;
			break;
		}
	}
	else {
		throw exception("Lines of student data in studentData string array exceeded rosterMax.");
	}
}
