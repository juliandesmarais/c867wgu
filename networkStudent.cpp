#include "networkStudent.h"

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeType) {
	this->setDegreeProgram(Degree::NETWORK);
}

Degree::DegreeType NetworkStudent::getDegreeProgram() {
	return Degree::NETWORK;
}