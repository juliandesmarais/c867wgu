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

int main() {
	
	return 0;
}

void Roster::extractStudentData() {
	rosterStudentIndex = 0;
	Roster classRoster;

	for (int i = 0; i < rosterMax; i++) {
		vector<string> studentDataSplit;
		istringstream stringStream(studentData[i]);
		string splitByDelimiter;
		char delimiter = ',';

		while (getline(stringStream, splitByDelimiter, delimiter)) {
			cout << splitByDelimiter << endl;
			studentDataSplit.push_back(splitByDelimiter);
		}

		if (sizeof(studentDataSplit) != 9) {
			throw exception("Line of student data did not have valid quantity of input. Index: " + i);
		}

		Degree::DegreeType tempDegree;
		string degreeTypeTemp = studentDataSplit[8];

		if (degreeTypeTemp == "NETWORKING") {
			tempDegree = Degree::DegreeType::NETWORKING;
		}
		else if (degreeTypeTemp == "SECURITY") {
			tempDegree = Degree::DegreeType::SECURITY;
		}
		else if (degreeTypeTemp == "SOFTWARE") {
			tempDegree = Degree::DegreeType::SOFTWARE;
		}
		else {
			throw exception("Degree type did not match known degree types. Check studentData table and DegreeType enum.");
		}

		int tempAge, tempDaysInCourse1, tempDaysInCourse2, tempDaysInCourse3;
		istringstream(studentDataSplit[4]) >> tempAge;
		istringstream(studentDataSplit[5]) >> tempDaysInCourse1;
		istringstream(studentDataSplit[6]) >> tempDaysInCourse2;
		istringstream(studentDataSplit[7]) >> tempDaysInCourse3;

		classRoster.add(studentDataSplit.at[0], studentDataSplit[1], studentDataSplit[2], studentDataSplit[3], tempAge,
			tempDaysInCourse1, tempDaysInCourse2, tempDaysInCourse3, tempDegree);
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
		case Degree::NETWORKING:
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
