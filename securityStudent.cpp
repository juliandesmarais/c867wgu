#include "securityStudent.h"

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeType) {
	this->setDegreeProgram(Degree::SECURITY);
}

Degree::DegreeType SecurityStudent::getDegreeProgram() {
	return Degree::SECURITY;
}