#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType degreeType) :
	Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeType) {
	degreeType = Degree::DegreeType::SOFTWARE;
}

Degree::DegreeType SoftwareStudent::getDegreeProgram() {
	return degreeType;
}