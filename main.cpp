#include "student.hpp"
#include "student_list.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
using namespace std;

void unitTest_Search(domStudents &dList, intStudents &iList);

int main(){

    domStudents stuList;


    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile;
      domesticFile.open("domestic-stu.txt");
      if(domesticFile.fail())
      {
        cout << "Input file opening failed." << endl;
        exit(1);
      }

      if(!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
      }

      getline(domesticFile, line);
      //domestic arrays
      while( getline(domesticFile, line) ) {
        istringstream ss(line);
        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        DomesticStudent* tempStud;
        tempStud = new DomesticStudent;
   
        //get firstName separated by comma
        getline(ss, firstName, ',');
        if(firstName.empty()){
            cout << "the student's first name is missing " << endl;
            exit(1);
        }

        tempStud->setFirstName(firstName);
   
   

        //get lastName separated by comma
        getline(ss, lastName, ',');
        if(lastName.empty()){
            cout << "the student's last name is missing " << endl;
            exit(1);
        }
        tempStud->setLastName(lastName);

   

        //get province separated by comma
        getline(ss, province, ',');
        if(province.empty()){
            cout << "the student's province is missing " << endl;
            exit(1);
        }
        tempStud->setProvince(province);
   

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        if(s_cgpa.empty()){
            cout << "the student's s_cgpa is missing " << endl;
            exit(1);
        }
        cgpa = atof(s_cgpa.c_str());
        tempStud->setCGPA(cgpa);
   
   
        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        if(s_researchScore.empty()){
            cout << "the student's s_researchScore is missing " << endl;
            exit(1);
        }
        researchScore = atoi(s_researchScore.c_str());
        tempStud->setResearchScore(researchScore);
           stuList.insert(tempStud);

   
     }


     intStudents intList;


    //Read the domestic-stu.txt file and exit if failed
    string line1;
    ifstream internationalFile;
      internationalFile.open("international-stu.txt");
      if(internationalFile.fail())
      {
        cout << "Input file opening failed." << endl;
        exit(1);
      }

      if(!internationalFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
      }

      //getline(internationalFile, line1);
      //domestic arrays
      while( getline(internationalFile, line1) ) {
          bool drop_flag = false;

        istringstream ss(line1);
           string firstName, lastName, country, s_cgpa, s_researchScore, s_read, s_listen, s_speak, s_write;
        float cgpa;
        int researchScore;
        int read;
        int listen;
        int speak;
        int write;
   

        InternationalStudent* tempStud;
        tempStud = new InternationalStudent;
   
        //get firstName separated by comma
        getline(ss, firstName, ',');
        if(firstName.empty()){
            cout << "the student's first name is missing " << endl;
            exit(1);
        }
        tempStud->setFirstName(firstName);
   
   

        //get lastName separated by comma
        getline(ss, lastName, ',');
        if(lastName.empty()){
            cout << "the student's last name is missing " << endl;
            exit(1);
        }
        tempStud->setLastName(lastName);
   

        //get country separated by comma
        getline(ss, country, ',');
        if(country.empty()){
            cout << "the student's country is missing " << endl;
            exit(1);
        }
        tempStud->setCountry(country);
   

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        if(s_cgpa.empty()){
            cout << "the student's s_cgpa is missing " << endl;
            exit(1);
        }
        cgpa = atof(s_cgpa.c_str());
        tempStud->setCGPA(cgpa);
   
   
        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        if(s_researchScore.empty()){
            cout << "the student's s_researchScore is missing " << endl;
            exit(1);
        }
        researchScore = atoi(s_researchScore.c_str());
        tempStud->setResearchScore(researchScore);

        ToeflScore* tempToefl;
        tempToefl = new ToeflScore;

           getline(ss, s_read, ',');
        read = atof(s_read.c_str());
        if(s_read.empty()){
            cout << "the student's s_read is missing " << endl;
            exit(1);
        }
        if(read < 20)
            drop_flag = true;
        tempToefl->setReading(read);
   
        getline(ss, s_listen, ',');
        if(s_listen.empty()){
            cout << "the student's s_listen is missing " << endl;
            exit(1);
        }
        listen = atof(s_listen.c_str());
        if(listen < 20)
            drop_flag = true;
        tempToefl->setListening(listen);
   
        getline(ss, s_speak, ',');
        if(s_speak.empty()){
            cout << "the student's s_speak is missing " << endl;
            exit(1);
        }
        speak = atof(s_speak.c_str());
        if(speak < 20)
            drop_flag = true;
        tempToefl->setSpeaking(speak);
   
        getline(ss, s_write, ',');
        if(s_write.empty()){
            cout << "the student's s_write is missing " << endl;
            exit(1);
        }
           write = atof(s_write.c_str());
           if(write < 20)
            drop_flag = true;
        tempToefl->setWriting(write);

        if(write + speak + listen + read < 93)
            drop_flag = true;
        if(drop_flag == false){
            tempStud->setToeflScore(*tempToefl);
            intList.insert(tempStud);
        }


   
     }






     cout << "international students: " << endl;
     intList.printList();

         DomesticStudent* dom_ptr=NULL, dom_stu;
    dom_stu.setFirstName("Peter");
  
    dom_stu.setLastName("Smith");
    dom_stu.setProvince("BC");
    dom_stu.setCGPA(3.00);
    dom_stu.setResearchScore(80);
    dom_ptr = &dom_stu;

    stuList.insert(stuList, dom_ptr);
     cout << "domestic students: " << endl;
     stuList.printList();

     cout << "There are " << intList.totalStudent() << " international students " << endl;
     cout << "There are " << stuList.totalStudent() << " domestic students " << endl;
     DomesticStudent *tempStud = stuList.getTop();
     for(int i = 0; i < 10 ; i++){
         tempStud = tempStud->nextDom;

     }
     cout << "rank " << stuList.rankStudent(tempStud) << endl;
    
    
    
    Students sList;
    sList = mergeList(stuList, intList);
    sList.printList();
    cout << "Check search Threshold function." << endl;
    sList.searchThreshold(0.0, 99);
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "perform the unit test: " << endl;
    unitTest_Search(stuList, intList);
    
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
