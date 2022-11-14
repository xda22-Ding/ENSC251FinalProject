//student.cpp to implement your classes
#include "student.hpp"
#include<iostream>
#include <iomanip>
using namespace std;

//The constructor of student class
Student::Student(string fn, string ln, float cgpa, int score, int APPID){
    setFirstName(fn);
    setLastName(ln);
    setCGPA(cgpa);
    setResearchScore(score);
    setAppID(APPID);
    isValid();
}

//The default constructor of student class
Student::Student(){};

//Check if the fields of Student object meet certain requirements.
bool Student::isValid() const{
	if(CGPA < 0 || CGPA > 4.33){
		cout << "the CGPA is invalid. " << endl;
		return false;
	}
	if(research_score < 0 || research_score > 100){
		cout << "the research score is invalid. " << endl;
		return false;
	}
	if( app_id < 20220000 || app_id > 20230000 ){
		cout << "the application id is invalid. " << endl;
		return false;
	}
	else{
		return true;
	}
}

//getter and setter of member variables
string Student::getFirstName() const{
	return first_name;
}

string Student::getLastName() const{
	return last_name;
}

float Student::getCGPA() const{
	return CGPA;
}

int Student::getResearchScore() const{
	return research_score;
}

int Student::getAppID() const{
	return app_id;
}


void Student::setFirstName(string fn){
	first_name = fn;
}

void Student::setLastName(string ln){
	last_name = ln;
}

void Student::setCGPA(float cgpa){
	CGPA = cgpa;
}

void Student::setResearchScore(int score){
	research_score = score;
}

void Student::setAppID(int APPID){
	app_id = APPID;
}


//The constructor of ToeflScore Class
ToeflScore::ToeflScore(int reading_para, int listening_para, int speaking_para, int writing_para){
	setReading(reading_para);
	setListening(listening_para);
	setSpeaking(speaking_para);
	setWriting(writing_para);
	total_score = reading + listening + speaking + writing;

}

//The default constructor of ToeflScore
ToeflScore::ToeflScore(){}


//The Getter and Setter of ToeflScore
int ToeflScore::getReading() const{
	return reading;
}

int ToeflScore::getListening() const{
	return listening;
}

int ToeflScore::getSpeaking() const{
	return speaking;
}

int ToeflScore::getWriting() const{
	return writing;
}

int ToeflScore::getTotalScore() const{
	return total_score;
}

void ToeflScore::setReading(int read){
	reading = read;
}

void ToeflScore::setListening(int listen){
	listening = listen;
}

void ToeflScore::setSpeaking(int speak){
	speaking = speak;
}

void ToeflScore::setWriting(int write){
	writing = write;
}

// compare functions: 1.greater than 2.less than 3.equal to 4.invalid
int compareCGPA (const Student& stu1, const Student& stu2){
	if (stu1.CGPA > stu2.CGPA)
		return 1; // student1 is greater than student2
	if (stu1.CGPA < stu2.CGPA)
		return 2; // student1 is less than student2
	if (stu1.CGPA == stu2.CGPA)
		return 3; // student 1 is equal to student2
        else
		return 4; // invalid

}

int compareResearchScore (const Student& stu1, const Student& stu2) {
	if (stu1.research_score > stu2.research_score)
		return 1; // student1 is greater than student2
	if (stu1.research_score < stu2.research_score)
		return 2; // student1 is less than student2
	if (stu1.research_score == stu2.research_score)
		return 3; // student 1 is equal to student2
        else
  		return 4; // invalid

}
// comparing name by alphabet
int compareFirstName (const Student& stu1, const Student& stu2) {
	if (stu1.first_name > stu2.first_name)
		return 1;
	if (stu1.first_name < stu2.first_name)
		return 2;
	if (stu1.first_name == stu2.first_name)
		return 3;
	else
		return 4;

}
int compareLastName (const Student& stu1, const Student& stu2) {
	if (stu1.last_name > stu2.last_name)
		return 1;
	if (stu1.last_name < stu2.last_name)
		return 2;
	if (stu1.last_name == stu2.last_name)
		return 3;
	else
		return 4;

}

int compareCountry (const InternationalStudent& stu1, const InternationalStudent& stu2){
	if (stu1.country > stu2.country)
		return 1;
	if (stu1.country < stu2.country)
		return 2;
	if (stu1.country == stu2.country)
		return 3;
	else
		return 4;

}

int compareProvince (const DomesticStudent& stu1, const DomesticStudent& stu2) {
	if (stu1.province > stu2.province)
		return 1;
	if (stu1.province < stu2.province)
		return 2;
	if (stu1.province == stu2.province)
		return 3;
	else
		return 4;
}


//The constructor of Inheritted class InternationalStudent Class
InternationalStudent::InternationalStudent(string fn, string ln, float cgpa, int score, int APPID, ToeflScore toeflscore_para, string country_para){
    setFirstName(fn);
    setLastName(ln);
    setCGPA(cgpa);
    setResearchScore(score);
    setAppID(APPID);
    setToeflScore(toeflscore_para);
    setCountry(country_para);

}

//The default constructor of InternationalStudent Class
InternationalStudent::InternationalStudent(){}

ToeflScore InternationalStudent::getToeflScore() const{
	return toefl_score;
}

string InternationalStudent::getCountry() const{
	return country;
}

void InternationalStudent::setToeflScore(ToeflScore toeflscore_para){
	toefl_score = toeflscore_para;
}

void InternationalStudent::setCountry(string country_para){
	country = country_para;
}

//The constructor of Inheritted class DomesticlStudent Class
DomesticStudent::DomesticStudent(string fn, string ln, float cgpa, int score, int APPID, string province_para){
    setFirstName(fn);
    setLastName(ln);
    setCGPA(cgpa);
    setResearchScore(score);
    setAppID(APPID);
    setProvince(province_para);
}

DomesticStudent::DomesticStudent(){}

string DomesticStudent::getProvince() const{
	return province;
}

void DomesticStudent::DomesticStudent::setProvince(string province_para){
	province = province_para;
}

//overload international student operator
std::ostream& operator <<(std::ostream& outs, const InternationalStudent& interStu){
	
        outs << "International Student : " <<interStu.getFirstName() << " "<< interStu.getLastName() <<"is from " << interStu.getCountry() << ". " <<"CGPA : " <<interStu.getCGPA() << " Research Score: " << interStu.getResearchScore() <<" Toefl Score: reading: " <<interStu.getToeflScore().getReading() <<"; listening: "<<interStu.getToeflScore().getListening()<<"; Speaking: "<<interStu.getToeflScore().getSpeaking()<<"; Writing: "<<interStu.getToeflScore().getWriting()<<"."<< endl;

 	return outs;

}

//overload domestic student operator
std::ostream& operator <<(std::ostream& outs, const DomesticStudent& domesStu){
	
	outs << "Domestic Student : " <<domesStu.getFirstName() << " "<< domesStu.getLastName() <<"is from " << domesStu.getProvince() << ". " <<"CGPA : " <<domesStu.getCGPA() << " Research Score: " << domesStu.getResearchScore() << endl;
        return outs;
}
