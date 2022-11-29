#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
#include <cmath>
#include <fstream> 
#include <sstream>
using namespace std;

/*--------------Student Linked List----------------*/

Students::Students()
{
    TopStudent = NULL;
    lastStudent = NULL;
}
Student* Students:: getTop()
{
    return TopStudent;
}
Student* Students:: getlast()
{
    return lastStudent;
}
void Students::insertMix(Student* stud)
{
    if(TopStudent==NULL){
        TopStudent = stud;
        lastStudent = stud;
    }
    else{
        Student* tempStud = TopStudent;
        if(compareResearchScore(*stud,*tempStud) == 1){
            stud->next = tempStud;
            TopStudent = stud;
            return;
        }
        else if(compareResearchScore(*stud,*tempStud) == 3){
            if(compareCGPA(*stud,*tempStud) == 1){
                stud->next = tempStud;
                TopStudent = stud;
                return;
            }
        }



        while(tempStud != lastStudent ){
            if(compareResearchScore(*stud,*tempStud->next) == 1){
                stud->next = tempStud->next;
                tempStud->next = stud;
                return;
            }
            else if(compareResearchScore(*stud,*tempStud->next) == 3){
                if(compareCGPA(*stud,*tempStud->next) == 1){
                    stud->next = tempStud->next;
                    tempStud->next = stud;
                    return;
                }
            }
            tempStud = tempStud -> next;
        }
        if(tempStud == lastStudent){
            tempStud->next = stud;
            lastStudent = stud;
        }

    }
    lastStudent->next = NULL;

}
//This function search the threshold of cpga and research socre and print out the valid results.
void Students::searchThreshold(float cgpaThreshold, int researchThreshold)
{
    Student* tempptr = TopStudent;
    while (tempptr != NULL)
    {
        if (tempptr->getResearchScore() >= researchThreshold)
        {
            if (tempptr->getCGPA() >= cgpaThreshold)
                cout << *tempptr << endl;
        }
        else
            return;
        tempptr = tempptr->next;
    }
}
void Students::printList()
{
    Student* tempStud = TopStudent;
    while(tempStud != NULL)
    {
        cout << *tempStud << endl;
        tempStud = tempStud->next;
    }
}

void Students::dataSummary(){
    Student* tempStud = TopStudent;
    int totalStudent = 0;
    float CGPAsum = 0;
    float CGPAmean =0;
    float stdCGPA = 0;
    float researchScoresum =0;
    float researchScoremean = 0;
    float stdRS = 0;
    tempStud = TopStudent;
    while(tempStud != NULL)
    {
        CGPAsum = CGPAsum + tempStud->getCGPA();
        researchScoresum = researchScoresum + tempStud->getResearchScore();
        totalStudent++;
        tempStud = tempStud->next;
    }

    CGPAmean = CGPAsum/totalStudent;
    researchScoremean = researchScoresum/totalStudent;
    tempStud = TopStudent;
    while(tempStud != NULL)
    {
        stdCGPA += pow(tempStud->getCGPA() - CGPAmean, 2);
        stdRS += pow(tempStud->getResearchScore() - researchScoremean, 2);
        tempStud = tempStud->next;
    }
    stdCGPA = sqrt(stdCGPA/totalStudent);
    stdRS = sqrt(stdRS/totalStudent);
    cout << "The mean of CGPA is: " << CGPAmean << "; The standard deviation of CGPA is " <<stdCGPA << endl;
    cout << "The mean of Research Score is: " << researchScoremean << "; The standard deviation of Research Score is " << stdRS << endl;


}

/*--------------Student Linked List----------------*/

/*------------Domestic Student Linked List----------------*/
domStudents::domStudents(){
    TopStudent = NULL;
    lastStudent = NULL;
}

