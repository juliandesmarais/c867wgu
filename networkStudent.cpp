#include "networkStudent.h"

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType degreeType) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeType) {
	degreeType = Degree::DegreeType::NETWORKING;
}

Degree::DegreeType NetworkStudent::getDegreeProgram() {
	return degreeType;
}