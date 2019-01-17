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

Roster::Roster() {
}

Roster::~Roster() {
}

int main() {
	Roster classRoster;
	classRoster.extractStudentData();
	classRoster.printAll();
	classRoster.printDaysInCourse("A2");
	classRoster.printInvalidEmails();
	classRoster.printByDegreeProgram(Degree::NETWORK);
	return 0;
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
	for (int i = 0; i < rosterMax; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			classRosterArray[i]->resetStudentData();
			break;
		}

		if (i == rosterMax) {
			cout << "==> Unable to find any students to remove with ID: " + studentId;
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i < rosterMax; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printDaysInCourse(string studentId)
{
	for (int i = 0; i < rosterMax; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			int* tempDays = classRosterArray[i]->getDaysToCompleteEachCourse();
			int averageDays = (tempDays[0] + tempDays[1] + tempDays[2]) / 3;
			cout << "\nAverage number of days in classes for student with ID: " << studentId << " is: " << averageDays << "\n" << endl;
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
		cout << "Invalid emails found: \n" << endl;
		for (string invalidEmail : invalidEmails) {
			cout << invalidEmail << "\n" << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree::DegreeType degreeProgram)
{
	for (int i = 0; i < rosterMax; i++) {
		Degree::DegreeType tempDegree = classRosterArray[i]->getDegreeProgram();

		if (tempDegree == degreeProgram) {
			cout << classRosterArray[i]->getDegreeProgramString() << " program student found: ";
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
			classRosterArray[rosterStudentIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse, degreeProgram);
			rosterStudentIndex++;
			break;
		case Degree::NETWORK:
			classRosterArray[rosterStudentIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse, degreeProgram);
			rosterStudentIndex++;
			break;
		case Degree::SOFTWARE:
			classRosterArray[rosterStudentIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, tempDaysInCourse, degreeProgram);
			rosterStudentIndex++;
			break;
		}
	}
	else {
		throw exception("Lines of student data in studentData string array exceeded rosterMax.");
	}
}
