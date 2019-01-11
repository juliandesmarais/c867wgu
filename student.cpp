#pragma once
#include <string>
#include "degree.h"
#include "student.h"

Student::Student(string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int *daysToCompleteEachCourse, Degree::DegreeType type) {
	this->setStudentId(studentId);
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setEmailAddress(emailAddress);
	this->setAge(age);
	this->setDaysToCompleteEachCourse(daysToCompleteEachCourse);
	this->setDegreeProgram(type);
};

void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDegreeProgram(Degree::DegreeType type) {
	this->degreeProgram = type;
}

void Student::setDaysToCompleteEachCourse(int *daysToCompleteEachCourse) {
	for (int i = 0; i < 3; i++) {
		this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
	}
}

string Student::getStudentId() {
	return this->studentId;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int *Student::getDaysToCompleteEachCourse() {
	return this->daysToCompleteEachCourse;
}