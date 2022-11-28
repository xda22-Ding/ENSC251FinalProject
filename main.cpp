#include "student.hpp"
#include "student_list.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
using namespace std;

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


    char choose;
    for(int k = 1; k < 100; k++)
    {
     cout <<"  What do you want?" <<endl;
     cout <<"  A for Printing All Sorted Domestic-stu Document" << endl;
     cout <<"  B for Printing All Sorted International-stu Document" << endl;
     cout <<"  C for " << endl;
     cout <<"  D for " <<endl;
     cout <<"  E for "<<endl;
     cout <<"  F for " <<endl;
     cout <<"  G for stop" << endl;  
     cin >> choose;
     
     if(choose > 'G' || choose < 'A')
     {
       cout << "Please write number between A and G" << endl;
       exit(1);
     }
     if(choose == 'G')
       break;
     else
     {
       switch(choose)
        {
        case 'A':
            stuList.printList();
            break;
        case 'B':
            intList.printList();
            break;
        case 'C':
            break;
        case 'D':
            break;           
        case 'E':
            break;
        case 'F':
            break;
      }
    }
 
}



     /*** //User id password
	int id;
	int pw;
	
	cout<<"ID: ";
	cin >> id;
	cout<<"Password: ";
	cin >> pw;
        if (intList.isVerified(id, pw)) {
	 intList.Search(intList, id);
	 cout << "Application Status: Processing" << endl;
	 
        }
	else{
	 
	 intList.Search(intList, id);
	 cout << "Applicaiton Status: Fail" << endl;
	
	}
***/	

    /*
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
    */
    return 0;
}