void domStudents::insert(DomesticStudent* stud){
    if(TopStudent==NULL){
        TopStudent = stud;
        lastStudent = stud;
    }
    else{
        //Compare the inserted student with the first student.
        DomesticStudent* tempStud = TopStudent;
        if(compareResearchScore(*stud,*tempStud) == 1){
            stud->nextDom = tempStud;
            TopStudent = stud;
            return;
        }
        else if(compareResearchScore(*stud,*tempStud) == 3){
            if(compareCGPA(*stud,*tempStud) == 1){
                stud->nextDom = tempStud;
                TopStudent = stud;
                return;
            }
            else if(compareCGPA(*stud,*tempStud) == 3){
                if(compareProvince(stud,tempStud) == 1){
                    stud->nextDom = tempStud;
                    TopStudent = stud;
                    return;
                }
            }
        }


        //compare the inserted student with the rest of students in the linked list.
        while(tempStud != lastStudent ){
            if(compareResearchScore(*stud,*tempStud->nextDom) == 1){
                stud->nextDom = tempStud->nextDom;
                tempStud->nextDom = stud;
                return;
            }
            else if(compareResearchScore(*stud,*tempStud->nextDom) == 3){
                if(compareCGPA(*stud,*tempStud->nextDom) == 1){
                    stud->nextDom = tempStud->nextDom;
                    tempStud->nextDom = stud;
                    return;
                }
                else if(compareCGPA(*stud,*tempStud->nextDom) == 3){
                    if(compareProvince(stud,tempStud->nextDom) == 1){
                        stud->nextDom = tempStud->nextDom;
                        tempStud->nextDom = stud;
                        return;
                    }
                }
            }
            tempStud = tempStud -> nextDom;
        }
        if(tempStud == lastStudent){
            tempStud->nextDom = stud;
            lastStudent = stud;
        }

    }

}

void domStudents::printList(){
    DomesticStudent* tempStud = TopStudent;
    while(tempStud != NULL){
        cout << *tempStud << endl;
        tempStud = tempStud->nextDom;
    }
}

DomesticStudent* domStudents:: getTop( )
{
   return TopStudent;
}

 DomesticStudent* domStudents::getlast( )
{
   return lastStudent;
}


// To print all information of domestic student with the same CGPA(target)
 void domStudents:: Search(domStudents head, float target)
{
   // Set pointer "here" to point the top of linked list of domestic student
   DomesticStudent* here = head.getTop();
   int count =0; // Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     // Search whole linked list to check if or not have target
     while (here != NULL)
     {
            if(abs(here->getCGPA() - target) < 0.01 )// The condtion to judge if or not exist the required target
           {
              count =count +1;
              cout << *here << endl;
           }
          here = here->nextDom;
     }
     if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
   }
}

// To print all information of domestic student with the same application ID(target) or research score(target)
void domStudents::Search(domStudents head, int target)
{
    // Set pointer "here" to point the top of linked list of domestic student
   DomesticStudent* here = head.getTop();
   int count =0; //Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      if (target > 100000) // To check if or not exist requied application ID in the linked list
        {
       while (here != NULL)
        {
           if(here->getAppID() == target)
                   {
                      count =count +1;
              cout << *here << endl;
                   }
         here = here->nextDom;
          }
          }
    else // To check if or not exist requied research score in the linked list
       {
         while (here != NULL)
       {
           if(here->getResearchScore() == target)
                {
                  count =count +1;
          cout << *here << endl;
                }
          here = here->nextDom;
       }
        }
      }
    if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
}

void domStudents:: Search (domStudents head,string FirstName, string LastName)
{
   DomesticStudent* here = head.getTop();
   domStudents Case;
   int count =0;
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      while (here != NULL)
    {
           if((here->getFirstName() == Case.checKDomInput(FirstName)) && (here->getLastName()== Case.checKDomInput(LastName)))
             {
                count =count +1;
        cout << *here << endl;
             }
          here = here->nextDom;
     }
    }
    if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
   }

DomesticStudent* domStudents:: Search1 (domStudents head,string FirstName, string LastName)
{
   DomesticStudent* here = head.getTop();
   domStudents Case;
   int count =0;
   if(here == NULL)
   {
     return NULL;
   }
   else
   {
      while (here != NULL)
    {
           if((here->getFirstName() == Case.checKDomInput(FirstName)) && (here->getLastName()== Case.checKDomInput(LastName)))
             {
                count =count +1;
        return here;
             }
          here = here->nextDom;
     }
     return NULL;
    }
    if ( count ==0 )
     {
       return NULL;
     }
   }



