#include "securityStudent.h"

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType degreeType) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeType) {
	degreeType = Degree::DegreeType::SECURITY;
}

Degree::DegreeType SecurityStudent::getDegreeProgram() {
	return degreeType;
}