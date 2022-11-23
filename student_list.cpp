#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
using namespace std;

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
		if(compareResearchScore(stud,tempStud) == 1){
			stud->nextDom = tempStud;
			TopStudent = stud;
			return;			
		}
		else if(compareResearchScore(stud,tempStud) == 3){
			if(compareCGPA(stud,tempStud) == 1){
				stud->nextDom = tempStud;
				TopStudent = stud;
				return;		
			}
			else if(compareCGPA(stud,tempStud) == 3){
				if(compareProvince(stud,tempStud) == 1){
					stud->nextDom = tempStud;
					TopStudent = stud;
					return;							
				}
			}
		}



		while(tempStud != lastStudent ){
			if(compareResearchScore(stud,tempStud->nextDom) == 1){
				stud->nextDom = tempStud->nextDom;
				tempStud->nextDom = stud;
				return;
			}
			else if(compareResearchScore(stud,tempStud->nextDom) == 3){
				if(compareCGPA(stud,tempStud->nextDom) == 1){
					stud->nextDom = tempStud->nextDom;
					tempStud->nextDom = stud;
					return;
				}
				else if(compareCGPA(stud,tempStud->nextDom) == 3){
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

 void domStudents:: Search(domStudents head, double target)
{
   DomesticStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
      cout << "The object is empty."<< endl;
   }
   else
   { 
  
     while (here != head.getlast())
	 {  
		if(abs(here->getCGPA() - target) < 0.01 )
         {
          count =count +1;
		  cout << here->getFirstName() << endl;
          cout << here->getLastName() << endl;
		   cout << here->getProvince() << endl;
		   cout << here->getCGPA() << endl;

         }
		 here = here->nextDom;
	 }
    if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
     }
   }
}

void domStudents::Search(domStudents head, int target)
{
   DomesticStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      if (target > 100000)
        {
			while (here != head.getlast())
	       {  
		       if(here->getAppID() == target)
             {
              count =count +1;
		      cout << here->getFirstName() << endl;
              cout << here->getLastName() << endl;
		      cout << here->getProvince() << endl;
		      cout << here->getCGPA() << endl;

         }
		 here = here->nextDom;
	      }
    
        }
    else
       {
          while (here != head.getlast())
	       {  
		       if(here->getResearchScore() == target)
             {
              count =count +1;
		      cout << here->getFirstName() << endl;
              cout << here->getLastName() << endl;
		      cout << here->getProvince() << endl;
		      cout << here->getCGPA() << endl;

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

void domStudents:: Search(domStudents head, string FirstName, string LastName)
{
   DomesticStudent* here = head.getTop();
   int count =0;
   if(here == NULL)
   {
     cout << "The object is empty."<< endl;
   }
   else
   {
      while (here != head.getlast())
	       {  
		       if((here->getFirstName() == FirstName) && (here->getLastName()== LastName))
             {
              count =count +1;
		      cout << here->getFirstName() << endl;
              cout << here->getLastName() << endl;
		      cout << here->getProvince() << endl;
		      cout << here->getCGPA() << endl;

            }
		 here = here->nextDom;
	      }

        }
       
     if ( count ==0 )
     {
       cout<<"Information here not found" <<endl;
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
		if(compareResearchScore(stud,tempIntStud) == 1){
			stud->nextInt = tempIntStud;
			TopIntStudent = stud;
			return;
		}
		else if(compareResearchScore(stud,tempIntStud)==3){
			if(compareCGPA(stud,tempIntStud) == 1){
				stud->nextInt = tempIntStud;
				TopIntStudent = stud;
				return;
			}
			else if(compareCGPA(stud,tempIntStud) == 3){
				if(compareCountry(stud,tempIntStud) == 1){
					stud->nextInt = tempIntStud;
					TopIntStudent = stud;
					return;
				}
			}

		}


		while(tempIntStud != lastIntStudent ){
			if(compareResearchScore(stud,tempIntStud->nextInt) == 1){
				stud->nextInt = tempIntStud->nextInt;
				tempIntStud->nextInt = stud;
				break;
			}
			else if(compareResearchScore(stud,tempIntStud->nextInt) == 3){
				if(compareCGPA(stud,tempIntStud->nextInt) == 1){
					stud->nextInt = tempIntStud->nextInt;
					tempIntStud->nextInt = stud;
					break;
				}
				else if(compareCGPA(stud,tempIntStud->nextInt) == 3){
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
