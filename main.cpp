#include "student.hpp"
#include "student_list.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
using namespace std;

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
	
    //delete by name
    //normal case
    cout << endl;
    cout << "1.Deletion normal case: " << endl;
    cout << "Delete Emily Rivera in domestic student list: " << endl;
    dList.deleteDom("Emily", "Rivera");
    cout << "Delete Mohammad Darbandi in international student list: " << endl;
    iList.deleteInt("Mohammad", "Darbandi");

    //cornar case head
    cout << "2.Cornar case head: " << endl;
    cout << "Delete Elizabeth Cooper in domestic student list: " << endl;
    dList.deleteDom("Elizabeth", "Cooper");
    cout << "Delete Ting Fang in international student list: " << endl;
    iList.deleteInt("Ting", "Fang");

    //cornar case tail
    cout << "2.Cornar case tail: " << endl;
    cout << "Delete Violet Simmons in domestic student list: " << endl;
    dList.deleteDom("Violet", "Simmons");
    cout << "Delete Layla Shirvani in international student list: " << endl;
    iList.deleteInt("Layla", "Shirvani");

    //error case: delete a student does not exist
    cout <<"3.Error case: "<<endl;
    cout << "Delete a Student that not exit in the List" << endl;
    string fname = "Tom";
    string lname = "Luo";
    cout << "Delete Tom Luo in domestic student list: " << endl;
    dList.deleteDom(fname, lname);
    cout << "Delete Tom Luo in international student list: " << endl;
    iList.deleteInt(fname, lname);

    //check name input
    cout << "4.Check name input: " << endl;
    cout << "Delete lIaM EDwArds (Liam Edward) in domestic student list: " << endl;
    dList.deleteDom("lIaM", "EDwArds");
    cout << "Delete hyunJoon ChoI (Hyunjoon Choi) in international student list: " << endl;
    iList.deleteInt("hyunJoon", "ChoI");
    
}

