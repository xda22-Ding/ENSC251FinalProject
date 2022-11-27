#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
using namespace std;

void unitTest_Search(domStudents &dList, intStudents &iList);


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

void unitTest_Search(domStudents &dList, intStudents &iList)
{
    Students mergedStudent;
    
    //Search by name
    cout << "Search a Student that not exit in the List (Jack Ma)" << endl;
    string f_name = "Jack";
    string l_name = "Ma";
    cout << "Search Jack Ma in domestic student list: " << endl;
    dList.Search(dList, f_name, l_name);
    cout << "Search Jack Ma in domestic student list: " << endl;
    iList.Search(iList, f_name, l_name);
    
    cout << "Search a Student that in the domestic student list (Aurora Foster): " << endl;
    f_name = "Aurora";
    l_name = "Foster";
    cout << "Search Aurora Foster in domestic student list: " << endl;
    dList.Search(dList, f_name, l_name);
    cout << "Search Aurora Foster in domestic student list: " << endl;
    iList.Search(iList, f_name, l_name);
    
    cout << "Search a Student that in the international student list (Ting Fang): " << endl;
    f_name = "Ting";
    l_name = "Fang";
    cout << "Search Ting Fang in international student list: " << endl;
    dList.Search(dList, f_name, l_name);
    cout << "Search Ting Fang in international student list: " << endl;
    iList.Search(iList, f_name, l_name);
    
    //Search by StuID
    cout << "Search for student with APP ID #20220200 (edge case): " << endl;
    int Stu_ID = 20220200;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, Stu_ID);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, Stu_ID);
    
    cout << "Search for student with APP ID #20220000 (edge case): " << endl;
    Stu_ID = 20220000;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, Stu_ID);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, Stu_ID);
    
    
    cout << "Search for student with APP ID #20220116 (normal case): " << endl;
    Stu_ID = 2022116;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, Stu_ID);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, Stu_ID);
    
    cout << "Search for student with APP ID #20220729 (illegal case): " << endl;
    Stu_ID = 20220729;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, Stu_ID);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, Stu_ID);
    
    //Search by CGPA
    cout << "Search for student with CGPA 2.8 (edge case): " << endl;
    float CGPA = 2.8;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, CGPA);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, CGPA);
    
    cout << "Search for student with CGPA 4.33 (edge case): " << endl;
    CGPA = 4.33;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, CGPA);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, CGPA);
    
    cout << "Search for student with CGPA 2.95 (normal case): " << endl;
    CGPA = 2.95;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, CGPA);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, CGPA);
    
    cout << "Search for student with CGPA 5 (illegal case): " << endl;
    CGPA = 5;
    cout << "Search in domestic student list: " << endl;
    dList.Search(dList, CGPA);
    cout << "Search in international student list: " << endl;
    iList.Search(iList, CGPA);
    
    //Search Threshold
    cout << "Merge two lists." << endl;
    mergedStudent = mergeList(dList, iList);
    
    cout << "Search based on the threshold: CGPA: 2.85, Research Score: 100 (edge case): " << endl;
    float cgpaThreshold = 2.85;
    int researchThreshold = 100;
    mergedStudent.searchThreshold(cgpaThreshold, researchThreshold);
    
    cout << "Search based on the threshold: CGPA: 2.95, Research Score: 70 (edge case): " << endl;
    cgpaThreshold = 2.95;
    researchThreshold = 70;
    mergedStudent.searchThreshold(cgpaThreshold, researchThreshold);
    
    cout << "Search based on the threshold: CGPA: 3.75, Research Score: 78 (normal case): " << endl;
    cgpaThreshold = 3.75;
    researchThreshold = 78;
    mergedStudent.searchThreshold(cgpaThreshold, researchThreshold);
    
    cout << "Search based on the threshold: CGPA: 4.33, Research Score: 100 (illegal case): " << endl;
    cgpaThreshold = 4.33;
    researchThreshold = 100;
    mergedStudent.searchThreshold(cgpaThreshold, researchThreshold);
    
}
