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
	
	DomesticStudent* getTop();
        DomesticStudent* getlast();
        void Search(domStudents head, double target);
        void Search(domStudents head, int target);
	void Search(domStudents head, string FirstName, string LastName);
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
