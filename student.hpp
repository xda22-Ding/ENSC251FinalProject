#ifndef student_hpp
#define student_hpp

#include <string> //you will have to use string in C++
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Student
{
public:
    Student* next ;
    //Constructors
    Student(string fn, string ln, float cgpa, int score);
    Student();
    //Getters
    string getFirstName() const;
    string getLastName() const;
    float getCGPA() const;
    int getResearchScore() const;
    int getAppID() const;
    int getPassW() const;
    //Setters
    void setFirstName(string fn);
    void setLastName(string ln);
    void setCGPA(float cgpa);
    void setResearchScore(int score);
    void setID (int ID);
    void setPassW(int pw);
    //Other member functions
    bool isValid() const;
    void printOutStudent (ostream &outs);
    friend ostream &operator<< (ostream &out, Student stu);
    
private:
    string first_name;
    string last_name;
    float CGPA;
    int research_score;
    int app_id;
    static int BaseID;//Every time a student class is created, BaseID += 1
    int passW;
    static int BasePassW;
};

class DomesticStudent : public Student
{
public:
    DomesticStudent* nextDom;
    //Constructor
    DomesticStudent(string fn, string ln, float cgpa, int score, string province);
    DomesticStudent();
    //Getter
    string getProvince() const;
    //Setter
    void setProvince(string province);
    //Friend Functions
    friend int compareProvince (const DomesticStudent* stu1, const DomesticStudent* stu2);
    friend ostream& operator <<(ostream& outs, const DomesticStudent& domesStu);
    
private:
    string province;
};

class ToeflScore
{
public:
    //The constructor of ToeflScore Class
    ToeflScore(int reading_para, int listening_para, int speaking_para, int writing_para);
    //The default constructor of ToeflScore
    ToeflScore();
    //Getters
    int getReading() const;
    int getListening() const;
    int getSpeaking() const;
    int getWriting() const;
    int getTotalScore() const;
    //Setters
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
    //Constructors
    InternationalStudent(string fn, string ln, float cgpa, int score, ToeflScore toefl_score, string country);
    InternationalStudent();
    //Getters
    ToeflScore getToeflScore() const;
    string getCountry() const;
    //Setters
    void setToeflScore(ToeflScore toefl_score);
    void setCountry(string country);
    //overload operator
    friend int compareCountry (const InternationalStudent* stu1, const InternationalStudent* stu2);
    friend ostream& operator <<(ostream& outs, const InternationalStudent& interStu);
    
private:
    string country;
    ToeflScore toefl_score;
};


//Commen compare functions
//when value 1 < value 2 return -1
//when value 1 == value 2 return 0
//when value 1 > value 2 return 1
int compareCGPA(const Student &stu1, const Student &stu2);
int compareResearchScore(const Student &stu1, const Student &stu2);
int compareFirstName(const Student &stu1, const Student &stu2);
int compareLastName(const Student &stu1, const Student &stu2);
#endif /* student_hpp */