void unitTest_InsertDomInt(){
    domStudents stuList_test;
    intStudents intList_test;
    DomesticStudent* domStudent1;
    domStudent1= new DomesticStudent("David","Black",4.3,100,"BC");


    DomesticStudent* domStudent2;
    domStudent2 = new DomesticStudent("Neil", "Green", 4.29, 100, "AB");

    DomesticStudent* domStudent3;
    domStudent3 = new DomesticStudent("Neil", "Green", 4.31, 100, "AB");

    stuList_test.insert(domStudent1);
    stuList_test.insert(domStudent2);

    stuList_test.printList();

}


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
    
    char choice;
    cout<<"Please select from a to c: "<<endl;
    cout<<"a for administrator" << endl;
    cout<<"b for domestic student"<<endl;
    cout<<"c for international student"<<endl;
    cin>> choice;
    
    if(choice > 'c' || choice < 'a')
     {
       cout << "Please write letter between a and c" << endl;
       exit(1);
     }

     if(choice == 'b'){
	int id;
	int pw;
	cout<<"Please enter ID and password"<< endl;
	cout<<"ID: ";
	cin >> id;
	cout<<"Password: ";
	cin >> pw;
        if (stuList.isVerified(id, pw)) {
	 stuList.Search(stuList, id);
	 cout << "Application Status: Processing" << endl;
	 
        }
	else{
	 
	 stuList.Search(stuList, id);
	 //cout << "Applicaiton Status: Fail" << endl;
	
	}	
     }

     if(choice == 'c'){
	int id;
	int pw;
	cout<<"Please enter ID and password"<< endl;
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
	 //cout << "Applicaiton Status: Fail" << endl;
	
	}	
     }

    if(choice == 'a'){
	    
    char choose;
    string domFN;
    string domLN;
    string intFN;
    string intLN;
    for(int k = 1; k < 100; k++)
    {
     cout <<"  What do you want?" <<endl;
     cout <<"  A for Printing All Sorted Domestic-stu Document" << endl;
     cout <<"  B for Printing All Sorted International-stu Document" << endl;
     cout <<"  C for Merge the demestic student and the international student and print the list" << endl;
     cout <<"  D for Perform the unit test for all search functions" <<endl;
     cout <<"  E for Delete domestic student by name"<<endl;
     cout <<"  F for Delete international student by name" <<endl;
     cout <<"  G for Delete head and tail from Domestic-stu Document"<<endl;
     cout <<"  H for Delete head and tail from International-stu Document"<<endl;
     cout <<"  I for Perform unit test for insert DomesticStudent(InternationalStudent) object into the DomesticStudent(InternationalStudent list)"<<endl;
     cout <<"  J for a data summary of students CGPA and Research Score" << endl; 
      cout<<"  K. Check Province Name of All Sorted Domestic-stu Document" << endl;
      cout<<"  L. Check Typo Of Country's Name of All Sorted International-stu Document" <<endl;
      cout<<"  M. Obtain Some Domestic Students Information"<<endl;
      cout<<"  N. Obtain Some International Students Information"<<endl;
      cout<<"  O. Insert New Domstic Students" <<endl; 
      cout<<"  P. Insert New International Students" <<endl;
      cout<<"  Q. Students Satisfied Special Requirement" <<endl; //innovation2
	    
     cout <<"  R for stop" << endl;  
     
     cin >> choose;
     
     if(choose > 'R' || choose < 'A')
     {
       cout << "Please write number between A and R" << endl;
     }
     if(choose == 'R')
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
            {
                Students s_list;
                s_list = mergeList(stuList, intList);
                s_list.printList();
                break;
            }
        case 'D':
            {
                unitTest_Search(stuList, intList);
                break;
            }
        case 'E':
	     
             cout<<"Please enter the first name: "<<endl;
	     cin >> domFN;
             cout<<"Please enter the first name: "<<endl;
             cin >> domLN;
             stuList.deleteDom(domFN,domLN);
             break;
        case 'F':
             cout<<"Please enter the first name: "<<endl;
	     cin >> intFN;
             cout<<"Please enter the first name: "<<endl;
             cin >> intLN;
             intList.deleteInt(intFN,intLN);  
             break;
        case 'G':
             cout<<"delete top and bottom from domestic student list"<<endl;
             stuList.deleteDom();
	     break;
        case 'H':
             cout<<"delete top and bottom from international student list"<<endl;
             intList.deleteInt();
	     break;
        case 'I':
            unitTest_InsertDomInt();
            break;
        case 'J':
            Students s_list;
            s_list = mergeList(stuList, intList);
            s_list.dataSummary();
	 case 'K':
          {              
	     stuList.Check_Provence(stuList);
              break;
          }
        case 'L':
          {
              intList.Check_Country(intList);
              break;
          }
         /*case 'M':
           { 
             char answerL;
             cout << "If you want to see the Domestic students satisfying some requirements. Please input y, any other char back to previous menu" << endl;
             cin >> answerL;
           while ((answerL == 'Y') || (answerL == 'y'))
            {           
             cout << "1. CGPA Requirement (float number between 0.00 and 4.33)"<< endl;
             cout << "2. Research Score Requirement(integer number between 70 annd 100)" <<endl;
             cout << "3. Application ID Requirement(integer number between " <<endl;
             cout << "4. First Name And Last Name Requirement" <<endl;
             cout << " Please input your choice" <<endl;
             int Choose_Dom;
             int Score_ID;
             float C_GPA;
             string First;
             string Last;
             cin >> Choose_Dom;
             switch(Choose_Dom)          
                {
                    case 1:
                         {
                          cout <<"Please Input the CGPA Requirement" <<endl;
                          cin >> C_GPA;
                          if((C_GPA < 0) || (C_GPA > 4.33))
                          {
                            cout <<"Please input float number between 0.00 and 4.33"<<endl;
                            break;
                          }
                          else
                          {
                            stuList.Search(stuList, C_GPA);
                            break;
                          }
                         }
                    case 2:
                        {
                          cout <<"Please Input the Research Score Requirement" <<endl;
                          cin >> Score_ID;
                          stuList.Search(stuList, Score_ID);
                          break;
                        }  
                    case 3:
                       {
                          cout <<"Please Input the Application ID Requirement" <<endl;
                          cin >> Score_ID;
                          if((Score_ID < 20220000) || (Score_ID> 20230000))
                          {
                            cout <<"Please Input integer number between 20220000 and 20230000"<<endl;
                            break;
                          }
                          else
                          {
                            stuList.Search(stuList, Score_ID);
                            break;
                          }
                       } 
                    case 4:
                       {
                          cout <<"Please Input the First Namr Requirement" <<endl;
                          cin >>First;
                          First = stuList.checKDomInput(First);
                          cout <<"Please Input the Last Namr Requirement" <<endl;
                          cin >>Last;
                          Last = stuList.checKDomInput(Last);
                          stuList.Search(stuList, First, Last);
                          break;
                       }
                                                                                           
                }
                cout << "If you want to see the another Domestic students satisfying some requirements. Please input y, any other char back to previous menu" << endl;
                cin >> answerL;
            }
            break;     
           }        
          case 'N':
                 {
                  char answerM;
                  cout << "If you want to see the International students satisfying some requirements. Please input y, any other char back to previous menu" << endl;
                  cin >> answerM;
                  while ((answerM == 'Y') || (answerM == 'y'))
                  {
                    cout << "1. International Students CGPA Requirement (float number between 0.00 and 4.33)"<< endl;
                    cout << "2. Research Score Requirement(integer number between 70 annd 100)" <<endl;
                    cout << "3. Application ID Requirement(integer number between 20220000 and 20230000 " <<endl;
                    cout << "4. First Name And Last Name Requirement" <<endl;
                    cout << " Please input your choice" <<endl;
                    int Choose_Int;
                    int IntScore_ID;
                    float IntC_GPA;
                    string IntFirst;
                    string IntLast;
                    cin >> Choose_Int;
                    switch(Choose_Int)
                    {
                    case 1:
                         {
                          cout <<"Please Input the CGPA Requirement" <<endl;
                          cin >> IntC_GPA;
                          if((IntC_GPA < 0) || (IntC_GPA > 4.33))
                          {
                            cout <<"Please input float number between 0.00 and 4.33"<<endl;
                            break;
                          }
                          else
                          {
                            intList.Search(intList, IntC_GPA);
                            break;
                          }
                         }
                    case 2:
                        {
                          cout <<"Please Input the Research Score Requirement" <<endl;
                          cin >> IntScore_ID;
                          intList.Search(intList, IntScore_ID);
                          break;
                        }  
                    case 3:
                       {
                          cout <<"Please Input the Application ID Requirement" <<endl;
                           cin >> IntScore_ID;
                          if((IntScore_ID < 20220000) || (IntScore_ID> 20230000))
                          {
                            cout <<"Please Input integer number between 20220000 and 20230000"<<endl;
                            break;
                          }
                          else
                          {
                            intList.Search(intList, IntScore_ID);
                            break;
                          }
                       } 
                    case 4:
                       {
                          cout <<"Please Input the First Namr Requirement" <<endl;
                          cin >>IntFirst;
                          IntFirst = intList.checKIntInput(IntFirst);
                          cout <<"Please Input the Last Namr Requirement" <<endl;
                          cin >>IntLast;
                          IntLast = intList.checKIntInput(IntLast);
                          intList.Search(intList, IntFirst, IntLast);
                          break;
                       }
                                                                                              
                }
                cout << "If you want to see the another International students satisfying some requirements. Please input y, any other char back to previous menu" << endl;
                cin >> answerM;
            }
            break;           
        }

          case 'O':
                {
                  DomesticStudent* dom_ptr=NULL, dom_stu;
                  string FN;
                  string LN, Pro;
                  float cgpa;
                  int  R_Sco;

                  cout <<"Please Input The Information Of Students" <<endl;
                  cout << "1. First Name "<<endl;
                  cin >> FN;
                  FN = stuList.checKDomInput(FN);
                  dom_stu.setFirstName(FN);
                  cout <<"2. Last Name " <<endl;
                  cin >> LN;
                  LN = stuList.checKDomInput(FN);
                  dom_stu.setLastName(FN);
                  cout <<"3. Province " <<endl;
                  cin >> Pro;
                  dom_stu.setProvince(Pro);
                  cout <<"4. CGPA" <<endl;
                  cin >> cgpa;
                  dom_stu.setCGPA(cgpa);
                  cout <<"5. Research Score"<<endl;
                  cin >> R_Sco;
                  dom_stu.setResearchScore(R_Sco);
                  dom_ptr = &dom_stu;
                  stuList.insert( dom_ptr);
                  stuList.printList();
                  stuList.Check_Provence(stuList);
                  break;
                }
        case 'P':
                {
                  InternationalStudent* int_ptr = NULL, int_stu;
                  ToeflScore grade_toef;
                  string H_FN;
                  string H_LN, H_Con;
                  float H_cgpa;
                  int  H_Sco, H_reading, H_listening, H_speaking,H_writing;
                  cout <<"Please Input The Information Of Students" <<endl;
                  cout << "1. First Name "<<endl;
                  cin >> H_FN;
                  H_FN = intList.checKIntInput(H_FN);
                  int_stu.setFirstName(H_FN);
                  cout <<"2. Last Name " <<endl;
                  cin >> H_LN;
                  H_LN = intList.checKIntInput(H_FN);
                  int_stu.setLastName(H_FN);
                  cout <<"3. Country " <<endl;
                  cin >> H_Con;
                  int_stu.setCountry(H_Con);
                  cout <<"4. CGPA" <<endl;
                  cin >> H_cgpa;
                  int_stu.setCGPA(H_cgpa);
                  cout <<"5. Research Score"<<endl;
                  cin >> H_Sco;
                  int_stu.setResearchScore(H_Sco);
                  cout <<"6.Reading"<<endl;
                  cin >>H_reading;
                  grade_toef.setReading(H_reading);
                  cout <<"7.Listening"<<endl;
                  cin >>H_listening;
                  grade_toef.setListening(H_listening);
                  cout <<"8.Speaking"<<endl;
                  cin >>H_speaking;
                  grade_toef.setSpeaking(H_speaking);
                  cout <<"9.Writing"<<endl;
                  cin >>H_writing;
                  grade_toef.setWriting(H_writing);
                  int_stu.setToeflScore(grade_toef);
                 int_ptr = &int_stu;
                 intList.insert(int_ptr);
                cout << "international students: " << endl;
 	            intList.printList();
                intList.Check_Country(intList);
                }
            case 'Q':
                {
                    char answer, Dom_int;
                    int score, subject;
                    float grade_CGPA;
                    cout << "If you want to see the detailed information of some students. Please input y, any other char to back to previous menu" << endl;
                    cin >> answer;
                    while ((answer == 'Y') || (answer == 'y'))
                    {
                      cout << "If you want to see the information of domestic students, please input D"<< endl;
                      cout << "If you want to see the information of international students, please input I"<< endl;
                      cin >> Dom_int;
                      if ( (Dom_int =='D') || (Dom_int == 'd'))
                        {
                          cout << "If you want to see the information about CGPA, please input 1" <<endl;
                          cout << "If you want to see the information about Researchscore, please input 2" <<endl;
                          cin >> subject;
                          if (subject == 1)
                           {
                            cout << "Please input the lowest of CGPA you concern"<< endl;
                             cin >> grade_CGPA;
                             stuList.requireDomCGPA(stuList, grade_CGPA);
                           }
                           if (subject == 2)
                            {
                              cout << "Please input the lowest of research score you concern"<< endl;
                              cin >> score;
                              stuList.requireDomScore(stuList, score);
                            }
                         }   
                      else if ( (Dom_int =='I') || (Dom_int == 'i') )
                        {
                        cout << "If you want to see the information about CGPA, please input 1" <<endl;
                        cout << "If you want to see the information about Researchscore, please input 2" <<endl;
                        cin >> subject;
                           if (subject == 1)
                           {
                              cout << "Please input the lowest of CGPA you concern"<< endl;
                              cin >> grade_CGPA;
                              intList.requireIntCGPA(intList, grade_CGPA);
                           }
                           if (subject == 2)
                           {
                             cout << "Please input the lowest of research score you concern"<< endl;
                             cin >> score;
                             intList.requireIntScore(intList, score);
                           }
                        }
                     else
                      {
                        cout << "The information input is wrong. please input again." <<endl;
                      } 
                     cout << "If you want to set another requirement to see the information of students. Please input y, any other char back to previous menu" << endl;
                     cin >> answer;
                    }            
                }*/
      }
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

