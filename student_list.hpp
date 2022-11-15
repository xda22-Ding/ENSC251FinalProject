#include "student.hpp"
#include<iostream>
#include <iomanip>
using namespace std;

class Students
{
public:
	Students();

	void insert(Student* stud);
	void printList();
private:
	Student* TopStudent;
	Student* lastStudent;
	
};