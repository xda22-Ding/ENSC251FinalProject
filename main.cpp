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
     cout <<"  J for stop" << endl;   
     cin >> choose;
     
     if(choose > 'I' || choose < 'A')
     {
       cout << "Please write number between A and I" << endl;
       exit(1);
     }
     if(choose == 'J')
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

