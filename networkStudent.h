#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class NetworkStudent : public Student {
public:
	NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *daysToCompleteEachCourse);
	Degree::DegreeType getDegreeProgram() override;

private:
	Degree::DegreeType degreeType;
};
