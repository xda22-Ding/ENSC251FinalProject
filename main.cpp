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

    	tempStud->setFirstName(firstName);
   
   

    	//get lastName separated by comma
    	getline(ss, lastName, ',');
    	tempStud->setLastName(lastName);
   

    	//get province separated by comma
    	getline(ss, province, ',');
    	tempStud->setProvince(province);
   

    	//get cpga separated by comma, and convert string to float
    	getline(ss, s_cgpa, ',');
    	cgpa = atof(s_cgpa.c_str());
    	tempStud->setCGPA(cgpa);
   
   
    	//get researchScore separated by comma, and convert it to int
    	getline(ss, s_researchScore, ',');
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
    	tempStud->setFirstName(firstName);
   
   

    	//get lastName separated by comma
    	getline(ss, lastName, ',');
    	tempStud->setLastName(lastName);
   

    	//get country separated by comma
    	getline(ss, country, ',');
    	tempStud->setCountry(country);
   

    	//get cpga separated by comma, and convert string to float
    	getline(ss, s_cgpa, ',');
    	cgpa = atof(s_cgpa.c_str());
    	tempStud->setCGPA(cgpa);
   
   
    	//get researchScore separated by comma, and convert it to int
    	getline(ss, s_researchScore, ',');
    	researchScore = atoi(s_researchScore.c_str());
    	tempStud->setResearchScore(researchScore);

    	ToeflScore* tempToefl;
    	tempToefl = new ToeflScore;

   		getline(ss, s_read, ',');
    	read = atof(s_read.c_str());
    	if(read < 20) 
    		drop_flag = true;
    	tempToefl->setReading(read);
   
    	getline(ss, s_listen, ',');
    	listen = atof(s_listen.c_str());
    	if(listen < 20) 
    		drop_flag = true;
    	tempToefl->setListening(listen);
   
    	getline(ss, s_speak, ',');
    	speak = atof(s_speak.c_str());
    	if(speak < 20) 
    		drop_flag = true;
    	tempToefl->setSpeaking(speak);
   
    	getline(ss, s_write, ',');
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


 	cout << "domestic students: " << endl;
 	stuList.printList();



}