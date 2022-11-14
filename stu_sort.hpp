//header file stu_sort.hpp to declare your sorting functions
#ifndef stu_sort_hpp
#define stu_sort_hpp

#include <string> //you will have to use string in C++
#include <stdio.h>
#include "student.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void SortingDomesticStudent( DomesticStudent DStudent[]);
void SortingInternationalStudent( InternationalStudent IStudent[], ToeflScore toefArr[]);


/*                    CGPA sort for international student              */
void merge_CGPA_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_CGPA_In (InternationalStudent *A, const int& startIndex, const int& lastIndex);
/*                Research Score sort for international student              */
void merge_RScore_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_RScore_In (InternationalStudent *A, const int& startIndex, const int& lastIndex);
/*                First name sort for international student              */
void merge_FN_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_FN_In (InternationalStudent *A, const int& startIndex, const int& lastIndex);
/*                Last name sort for international student              */
void merge_LN_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_LN_In (InternationalStudent *A, const int& startIndex, const int& lastIndex);
/*                    CGPA sort for Domestic Student                    */
void merge_CGPA_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_CGPA_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex);
/*                 Research Score sort for Domestic Student              */
void merge_RScore_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_RScore_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex);
/*                  First name sort for Domestic student                */
void merge_FN_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_FN_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex);
/*                  Last name sort for Domestic student                */
void merge_LN_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex);
void mergeSort_LN_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex);
InternationalStudent * Field_Sort_IN (InternationalStudent * A, const int size);
DomesticStudent * Field_Sort_Do (DomesticStudent * A, const int size);

#endif /* stu_sort_hpp */
