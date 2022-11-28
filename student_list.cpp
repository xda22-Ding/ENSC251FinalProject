#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
#include <cmath>
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
            if( here->getCGPA() > target )// The condtion to judge if or not exist the required target
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
            if( here->getResearchScore() > target )// The condtion to judge if or not exist the required target
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

// Based on the definition of order to insert new student to  the student's data
void domStudents::insert(domStudents dom_list, DomesticStudent* stud){

    DomesticStudent* here = dom_list.getTop();//Set pointer "here" to point the top of linked list of domestic student
    if( here ==NULL){
        TopStudent = stud;
        lastStudent = stud;
    }
    else{
        DomesticStudent* tempStud = here; // Creat the temp pointer to exchange the data
        if(compareResearchScore(*stud,*tempStud) == 1){
            stud->nextDom = tempStud;
            here = stud;
            return;
          }
        else if(compareResearchScore(*stud,*tempStud) == 3){
            if(compareCGPA(*stud,*tempStud) == 1){
                stud->nextDom = tempStud;
                here = stud;
                return;
            }
            else if(compareCGPA(*stud,*tempStud) == 3){
                if(compareProvince(stud,tempStud) == 1){
                    stud->nextDom = tempStud;
                    here = stud;
                    return;
                }
            }
        }


        // Based on the requirement to arrange the order between two students
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
/*------------Domestic Student Linked List----------------*/

/*------------International Student Linked List----------------*/
intStudents::intStudents(){
    TopIntStudent = NULL;
    lastIntStudent = NULL;
}

void intStudents::insert(InternationalStudent* stud){
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
           if((here->getFirstName() == FirstName) && (here->getLastName()== LastName))
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

void intStudents::insert(intStudents int_list , InternationalStudent* stud){

      InternationalStudent* here = int_list.getTop();
    if(here==NULL){
        TopIntStudent = stud;
        lastIntStudent = stud;
    }
    else{
        InternationalStudent* tempIntStud = here;
        if(compareResearchScore(*stud,*tempIntStud) == 1){
            stud->nextInt = tempIntStud;
            here = stud;
            return;
        }
        else if(compareResearchScore(*stud,*tempIntStud)==3){
            if(compareCGPA(*stud,*tempIntStud) == 1){
                stud->nextInt = tempIntStud;
                here = stud;
                return;
            }
            else if(compareCGPA(*stud,*tempIntStud) == 3){
                if(compareCountry(stud,tempIntStud) == 1){
                    stud->nextInt = tempIntStud;
                    here = stud;
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

// Part2 3
void intStudents::Check_Country(intStudents head)
{
    InternationalStudent* here = head.getTop();
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
          string tempStr, CountryStr;
     
          CountryStr = here->getCountry();
          for ( len  = 0; len < CountryStr.length(); len++)
           {
              CountryStr[len]=toupper(CountryStr[len]);
           }
          int C_Number=0;
          int A_Number =0;
          int N_Number =0;
          int D_Number =0;
          if ((CountryStr.length()==6) && CountryStr != "CANADA" )
              {   
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
                   }
               }
            }
            int I_Number=0;
            int R_Number =0;
            A_Number =0;
            N_Number =0;
            if ((CountryStr.length()==4) && CountryStr != "IRAN" )
             {
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
                   }
               }
           }
            C_Number = 0;
            int H_Number = 0;
            I_Number = 0;
            N_Number = 0;
            A_Number = 0;
            D_Number = 0;
            int K_Number = 0;
            int O_Number = 0;
            R_Number = 0;
            int E_Number=0;
            if ((CountryStr.length()==5) && (CountryStr != "CHINA") && (CountryStr != "INDIA")&& (CountryStr != "KOREA") )
           {
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
                       cout<< *here << endl;
                   }

                   if (( I_Number==2) && (N_Number==1) && (D_Number==1) && (A_Number==1) )
                   {
                       CountryStr = "INDIA";
                       cout << "It's a typo "<<  here->getCountry()  <<" and fixes it to India"<< endl;
                       cout<< *here << endl;
                   }
                  if (( K_Number==1) && (O_Number==1) && (R_Number==1) && (E_Number==1)&& (A_Number==1)  )
                   {
                       CountryStr = "KOERA";
                       cout << "It's a typo " << here->getCountry()  <<" and fixes it to Korea"<< endl;
                       cout<< *here << endl;
                   }

                }
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
     if (flag == false)
        {
            cout <<" All records about the Countries are correct."<< endl;
        }
   }  
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
          if( here->getCGPA() > target )// The condtion to judge if or not exist the required target
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
            if( here->getResearchScore() > target )// The condtion to judge if or not exist the required target
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
