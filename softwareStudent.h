#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType degreeType);
	Degree::DegreeType getDegreeProgram() override;

private:
	Degree::DegreeType degreeType;
};
