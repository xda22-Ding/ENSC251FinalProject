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
		while(tempStud != lastStudent ){
			if(compareResearchScore(stud,tempStud->nextDom) == 1){
				stud->nextDom = tempStud->nextDom;
				tempStud->nextDom = stud;
				break;
			}
			else if(compareResearchScore(stud,tempStud->nextDom) == 3){
				if(compareCGPA(stud,tempStud->nextDom) == 1){
					stud->nextDom = tempStud->nextDom;
					tempStud->nextDom = stud;
					break;
				}
				else if(compareCGPA(stud,tempStud->nextDom) == 3){
					if(compareProvince(stud,tempStud->nextDom) == 1){
						stud->nextDom = tempStud->nextDom;
						tempStud->nextDom = stud;
						break;
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