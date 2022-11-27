#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
using namespace std;

int main(){

    domStudents stuList;
    intStudents intList;
    DomesticStudent* domStudent1;
    domStudent1= new DomesticStudent("David","Black",4.3,100,"BC");


    DomesticStudent* domStudent2;
    domStudent2 = new DomesticStudent("Neil", "Green", 4.29, 100, "AB");

    DomesticStudent* domStudent3;
    domStudent3 = new DomesticStudent("Neil", "Green", 4.31, 100, "AB");

    stuList.insert(domStudent1);
    stuList.insert(domStudent2);

    stuList.printList();





    return 0;
}