#include "mergeSort.h"
#include <string>
#include <iostream>

class Student {
	public:
	int rollNo;
	std::string name;
	
	Student() {
		this->rollNo = 0;
		this->name = "";
	}
	
	Student(int rollNo, std::string name) {
		this->rollNo = rollNo;
		this->name = name;
	}
	
	static int compareRoll(Student &ob1, Student &ob2);
	
	static int compareName(Student &ob1, Student &ob2);
};

int Student::compareRoll(Student &ob1, Student &ob2) {
	return ob1.rollNo - ob2.rollNo;
}

int Student::compareName(Student &ob1, Student &ob2) {
	return ob1.name.compare(ob2.name);
}

int main(void) {
	Student students[5];
	
	students[0] = Student(20, std::string("Barry") );
	students[1] = Student(10, std::string("Zamayla") );
	students[2] = Student(17, std::string("Giovanni") );
	students[3] = Student(30, std::string("Putin") );
	students[4] = Student(35, std::string("Niko") );
	
	algo::mergeSort(students, 5, Student::compareName);
	for (int i = 0; i < 5; i++)
		std::cout << students[i].rollNo << " " << students[i].name << std::endl; 
	
	algo::mergeSort(students, 5, Student::compareRoll);
	for (int i = 0; i < 5; i++)
		std::cout << students[i].rollNo << " " << students[i].name << std::endl; 
	
	return 0;
}