// 2 e delete base on name
void domStudents::deleteDom(string fn, string ln){
   domStudents Case;
   DomesticStudent* before = TopStudent;
   DomesticStudent* current = TopStudent->nextDom;
   int count = 0;

   //special cases1: the list is empty
   if (TopStudent == NULL){
        cout<<"empty list"<<endl;
        return;
   }

   //special cases2: delete the first student
   if ((before->getFirstName() == Case.checKDomInput(fn)) && (before->getLastName()== Case.checKDomInput(ln))){
        TopStudent = TopStudent->nextDom;
        //DomesticStudent* temp->nextDom = before;
        //before = before->nextDom;
        delete before;
        count = count + 1;
        //return;
        
   }


   //normal cases

   while (current != lastStudent->nextDom){
//cout<< "test 3"<< endl;
        if ((current->getFirstName() == Case.checKDomInput(fn)) && (current->getLastName()== Case.checKDomInput(ln))){
            //cout<<"test2"<<endl;
            before->nextDom = current->nextDom;
            
            delete current;
            count = count + 1;
           }
        before = before->nextDom;
        current = current->nextDom;
   }


   if (count == 0){
    cout << "No such student"<< endl;
   }
  
}


//2 f delete head and tail
void domStudents::deleteDom(){
    DomesticStudent* temp;
    DomesticStudent* secondL = TopStudent;
    if(TopStudent == NULL){
            cout<<"Invalid Pointer"<<endl;
      }
        if(TopStudent->nextDom == NULL){
            delete TopStudent;
       }
      //delete first node
      else {
             temp = TopStudent;
             TopStudent = TopStudent->nextDom;
             delete temp;

      }
    //delete last
    if(lastStudent == NULL){
        delete lastStudent;
    }else{
        
        while(secondL->nextDom->nextDom != NULL)
            secondL = secondL->nextDom;
            
        delete(secondL->nextDom);
        secondL->nextDom = NULL;
    }
}

//Part2 Q2
string domStudents::checKDomInput(string name){
  char c;

  for (int i = 0; i < name.size(); i++){
    c = name[i];
    //make every letter to lower case
    if (isupper(c)){
        name[i] = tolower(c);
    }else
        name[i] = name[i];
    
  }
  //make the first letter to upper case
  name[0] = toupper(name[0]);

  return name;
}

//check if password mathces ID (innovation3)
bool domStudents::isVerified(int ID, int PW) const{
    DomesticStudent* Stud = TopStudent;
    while(Stud != lastStudent->nextDom)
    {
        if(Stud->getAppID() == ID && Stud->getPassW() == PW){
		return true;
        }
	Stud = Stud->nextDom;
    }
    return false;
}

//reset password
void domStudents::resetPW(int id, int pw){
    DomesticStudent* Stud = TopStudent;
    while(Stud != lastStudent->nextDom)
    {
        if(Stud->getAppID() == id){
            Stud->setPassW(pw);
        }
	    Stud = Stud->nextDom;
    }
}

// Part2 3
void domStudents::Check_Provence(domStudents head)
{
    DomesticStudent* here = head.getTop();
    bool flag =false;
   int count =0; //Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
    while (here != NULL)
      {
        int len;
        string tempStr, provenceStr;
     
        provenceStr = here->getProvince();
        for ( len  = 0; len < provenceStr.length(); len++)
        {
               provenceStr[len]=toupper(provenceStr[len]);
        }
        tempStr = provenceStr;
        if ((tempStr == "NL") || (tempStr == "NS") || (tempStr == "NB") || (tempStr == "PE") || 
             (tempStr == "QC") || (tempStr == "ON") || (tempStr == "MB") || (tempStr == "SK") || 
             (tempStr == "AB") || (tempStr == "BC") || (tempStr == "YT") || (tempStr == "NT") || (tempStr == "NU"))
           {
            flag = false;
           }
        else
        {
            cout<< "The item contains a wrong record." << endl;
            cout << *here << endl;
            flag= true;
            exit(1);
        }
       
        here = here->nextDom;
    }
 if (flag == false)
        {
            cout <<" All records about the proviences are correct."<< endl;
        }

   }  
}

// innovation 2
void domStudents::requireDomCGPA(domStudents head, float target)
{
     DomesticStudent* here = head.getTop();
   int count =0; // Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     // Search whole linked list to check if or not have target
     while (here != NULL)
     {
            if( here->getCGPA() >= target )// The condtion to judge if or not exist the required target
           {
              count =count +1;
              cout << *here << endl;
           }
          here = here->nextDom;
     }
     if ( count ==0 )
     {
       cout<<"The domestic students satisfied the requirements do noe exist." <<endl;
     }
   }
}

