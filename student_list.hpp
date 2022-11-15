#include "student.hpp"
#include<iostream>
#include <iomanip>
using namespace std;

class domStudents
{
public:
	domStudents();

	void insert(DomesticStudent* stud);
	void printList();
private:
	DomesticStudent* TopStudent;
	DomesticStudent* lastStudent;
	
};


class intStudents
{
public:
	intStudents();

	void insert(InternationalStudent* stud);
	void printList();
private:
	InternationalStudent* TopIntStudent;
	InternationalStudent* lastIntStudent;
	
};