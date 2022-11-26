#ifndef student_list_hpp
#define student_list_hpp

#include "student.hpp"
#include<iostream>
#include <iomanip>
using namespace std;


class Students
{
public:
    //Constructor
    Students();
    //getter
    Student* getTop();
    Student* getlast();
    
    //Other member functions
    void insertMix(Student* stud);
    void searchThreshold(float cgpaThreshold, int researchThreshold);
    virtual void printList();
private:
    Student* TopStudent;
    Student* lastStudent;
};


class domStudents: public Students
{
public:
    domStudents();

    void insert(DomesticStudent* stud);
    void printList();
    
    DomesticStudent* getTop();
    DomesticStudent* getlast();
    
    //This Search Function is to find some domestic students satisfied requirements of CGPA   2 b
    void Search(domStudents head, double target);

    //This Search Function is to find some domestic students satisfied requirements of application ID or research score 2b
    void Search(domStudents head, int target);

    //This Search Function is to find some domestic students satisfied requirements of Name 2c
    void Search(domStudents head, string FirstName, string LastName);
    
    //This function insert a new node in the linked list based on the required order 2d
    void insert(domStudents dom_list, DomesticStudent* stud);
    int totalStudent();
    float rankStudent(DomesticStudent* objectStud);
    
    //Innovation 2
    void requireDomCGPA(domStudents head, double target);
    void requireDomScore(domStudents head, int target);
private:
    DomesticStudent* TopStudent;
    DomesticStudent* lastStudent;
    
};


class intStudents: public Students
{
public:
    intStudents();

    void insert(InternationalStudent* stud);
    void printList();
    
    InternationalStudent* getTop();
    InternationalStudent* getlast();
    
    //This Search Function is to find some international students satisfied requirements of CGPA   2 b
    void Search(intStudents head, double target);
    
    //This Search Function is to find some international students satisfied requirements of application ID or research score 2b
    void Search(intStudents head, int target);
    
    //This Search Function is to find some international students satisfied requirements of Name 2c
    void Search(intStudents head, string FirstName, string LastName);
    
    //This function insert a new node in the linked list based on the required order 2d
    void insert( intStudents int_list ,  InternationalStudent* stud);
    int totalStudent();
private:
    InternationalStudent* TopIntStudent;
    InternationalStudent* lastIntStudent;
    
};
//Other functions
//Comapre Research -> CGPA
//1>2 return 1; 1<2 return -1;
int compareOverall (const Student s1, const Student s2);
//Merge function, merge one international student and one domestic student and return a student linked list
Students mergeList(domStudents &dList, intStudents &iList);





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

#endif /* student_list_hpp */