//innovation 2
void domStudents::requireDomScore(domStudents head, int target)
{
    DomesticStudent* here = head.getTop();
   int count =0; // Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     // Search whole linked list to check if or not have target
     while (here != NULL)
     {
            if( here->getResearchScore() >= target )// The condtion to judge if or not exist the required target
           {
              count =count +1;
              cout << *here << endl;
           }
          here = here->nextDom;
     }
     if ( count ==0 )
     {
       cout<<"The domestic students satisfied the requirements do noe exist." <<endl;
     }
   }
}


/*------------Domestic Student Linked List----------------*/

/*------------International Student Linked List----------------*/
intStudents::intStudents(){
    TopIntStudent = NULL;
    lastIntStudent = NULL;
}

void intStudents::insert(InternationalStudent* stud){
    ToeflScore tempToefl = stud->getToeflScore();
    int reading = tempToefl.getReading();
    int listening = tempToefl.getListening();
    int speaking = tempToefl.getSpeaking();
    int writing = tempToefl.getWriting();
    int total = reading+listening+speaking+writing;

    if((reading>=20) && (writing>=20) && (listening>=20) && (speaking>=20)  && (total>=93)){
 
    if(TopIntStudent==NULL){
        TopIntStudent = stud;
        lastIntStudent = stud;
    }
    else{
        InternationalStudent* tempIntStud = TopIntStudent;
        if(compareResearchScore(*stud,*tempIntStud) == 1){
            stud->nextInt = tempIntStud;
            TopIntStudent = stud;
            return;
        }
        else if(compareResearchScore(*stud,*tempIntStud)==3){
            if(compareCGPA(*stud,*tempIntStud) == 1){
                stud->nextInt = tempIntStud;
                TopIntStudent = stud;
                return;
            }
            else if(compareCGPA(*stud,*tempIntStud) == 3){
                if(compareCountry(stud,tempIntStud) == 1){
                    stud->nextInt = tempIntStud;
                    TopIntStudent = stud;
                    return;
                }
            }

        }


        while(tempIntStud != lastIntStudent ){
            if(compareResearchScore(*stud,*tempIntStud->nextInt) == 1){
                stud->nextInt = tempIntStud->nextInt;
                tempIntStud->nextInt = stud;
                break;
            }
            else if(compareResearchScore(*stud,*tempIntStud->nextInt) == 3){
                if(compareCGPA(*stud,*tempIntStud->nextInt) == 1){
                    stud->nextInt = tempIntStud->nextInt;
                    tempIntStud->nextInt = stud;
                    break;
                }
                else if(compareCGPA(*stud,*tempIntStud->nextInt) == 3){
                    if(compareCountry(stud,tempIntStud->nextInt) == 1){
                        stud->nextInt = tempIntStud->nextInt;
                        tempIntStud->nextInt = stud;
                        break;
                    }
                }
            }


            tempIntStud = tempIntStud -> nextInt;
        }
        if(tempIntStud == lastIntStudent){
            tempIntStud->nextInt = stud;
            lastIntStudent = stud;
        }

    }
}
else{
    cout << "The student does not meet the TOEFL requirements" << endl;
}

}

void intStudents::printList(){
    InternationalStudent* tempIntStud = TopIntStudent;
    while(tempIntStud != NULL){
        cout << *tempIntStud << endl;
        tempIntStud = tempIntStud->nextInt;
    }
}

InternationalStudent* intStudents:: getTop( )
{
   return TopIntStudent;
}

 InternationalStudent* intStudents::getlast( )
{
   return lastIntStudent;
}

void intStudents:: Search(intStudents head, float target)
{
   InternationalStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     while (here != NULL)
     {
        if(abs(here->getCGPA() - target) < 0.01 )
            {
              count =count +1;
          cout << *here << endl;
            }
       here = here->nextInt;
     }
      if ( count ==0 )
        {
          cout<<"Information here not found" <<endl;
        }
   }
}

void intStudents::Search(intStudents head, int target)
{
   InternationalStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      if (target > 100000)
        {
          while (here != NULL)
        {
            if(here->getAppID() == target)
               {
                  count =count +1;
          cout << *here << endl;
                }
            here = here->nextInt;
        }
         }
    else
       {
          while (here != NULL)
         {
         if(here->getResearchScore() == target)
                {
                   count =count +1;
           cout << *here << endl;
                }
        here = here->nextInt;
        }
        }
     }
    if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
}

