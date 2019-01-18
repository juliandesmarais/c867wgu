#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, Degree::SOFTWARE) {
	this->setDegreeProgram(Degree::SOFTWARE);
}

Degree::DegreeType SoftwareStudent::getDegreeProgram() {
	return Degree::SOFTWARE;
}