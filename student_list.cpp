#include "student.hpp"
#include "student_list.hpp"
#include<iostream>
#include <iomanip>
using namespace std;

Students::Students(){
	TopStudent = NULL;
	lastStudent = NULL;
}

void Students::insert(Student* stud){
	if(TopStudent==NULL){
		TopStudent = stud;
		lastStudent = stud;
	}
	else{
		Student* tempStud = TopStudent;
		while(tempStud != lastStudent ){
			if(compareResearchScore(stud,tempStud->next) == 1){
				stud->next = tempStud->next;
				tempStud->next = stud;
				break;
			}


			tempStud = tempStud -> next;
		}
		if(tempStud == lastStudent){
			tempStud->next = stud;
			lastStudent = stud;
		}

	}

}

void Students::printList(){
	Student* tempStud = TopStudent;
	while(tempStud != NULL){
		cout << tempStud->getResearchScore() << endl;
		tempStud = tempStud->next;
	}



}