void intStudents:: Search (intStudents head,string FirstName, string LastName)
{
   intStudents Case; 
   InternationalStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      while (here != NULL)
    {
           if((here->getFirstName() == Case.checKIntInput(FirstName)) && (here->getLastName()== Case.checKIntInput(LastName)))
              {
                 count =count +1;
         cout << *here << endl;
              }
             here = here->nextInt;
        }
    }
       
     if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
   }

InternationalStudent* intStudents:: Search1(intStudents head,string FirstName, string LastName)
{
   intStudents Case; 
   InternationalStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
         return NULL;
   }
   else
   {
      while (here != NULL)
    {
           if((here->getFirstName() == Case.checKIntInput(FirstName)) && (here->getLastName()== Case.checKIntInput(LastName)))
              {
                 count =count +1;
         return here;
              }
             here = here->nextInt;
        }
        return NULL;
    }
       
     if ( count ==0 )
     {
       return NULL;
     }
   }




int domStudents::totalStudent(){
    DomesticStudent* tempStud = TopStudent;
    int total = 0;
    while(tempStud != NULL){
        total++;
        tempStud = tempStud->nextDom;
    }
    return total;
}

float domStudents::rankStudent(DomesticStudent* objectStud){
    DomesticStudent* tempStud = TopStudent;
    int rank = 1;
    while(tempStud != objectStud){
        rank++;
        tempStud = tempStud -> nextDom;
    }
    int total = totalStudent();
    float result = (float) rank/ (float) total;
    return result;


}


int intStudents::totalStudent(){
    InternationalStudent* tempIntStud = TopIntStudent;
    int total = 0;
    while(tempIntStud != NULL){
        total++;
        tempIntStud = tempIntStud->nextInt;
    }

    return total;
}

float intStudents::rankStudent(InternationalStudent* objectStud){
    InternationalStudent *tempStud = TopIntStudent;
    int rank = 1;
    while(tempStud != objectStud){
        rank++;
        tempStud = tempStud->nextInt;
    }
    int total = totalStudent();
    float result = (float) rank/ (float) total;
    return result;


}


//Merge function, merge one international student and one domestic student and return a student linked list
Students mergeList(domStudents &dList, intStudents &iList)
{
    Students stuList;
    DomesticStudent* dom_ptr = dList.getTop();
    InternationalStudent* int_ptr = iList.getTop();
    while (dom_ptr != NULL)
    {
        stuList.insertMix(dom_ptr);
        dom_ptr = dom_ptr->nextDom;
    }
    while (int_ptr != NULL)
    {
        stuList.insertMix(int_ptr);
        int_ptr = int_ptr->nextInt;
    }
    return stuList;
}

// 2 e
void intStudents::deleteInt(string fn, string ln){
   intStudents Case;
   InternationalStudent* before = TopIntStudent;
   InternationalStudent* current = TopIntStudent->nextInt;
   int count = 0;

   //special cases1: the list is empty
   if (TopIntStudent == NULL){
        cout<<"empty list"<<endl;
        return;
   }

   //special cases2: delete the first student
   if ((before->getFirstName() == Case.checKIntInput(fn)) && (before->getLastName()== Case.checKIntInput(ln))){
        TopIntStudent = TopIntStudent->nextInt;
        //DomesticStudent* temp->nextDom = before;
        //before = before->nextDom;
        delete before;
        count = count +1;
        //return;
   }


   //normal cases

   while (current != lastIntStudent->nextInt){

        if ((current->getFirstName() == Case.checKIntInput(fn)) && (current->getLastName()== Case.checKIntInput(ln))){
            
            before->nextInt = current->nextInt;
            
            delete current;
            count = count + 1;
           }
        before = before->nextInt;
        current = current->nextInt;
   }


   if (count == 0){
    cout << "No such student"<< endl;
   }
  
}


//2 f
void intStudents::deleteInt(){
    InternationalStudent* temp;
    InternationalStudent* secondL = TopIntStudent;
    if(TopIntStudent == NULL){
            cout<<"Invalid Pointer"<<endl;
      }
        if(TopIntStudent->nextInt == NULL){
            delete TopIntStudent;
       }
      //delete first
      else {
             temp = TopIntStudent;
             TopIntStudent = TopIntStudent->nextInt;
             delete temp;

      }
    //delete last
    if(lastIntStudent == NULL){
        delete lastIntStudent;
    }else{
        
        while(secondL->nextInt->nextInt != NULL)
            secondL = secondL->nextInt;
            
        delete(secondL->nextInt);
        secondL->nextInt = NULL;
    }
}

