//header file student.hpp to declare your classes
#ifndef STUDENT
#define STUDENT
#include <string> //you will have to use string in C++
#include<iostream>
class Student 
{
public:
	Student* next ;
	//The constructor of student class
	Student(std::string fn, std::string ln, float cgpa, int score, int APPID);
	//The default constructor of student class
	Student();
    bool isValid() const;
    //getter and setter of member variables
    std::string getFirstName() const;
    std::string getLastName() const;
    float getCGPA() const;
    int getResearchScore() const;
    int getAppID() const;



    void setFirstName(std::string fn);
    void setLastName(std::string ln);
    void setCGPA(float cgpa);
    void setResearchScore(int score);
    void setAppID(int APPID);



    // compare student's cgpa, research score, name, country and province
    friend int compareCGPA (const Student* stu1, const Student* stu2);
    friend int compareResearchScore (const Student* stu1, const Student* stu2);
    friend int compareFirstName (const Student* stu1, const Student* stu2);
    friend int compareLastName (const Student* stu1, const Student* stu2);


private:
	std::string first_name;
	std::string last_name;
	float CGPA; 
	int research_score;
	int app_id;
  
};

class ToeflScore
{
public:
	//The constructor of ToeflScore Class
	ToeflScore(int reading_para, int listening_para, int speaking_para, int writing_para);
	//The default constructor of ToeflScore
	ToeflScore();
	//The Getter and Setter of ToeflScore
	int getReading() const;
	int getListening() const;
	int getSpeaking() const;
	int getWriting() const;
	int getTotalScore() const;

	void setReading(int read);
	void setListening(int listen);
	void setSpeaking(int speak);
	void setWriting(int write);




private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total_score;


};


class InternationalStudent : public Student
{
public:
	InternationalStudent* nextInt;
	//The constructor of Inheritted class InternationalStudent Class
	InternationalStudent(std::string fn, std::string ln, float cgpa, int score, int APPID, ToeflScore toefl_score, std::string country);
	InternationalStudent();
	ToeflScore getToeflScore() const;
	std::string getCountry() const;
	void setToeflScore(ToeflScore toefl_score);
	void setCountry(std::string country);
        
	//compare
	friend int compareCountry (const InternationalStudent* stu1, const InternationalStudent* stu2);
	//overload operator
	friend std::ostream& operator <<(std::ostream& outs, const InternationalStudent& interStu);
private:
	std::string country;
	ToeflScore toefl_score;

};

class DomesticStudent : public Student
{
public:
	DomesticStudent* nextDom;
	//The constructor of Inheritted class DomesticlStudent Class
	DomesticStudent(std::string fn, std::string ln, float cgpa, int score, int APPID, std::string province);
	DomesticStudent();
	std::string getProvince() const;
	void setProvince(std::string province);
       
       //compare
       friend int compareProvince (const DomesticStudent* stu1, const DomesticStudent* stu2);
       //overload operator
       friend std::ostream& operator <<(std::ostream& outs, const DomesticStudent& domesStu);
private:
	std::string province;

};
#endif//STUDENT



