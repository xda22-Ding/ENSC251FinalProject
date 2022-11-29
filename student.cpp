#include "student.hpp"
/* ----------------------------Student Class------------------------------*/
int Student::BaseID = 20220000;
int Student::BasePassW = 22220000;
//Constructor
Student::Student()
{
    CGPA = 0.0;
    research_score = 0;
    app_id = BaseID;
    BaseID++;
    passW = BasePassW;
    BasePassW++;
    setPassW(passW);
    next = NULL;
}
Student::Student(string fn, string ln, float cgpa, int score)
{
    setFirstName(fn);
    setLastName(ln);
    setCGPA(cgpa);
    setResearchScore(score);
    app_id = BaseID;
    BaseID++;
    passW = BasePassW;
    BasePassW++;
    setPassW(passW);
    next = NULL;
    isValid();
}
//Getter
string Student::getFirstName() const
{
    return first_name;
}
string Student::getLastName() const
{
    return last_name;
}
int Student::getResearchScore() const
{
    return research_score;
}
float Student::getCGPA() const
{
    return CGPA;
}
int Student::getAppID() const
{
    return app_id;
}
int Student::getPassW() const
{
    return passW;
}
//Setters
void Student::setFirstName(string fn)
{
    first_name = fn;
}
void Student::setLastName(string ln)
{
    last_name = ln;
}
void Student::setCGPA(float cgpa)
{
    CGPA = cgpa;
}
void Student::setResearchScore(int score)
{
    research_score = score;
}
void Student::setPassW(int pw){
    passW = pw;
}
//Other member functions
bool Student::isValid() const
{
    if(CGPA < 0 || CGPA > 4.33)
    {
        cout << "the CGPA is invalid. " << endl;
        exit(1);
    }
    if(research_score < 0 || research_score > 100)
    {
        cout << "the research score is invalid. " << endl;
        exit(1);
    }
    if( app_id < 20220000 || app_id > 20230000 )
    {
        cout << "the application id is invalid. " << endl;
        exit(1);
    }
    return true;
}

void Student::printOutStudent(ostream &outs)
{
    outs << "Student : " <<getFirstName() << " "<< getLastName() << ". " <<"CGPA : " <<getCGPA() << " Research Score: " << getResearchScore() << " Student ID: " << getAppID() << endl;
}

ostream &operator << (ostream &out, Student stu)
{
    stu.printOutStudent(out);
    return cout;
}
/* ----------------------------Student Class------------------------------*/

/* --------------------------Domestic Student Class----------------------------*/
//Constructor
DomesticStudent::DomesticStudent()
{
    nextDom = NULL;
}
DomesticStudent::DomesticStudent(string fn, string ln, float cgpa, int score, string province):Student(fn, ln, cgpa, score)
{
    this->province = province;
    nextDom = NULL;
    isValid();
}
//Getter
string DomesticStudent::getProvince() const
{
    return province;
}
//Setter
void DomesticStudent::setProvince(string province)
{
    this->province = province;
}
//Friend functions
//when value 1 < value 2 return -1
//when value 1 == value 2 return 0
//when value 1 > value 2 return 1
int compareProvince (const DomesticStudent* stu1, const DomesticStudent* stu2)
{
    if (stu1->province > stu2->province)
        return 1;
    if (stu1->province < stu2->province)
        return 2;
    return 3;
}
ostream& operator <<(std::ostream& outs, const DomesticStudent& domesStu)
{
    outs << "Domestic Student : " <<domesStu.getFirstName() << " "<< domesStu.getLastName() <<" is from " << domesStu.getProvince() << ". " <<"CGPA : " <<domesStu.getCGPA() << " Research Score: " << domesStu.getResearchScore() << "Student ID: " << domesStu.getAppID() << endl;;
        return outs;
}

/* --------------------------Domestic Student Class----------------------------*/

