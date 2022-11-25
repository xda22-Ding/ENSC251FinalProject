#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;


Students::Students(){
    TopStudent = NULL;
    lastStudent = NULL;

}




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
 void domStudents:: Search(domStudents head, double target)
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
       while (here != head.getlast())
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
          here = here->nextDom;
     }
    }
    if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
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

void intStudents:: Search(intStudents head, double target)
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
/*
 Student_Node::Student_Node(){}
 Student_Node::Student_Node(Student new_st)
 {
     st = new_st;
     next = NULL;
 }
 //constructor
 Student_list::Student_list()
 {
     head = NULL;
     tail = NULL;
 }
 //destructor
 Student_list::~Student_list()
 {
     Student_Node *temp = head;
     while (head != NULL)
     {
         temp = head;
         head = head->next;
         delete temp;
     }
 }
 //getters
 Student_Node* Student_list::getHead() const
 {
     return head;
 }
 Student_Node* Student_list::getTail() const
 {
     return tail;
 }
 void Student_list::insertall(Student_Node *new_st)
 {
     if (head == NULL)
     {
         head = new_st;
         tail = new_st;
     }
     else
     {
         if (compareOverall_modified(head->st, new_st->st) == -1)
         {
             new_st->next = head;
             head = new_st;
         }
         Student_Node *front = head;
         Student_Node *back = head->next;
         int instered = 0;
         while (back != NULL)
         {
             if (compareOverall_modified(back->st, new_st->st) == 1)
             {
                 front = front->next;
                 back = back->next;
             }
             else
             {
                 front->next = new_st;
                 new_st->next = back;
                 instered = 1;
                 break;
             }
         }
         if (instered == 0)
         {
             tail->next = new_st;
             tail = new_st;
         }
     }
 }
 void Student_list::mergeList(domStudents &dList, intStudents &iList, Student_list &sList)
 {
     while (dList.getTop() != NULL)
     {
         string first_name = dList.getTop()->getFirstName();
         string last_name = dList.getTop()->getLastName();
         float cgpa = dList.getTop()->getCGPA();
         int score = dList.getTop()->getResearchScore();
         int stuID = dList.getTop()->getAppID();
         Student new_st (first_name, last_name, cgpa, score, stuID);
         Student_Node *ns = new Student_Node(new_st);
         sList.insertall(ns);
         //dList.deleteTop(dList);
     }
     while (iList.getTop() != NULL)
     {
         string first_name = iList.getTop()->getFirstName();
         string last_name = iList.getTop()->getLastName();
         float cgpa = iList.getTop()->getCGPA();
         int score = iList.getTop()->getResearchScore();
         int stuID = iList.getTop()->getAppID();
         Student new_st (first_name, last_name, cgpa, score, stuID);
         Student_Node *ns = new Student_Node(new_st);
         sList.insertall(ns);
         //dList.deleteTop(dList);
     }
      
 }

 //friend functions
 int compareOverall_modified(const Student s1, const Student s2)
 {
     if (compareResearchScore_modified(s1, s2) == 1)
         return 1;
     if (compareResearchScore_modified(s1, s2) == -1)
         return -1;
     if (compareCPGA_modified(s1, s2) == 1)
         return 1;
     if (compareCPGA_modified(s1, s2) == -1)
         return -1;
     return 1;
 }
*/
