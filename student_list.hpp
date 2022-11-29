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
    void dataSummary();
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
    void Search(domStudents head, float target);

    //This Search Function is to find some domestic students satisfied requirements of application ID or research score 2b
    void Search(domStudents head, int target);

    //This Search Function is to find some domestic students satisfied requirements of Name 2c
    void Search(domStudents head, string FirstName, string LastName);
    DomesticStudent* Search1 (domStudents head,string FirstName, string LastName);

    
    int totalStudent();
    float rankStudent(DomesticStudent* objectStud);
    
    //innovation 2
    void requireDomCGPA(domStudents head, float target);
    void requireDomScore(domStudents head, int target);
    
    void deleteDom(string fn,string ln);
    void deleteDom();
    //check input case
    string checKDomInput(string n);
    
    // Part2 3
    void Check_Provence(domStudents head);
    
    //innovation 3 
    bool isVerified(int ID, int PW) const;
    void resetPW(int id, int pw);
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
    void Search(intStudents head, float target);
    
    //This Search Function is to find some international students satisfied requirements of application ID or research score 2b
    void Search(intStudents head, int target);
    
    //This Search Function is to find some international students satisfied requirements of Name 2c
    void Search(intStudents head, string FirstName, string LastName);
    InternationalStudent* Search1(intStudents head, string FirstName, string LastName);
 
   
    int totalStudent();
    float rankStudent(InternationalStudent* objectStud);
    
    void deleteInt(string fn,string ln);
    void deleteInt();
    
    //innovation 2
    void requireIntCGPA(intStudents head, float target);
    void requireIntScore(intStudents head, int target);
    
    //check input case
    string checKIntInput(string n);
    
    //Part2 3
    void Check_Country(intStudents head);
    
    //innovation 3 
    bool isVerified(int ID, int PW) const;
    void resetPW(int id, int pw);
    
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


#endif /* student_list_hpp */
