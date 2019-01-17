#pragma once
using namespace std;
#include "degree.h"

class Student {
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	string degreeProgramString;
	int age;
	Degree::DegreeType degreeProgram;
	int daysToCompleteEachCourse[3];

public:
	// Constructor
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType degreeType);
	// Destructor
	~Student();

	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDegreeProgram(Degree::DegreeType degreeType);
	void setDaysToCompleteEachCourse(int*);
	void resetStudentData();

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getDegreeProgramString();
	int getAge();
	int *getDaysToCompleteEachCourse();

	virtual Degree::DegreeType getDegreeProgram();
	virtual void print();
};
