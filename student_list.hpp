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
/*
 class Student_Node
 {
 public:
     Student st;
     Student_Node* next;
     Student_Node(Student new_st);
     Student_Node();
 };
 class Student_list
 {
 public:
     //constructor
     Student_list();
     
     //destructr
     ~Student_list();
     
     //getter
     Student_Node* getHead() const;
     Student_Node* getTail() const;
     
     //other member functions
     void insertall(Student_Node* new_st);
     void mergeList(domStudents &dList, intStudents &iList, Student_list &sList);
     
 private:
     Student_Node* head;
     Student_Node* tail;
 };
 //friend functions
 int compareOverall_modified(const Student s1, const Student s2);
 */