//Part2 Q2
string intStudents::checKIntInput(string name){
  int i;
  char c;

  for (int i = 0; i < name.size(); i++){
    c = name[i];
    //make every letter to lower case
    if (isupper(c)){
        name[i] = tolower(c);
    }else
        name[i] = name[i];
    
  }
  //make the first letter to upper case
  name[0] = toupper(name[0]);

  return name;
}

//check if password mathces ID (innovation3)
bool intStudents::isVerified(int ID, int PW) const{
    InternationalStudent* Stud = TopIntStudent;
    while(Stud != lastIntStudent->nextInt)
    {
        if(Stud->getAppID() == ID && Stud->getPassW() == PW){
		return true;
        }
	Stud = Stud->nextInt;
    }
    return false;
}

//reset password
void intStudents::resetPW(int id, int pw){
    InternationalStudent* Stud = TopIntStudent;
    while(Stud != lastIntStudent->nextInt)
    {
        if(Stud->getAppID() == id){
            Stud->setPassW(pw);
        }
	    Stud = Stud->nextInt;
    }
}

// Part2 3
void intStudents::Check_Country(intStudents head)
{
    InternationalStudent* here = head.getTop();
    bool flag =false;
    bool flag_typo =false;
   int count =0; //Flag to recall the number of targets exist in the linked list
   fstream File;
   
      File.open("newstu.txt", ios::out);
      if(File.fail())
      {
        cout << "Input file opening failed." << endl;
        exit(1);
      }

      if(!File.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        exit(1);
      }
  
      
       
       
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
     while (here != NULL)
       {
          int len;
          string tempStr, CountryStr;
     
          CountryStr = here->getCountry();
          for ( len  = 0; len < CountryStr.length(); len++)
           {
              CountryStr[len]=toupper(CountryStr[len]);
           }
         

          if ((CountryStr.length()==6) && CountryStr != "CANADA" )
              {   
                  int C_Number=0;
                  int A_Number =0;
                   int N_Number =0;
                    int D_Number =0;
                    int I_Number =0;
                    int R_Number=0;

                for ( len  = 0; len < CountryStr.length(); len++)
                 {
                  if ( CountryStr[len]== 'C')
                    {
                     C_Number = C_Number+1;
                    }
                   else if ( CountryStr[len]== 'A')
                   {   
                    A_Number = A_Number+1;
                   }
                   else if ( CountryStr[len]== 'D')
                   {       
                    D_Number = D_Number+1;  
                   }
                   else if ( CountryStr[len]== 'N')
                   {
                       
                    N_Number = N_Number+1;
                   
                   }
                   if (( N_Number==1) && (D_Number==1) && (A_Number==3) && (C_Number==1))
                   {
                    CountryStr = "CANADA";
                    cout << "It's a typo and fixes it to Canada"<< endl;
                    cout<< *here << endl;
                    File<< *here <<endl;
                    flag_typo=true;
                   }
               }
            }
          
          
            else if ((CountryStr.length()==4) && CountryStr != "IRAN" )
             {
                    int C_Number=0;
                  int A_Number =0;
                   int N_Number =0;
                    int D_Number =0;
                    int I_Number =0;
                    int R_Number=0;

                 for ( len  = 0; len < CountryStr.length(); len++)
                 {
                   if ( CountryStr[len]== 'I')
                   {   
                    I_Number = I_Number+1;
                   }
                   else if ( CountryStr[len]== 'R')
                   {   
                    R_Number = R_Number+1;
                   }
                   else if ( CountryStr[len]== 'A')
                   {      
                    A_Number = A_Number+1;  
                   }
                   else if ( CountryStr[len]== 'N')
                   {      
                    N_Number = N_Number+1;   
                   }
                   if (( I_Number==1) && (R_Number==1) && (N_Number==1) && (N_Number==1))
                   {
                       CountryStr = "IRAN";
                       cout << "It's a typo and fixes it to Iran"<< endl;
                       cout<< *here << endl;
                       File<< *here <<endl;
                       flag_typo=true;
                   }
               }
           }
          
           else if ((CountryStr.length()==5) && (CountryStr != "CHINA") && (CountryStr != "INDIA")&& (CountryStr != "KOREA") )
           {
              int C_Number = 0;
            int H_Number = 0;
            int I_Number = 0;
            int N_Number = 0;
            int A_Number = 0;
            int D_Number = 0;
            int K_Number = 0;
            int O_Number = 0;
            int R_Number = 0;
            int E_Number=0;
            

                 for ( len  = 0; len < CountryStr.length(); len++)
               {
                   if ( CountryStr[len]== 'C')
                   {   
                    C_Number = C_Number+1;
                   }
                   else if ( CountryStr[len]== 'H')
                   {   
                    H_Number = H_Number+1;
                   }
                   else if ( CountryStr[len]== 'I')
                   {       
                    I_Number = I_Number+1;  
                   }
                   else if ( CountryStr[len]== 'N')
                   {                       
                    N_Number = N_Number+1;                   
                   }
                    else if ( CountryStr[len]== 'A')
                   {               
                    A_Number = A_Number+1;   
                   }
                    else if ( CountryStr[len]== 'D')
                   {      
                    D_Number = D_Number+1;   
                   }
                   else if ( CountryStr[len]== 'K')
                   {      
                    K_Number = K_Number+1;   
                   }
                    else if ( CountryStr[len]== 'O')
                   {      
                    O_Number = O_Number+1;  
                   }
                    else if ( CountryStr[len]== 'R')
                   {      
                    R_Number = R_Number+1;   
                   }
                   else if ( CountryStr[len]== 'E')
                   {      
                    E_Number = E_Number+1;   
                   }

                   if (( C_Number==1) && (H_Number==1) && (I_Number==1) && (N_Number==1) && (A_Number==1) )
                   {
                       CountryStr = "CHINA";
                       cout << "It's a typo " << here->getCountry()   <<"  and fixes it to China"<< endl;
                       here->setCountry("China");
                       cout<< *here << endl;
                       flag_typo=true;
                       File<< *here <<endl;
                   }

                   if (( I_Number==2) && (N_Number==1) && (D_Number==1) && (A_Number==1) )
                   {
                       CountryStr = "INDIA";
                       cout << "It's a typo "<<  here->getCountry()  <<" and fixes it to India"<< endl;
                        here->setCountry("India");
                       cout<< *here << endl;
                       flag_typo=true;
                     File<< * here <<endl;
                   }
                  if (( K_Number==1) && (O_Number==1) && (R_Number==1) && (E_Number==1)&& (A_Number==1)  )
                   {
                       CountryStr = "KOERA";
                       cout << "It's a typo " << here->getCountry()  <<" and fixes it to Korea"<< endl;
                       cout<< *here << endl;
                       flag_typo=true;
                        File<< *here <<endl;
                   }

                }
           }
           else 
           {
            File << *here<<endl;
           }           
           tempStr = CountryStr;
           if ((tempStr == "CHINA") || (tempStr == "CANADA") || (tempStr == "INDIA") || (tempStr == "IRAN") || 
             (tempStr == "KOREA"))
             {
               flag = false;
              }
           else
            {
               cout<< "The item contains a wrong record." << endl;
               cout << *here << endl;
               flag= true;
               exit(1);
            }
       
            here = here->nextInt;
     }
     if ((flag == false) && (flag_typo == true))
        {
            cout <<" All records about the Countries are correct after fixing the typo."<< endl;
        }

   }  
    File.close();
}
// innovation2
void intStudents::requireIntCGPA(intStudents head, float target)
{
   InternationalStudent* here = head.getTop();
   int count =0; // Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     // Search whole linked list to check if or not have target
     while (here != NULL)
     {
          if( here->getCGPA() >= target )// The condtion to judge if or not exist the required target
           {
              count =count +1;
              cout << *here << endl;
           }
          here = here->nextInt;
     }
     if ( count ==0 )
     {
       cout<<"The domestic students satisfied the requirements do noe exist." <<endl;
     }
   }
}

// innovation2
void intStudents::requireIntScore(intStudents head, int target)
{
    InternationalStudent* here = head.getTop();
   int count =0; // Flag to recall the number of targets exist in the linked list
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   {
     // Search whole linked list to check if or not have target
     while (here != NULL)
     {
            if( here->getResearchScore() >= target )// The condtion to judge if or not exist the required target
           {
              count =count +1;
              cout << *here << endl;
           }
          here = here->nextInt;
     }
     if ( count ==0 )
     {
       cout<<"The domestic students satisfied the requirements do noe exist." <<endl;
     }
   }
}