/* ------------------------------ToeflScore Class--------------------------------*/
//The constructor of ToeflScore Class
ToeflScore::ToeflScore(int reading_para, int listening_para, int speaking_para, int writing_para)
{
    setReading(reading_para);
    setListening(listening_para);
    setSpeaking(speaking_para);
    setWriting(writing_para);
    total_score = reading + listening + speaking + writing;
}
//The default constructor of ToeflScore
ToeflScore::ToeflScore(){}
//The Getter and Setter of ToeflScore
int ToeflScore::getReading() const
{
    return reading;
}
int ToeflScore::getListening() const
{
    return listening;
}
int ToeflScore::getSpeaking() const
{
    return speaking;
}
int ToeflScore::getWriting() const
{
    return writing;
}
int ToeflScore::getTotalScore() const
{
    return total_score;
}
void ToeflScore::setReading(int read)
{
    reading = read;
}
void ToeflScore::setListening(int listen)
{
    listening = listen;
}
void ToeflScore::setSpeaking(int speak)
{
    speaking = speak;
}
void ToeflScore::setWriting(int write)
{
    writing = write;
}
/* ------------------------------ToeflScore Class--------------------------------*/

/* -----------------------International Student Class-------------------------*/
//Constructor
InternationalStudent::InternationalStudent()
{
    nextInt = NULL;
}
InternationalStudent::InternationalStudent(string fn, string ln, float cgpa, int score, ToeflScore toefl_score, string country):Student(fn, ln, cgpa, score)
{
    setToeflScore(toefl_score);
    setCountry(country);
    nextInt = NULL;
    isValid();
}
//Getters
ToeflScore InternationalStudent::getToeflScore() const
{
    return toefl_score;
}
string InternationalStudent::getCountry() const
{
    return country;
}
//Setters
void InternationalStudent::setToeflScore(ToeflScore toefl_score)
{
    this->toefl_score = toefl_score;
}
void InternationalStudent::setCountry(string country)
{
    this->country = country;
}
int compareCountry (const InternationalStudent* stu1, const InternationalStudent* stu2){
    if (stu1->country > stu2->country)
        return 1; //1
    if (stu1->country < stu2->country)
        return 2; //-1
    if (stu1->country == stu2->country)
        return 3; //0
    else
        return 4;
}
ostream& operator <<(std::ostream& outs, const InternationalStudent& interStu)
{
    outs << "International Student : " <<interStu.getFirstName() << " "<< interStu.getLastName() <<" is from " << interStu.getCountry() << ". " <<"CGPA : " <<interStu.getCGPA() << " Research Score: " << interStu.getResearchScore() <<" Toefl Score: reading: " <<interStu.getToeflScore().getReading() <<"; listening: "<<interStu.getToeflScore().getListening()<<"; Speaking: "<<interStu.getToeflScore().getSpeaking()<<"; Writing: "<<interStu.getToeflScore().getWriting()<<"."<< "Student ID: " << interStu.getAppID() << endl;

     return outs;
}
/* -----------------------International Student Class-------------------------*/


//Common Compare functions
//when value 1 < value 2 return -1
//when value 1 == value 2 return 0
//when value 1 > value 2 return 1
int compareCGPA(const Student &stu1, const Student &stu2)
{
    float cgpa1 = stu1.getCGPA();
    float cgpa2 = stu2.getCGPA();
    
    if (cgpa1 < cgpa2)
        return 2;
    if (cgpa1 > cgpa2)
        return 1;
    return 3;
}
int compareResearchScore(const Student &stu1, const Student &stu2)
{
    int rs1 = stu1.getResearchScore();
    int rs2 = stu2.getResearchScore();
    
    if (rs1 < rs2)
        return 2;
    if (rs1 > rs2)
        return 1;
    return 3;
}
//in this case, we assum all the name is in the correct format
int compareFirstName(const Student &stu1, const Student &stu2)
{
    string l1 = stu1.getFirstName();
    string l2 = stu1.getFirstName();
    
    if (l1 < l2)
        return 2;
    if (l1 > l2)
        return 1;
    return 3;
}
int compareLastName(const Student &stu1, const Student &stu2)
{
    string l1 = stu1.getLastName();
    string l2 = stu1.getLastName();
    
    if (l1 < l2)
        return 2;
    if (l1 > l2)
        return 1;
    return 3;
}


