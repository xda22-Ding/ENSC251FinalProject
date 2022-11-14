//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"
#include "student.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

/* Part 6*/
void SortingDomesticStudent( DomesticStudent DStudent[])
{
    class DomesticStudent Order[100];
    for(int n=0; n< 100; n++)
    {
    Order[n] = DStudent[n];
    }
    
    int size = sizeof(Order)/sizeof(Order[0]);
    class DomesticStudent Temp;
    int index;
    int result;
    int result2;
    int result3;
  
    for(int i = 1; i < size - 1;i++ )
    {    
         index = i - 1;
         Temp =Order[i-1];
         for (int j=i+1;j < size ;j++)
         {
            result = compareResearchScore(Temp, Order[j]);
            if(result == 1)
            {
               Temp = Order[j];
               index =j;
            } 
            else if (result == 3)
            {
                  result2 = compareCGPA(Temp,Order[j]);
                  if(result2 == 1)
                    {
                        Temp = Order[j];
                        index = j;
                    }
                  else if(result2 == 3)
                  {
                        result3 = compareProvince(Temp,Order[j]);
                        if(result3 == 1 )
                        {
                            Temp = Order[j];
                            index = j;
                        }

                  }

             
            }
              
          }
          if(index != i - 1)
          {
              Order[index] = Order[i-1];
              Order[i-1] =Temp;
           }


    }
    cout<< setw(14) << "FirstName" << setw(14) <<"LastName" <<setw(10) <<"Province"<< setw(6) <<"CGPA"<<setw(16) <<"ResearchScore" <<endl;
   for (int m=0; m<100; m++)  
   {
    cout << setw(14) << Order[m].getFirstName() << setw(14) << Order[m].getLastName();
    cout << setw(10) << Order[m].getProvince()<< setw(6) << Order[m].getCGPA()<<setw(10)<< Order[m].getResearchScore() <<endl;
   }

/* test requirement*/

/*cout << " Violet Simmons researchscore is 70" << endl;
cout << " Abigail Bailey researchscore is 71" <<endl;
for (int mm=0; mm<100;mm++)
{
      if ((Order[mm].getFirstName() == "Violet") && (Order[mm].getLastName() == "Simmons" ))
       { cout <<" Index of Simmons is " << mm <<endl;
        break;

       }
}
  for (int mm=0; mm<100;mm++)
      {
        if ((Order[mm].getFirstName() == "Abigail") && (Order[mm].getLastName() == "Bailey" ))
        { cout <<" Index of Bailey is " << mm <<endl;
           break;
        }
  
      }
cout << " Violet Simmons researchscore is 70, CGPA is 2.95, province is AB" << endl;
cout << " Emily Rivera researchscore is 70, CGPA is 2.95, province is ON" <<endl;
for (int mm=0; mm<100;mm++)
{
      if ((Order[mm].getFirstName() == "Violet") && (Order[mm].getLastName() == "Simmons" ))
       { cout <<" Index of Simmons is " << mm <<endl;
        break;

       }
}
  for (int mm=0; mm<100;mm++)
      {
        if ((Order[mm].getFirstName() == "Emily") && (Order[mm].getLastName() == "Rivera" ))
        { cout <<" Index of Rivera is " << mm <<endl;
           break;
        }
  
      }

  cout << " Liam Edwards researchscore is 70, CGPA is 4.33, province is AB" << endl;
  cout << " Emily Rivera researchscore is 70, CGPA is 2.95, province is ON" <<endl;
for (int mm=0; mm<100;mm++)
{
      if ((Order[mm].getFirstName() == "Liam") && (Order[mm].getLastName() == "Edwards" ))
       { 
        cout <<" Index of Edwards is " << mm <<endl;
        break;
       }
}
  for (int mm=0; mm<100;mm++)
      {
        if ((Order[mm].getFirstName() == "Emily") && (Order[mm].getLastName() == "Rivera" ))
        { 
           cout <<" Index of Rivera is " << mm <<endl;
           break;
        }
  
      }*/

}
void SortingInternationalStudent( InternationalStudent IStudent[], ToeflScore toefArr[])
{
    class InternationalStudent InternationalOrder[100];
    class ToeflScore ToefGrade[100];

     for(int n=0; n< 100; n++)
    {
    ToefGrade[n] = toefArr[n];
    InternationalOrder[n] = IStudent[n];
    }
    
    int size = sizeof(InternationalOrder)/sizeof(InternationalOrder[0]);
    class InternationalStudent Temp, chooseStudent[100];
    class ToeflScore ToefTemp, chooseToef[100];
    int index;
    int SortNumber = size;
    int GradeReading;
    int GradeListening;
    int GradeWriting;
    int GradeSpeaking;
    int GradeTotal;
    int result;
    int result2;
    int result3;
    int number =0;
    /*To choice  students base on toefl requirment*/
    for(int k = 0; k < size; k++)
    {
        GradeListening = ToefGrade[k].getListening();
        GradeSpeaking = ToefGrade[k].getSpeaking();
        GradeReading = ToefGrade[k].getReading();
        GradeWriting = ToefGrade[k].getWriting();
        GradeTotal = GradeListening + GradeSpeaking + GradeReading + GradeWriting;
        if((GradeTotal >92) && (GradeListening > 19) && ( GradeSpeaking > 19) && ( GradeWriting > 19) && (GradeReading > 19))
        {
           chooseStudent[number] = InternationalOrder[k];
           chooseToef[number] = ToefGrade[k];
           number = number +1 ;
        }
        
        
    }
    
    SortNumber = number; 
    /* Base on the requirement to sort students*/
    for (int kk =0; kk < SortNumber-1; kk++)
      {
        InternationalOrder[kk]= chooseStudent[kk];
        ToefGrade[kk]=chooseToef[kk];
      }
    for(int i = 1; i < SortNumber- 1;i++ )
    {    
         index = i - 1;
         Temp =InternationalOrder[i-1];
         ToefTemp = ToefGrade[i-1];
         for (int j=i+1;j < SortNumber; j++)
         {
            result = compareResearchScore(Temp, InternationalOrder[j]);
            if(result == 1)
            {
               Temp = InternationalOrder[j];
               ToefTemp = ToefGrade[j];
               index =j;
            } 
            else if (result == 3)
            {
                  result2 = compareCGPA(Temp,InternationalOrder[j]);
                  if(result2 == 1)
                    {
                        Temp = InternationalOrder[j];
                        ToefTemp = ToefGrade[j];
                        index = j;
                    }
                  else if(result2 == 3)
                  {
                        result3 = compareCountry(Temp,InternationalOrder[j]);
                        if(result3 == 1 )
                        {
                            Temp = InternationalOrder[j];
                            ToefTemp = ToefGrade[j];
                            index = j;
                        }

                  }

             
            }
             
          }
        /* Base on the relation of index to decide if or not exchange the contain the array*/
        if(index != i - 1)
              {
                InternationalOrder[index] = InternationalOrder[i-1];
                InternationalOrder[i-1] =Temp;
                ToefGrade[index] = ToefGrade[i-1];
                ToefGrade[i-1] = ToefTemp; 
              }
    }
    class InternationalStudent PrintArray[SortNumber];
    class ToeflScore PrintToefArray[SortNumber];
    for(int M = 0; M < SortNumber; M++)
    {
        PrintToefArray[M] = ToefGrade[M];
        PrintArray[M] = InternationalOrder[M];
    }
    cout << setw(16) << "FirstName" << setw(16) <<"LastName" <<setw(10) <<"Country"<< setw(6) <<"CGPA"<<setw(16) <<"ResearchScore";
    cout << setw(9) << "Reading"<< setw(11) << "Listening"<<setw(8) <<"Speaking"<< setw(9)<<"Writing" << endl;
    for (int m=0; m<SortNumber; m++)  
    {
     cout << setw(16) << InternationalOrder[m].getFirstName()<<setw(16) << InternationalOrder[m].getLastName()<<setw(10)<< InternationalOrder[m].getCountry();
     cout << setw(6) << InternationalOrder[m].getCGPA()<< setw(16) << InternationalOrder[m].getResearchScore()<< setw(9) << ToefGrade[m].getReading();
     cout << setw(11) << ToefGrade[m].getListening() << setw(8) << ToefGrade[m].getSpeaking() << setw(9)<< ToefGrade[m].getWriting() << endl;
    }

 /* Test my code wheather or not satisfy requirment of project*/   
 /* Below tow guys have different research score */
 /*cout << " Mohammad Darbandi researchscore is 70" << endl; 
cout << " Alireza Daghestani researchscore is 72" <<endl;
for (int mm=0; mm < SortNumber - 1; mm++)
{
      if ((InternationalOrder[mm].getFirstName() == "Mohammad") && (InternationalOrder[mm].getLastName() == "Darbandi" ))
       { 
        cout <<" Index of Darbandi is " << mm <<endl;
        break;

       }
}
  for (int mm=0; mm<SortNumber - 1;mm++)
      {
        if ((InternationalOrder[mm].getFirstName() == "Alireza") && (InternationalOrder[mm].getLastName() == "Daghestani" ))
        { 
          cout <<" Index of Daghestani is " << mm <<endl;
           break;
        }
  
      }*/

  /* Below tow guys have same research score and CGPA, but from different country*/
/*cout << " Ankit Chaturvedi researchscore is 74, CGPA is 3.35,Country is Indian" << endl;
cout << " Jiho Chung researchscore is 74,CGPA is 3.35, country is Korea " <<endl;
for (int mm=0; mm < SortNumber - 1; mm++)
{
      if ((InternationalOrder[mm].getFirstName() == "Ankit") && (InternationalOrder[mm].getLastName() == "Chaturvedi" ))
       { 
        cout <<" Index of Chaturvedi is " << mm <<endl;
        break;

       }
}
  for (int mm=0; mm<SortNumber - 1;mm++)
      {
        if ((InternationalOrder[mm].getFirstName() == "Jiho") && (InternationalOrder[mm].getLastName() == "Chung" ))
        { 
          cout <<" Index of Chung is " << mm <<endl;
           break;
        }
  
      }*/

  /* Below tow guys have same research score but have different CGPA*/
/*cout << " Xin Liu researchscore is 79, CGPA is 3.4," << endl;
cout << " Aditya Bhattathiri researchscore is 79,CGPA is 3.35,  " <<endl;
for (int mm=0; mm < SortNumber - 1; mm++)
{
      if ((InternationalOrder[mm].getFirstName() == "Xin") && (InternationalOrder[mm].getLastName() == "Liu" ))
       { 
        cout <<" Index of Liu is " << mm <<endl;
        break;

       }
}
  for (int mm=0; mm<SortNumber - 1;mm++)
      {
        if ((InternationalOrder[mm].getFirstName() == "Aditya") && (InternationalOrder[mm].getLastName() == "Bhattathiri" ))
        { 
          cout <<" Index of Bhattathiri is " << mm <<endl;
           break;
        }
  
      }*/
/*Test condition of droping total toefl score*/
/*cout << " Peter Choi: Total Toef Score is 92 " <<endl;
for (int mm=0; mm < SortNumber - 1; mm++)
{
      if ((InternationalOrder[mm].getFirstName() == "Peter") && (InternationalOrder[mm].getLastName() == "Choi" ))
       { 
        cout <<" Index of Choi is " << mm <<endl;
        break;

       }
       else
       {
        cout << " Peter Choi is droped!"<< endl;
        break;
       }
}*/

/*Test drop condition  with speaking*/
/*cout << " Quan Zhang: Total Toef Score is 94 however the speaking is 19" <<endl;
for (int mm=0; mm < SortNumber - 1; mm++)
{
      if ((InternationalOrder[mm].getFirstName() == "Quan") && (InternationalOrder[mm].getLastName() == "Zhang" ))
       { 
        cout <<" Index of Zhang  is " << mm <<endl;
        break;

       }
       else
       {
        cout << " Quan Zhang is droped!"<< endl;
        break;
       }
}*/



}


//--------field sort



/*                    CGPA sort for international student              */
void merge_CGPA_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    InternationalStudent * temp = new InternationalStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getCGPA() > A[j].getCGPA())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_CGPA_In (InternationalStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_CGPA_In(A, startIndex, middleIndex);
        mergeSort_CGPA_In(A, middleIndex + 1, lastIndex);
        merge_CGPA_In(A,startIndex,middleIndex,lastIndex);
    }
}

/*                Research Score sort for international student              */
void merge_RScore_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    InternationalStudent * temp = new InternationalStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getResearchScore() > A[j].getResearchScore())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_RScore_In (InternationalStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_RScore_In(A, startIndex, middleIndex);
        mergeSort_RScore_In(A, middleIndex + 1, lastIndex);
        merge_RScore_In(A,startIndex,middleIndex,lastIndex);
    }
}

/*                First name sort for international student              */
void merge_FN_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    InternationalStudent * temp = new InternationalStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getFirstName() < A[j].getFirstName())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_FN_In (InternationalStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_FN_In(A, startIndex, middleIndex);
        mergeSort_FN_In(A, middleIndex + 1, lastIndex);
        merge_FN_In(A,startIndex,middleIndex,lastIndex);
    }
}

/*                Last name sort for international student              */
void merge_LN_In(InternationalStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    InternationalStudent * temp = new InternationalStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getLastName() < A[j].getLastName())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_LN_In (InternationalStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_LN_In(A, startIndex, middleIndex);
        mergeSort_LN_In(A, middleIndex + 1, lastIndex);
        merge_LN_In(A,startIndex,middleIndex,lastIndex);
    }
}

/*                    CGPA sort for Domestic Student                    */
void merge_CGPA_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    DomesticStudent * temp = new DomesticStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getCGPA() > A[j].getCGPA())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_CGPA_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_CGPA_Do(A, startIndex, middleIndex);
        mergeSort_CGPA_Do(A, middleIndex + 1, lastIndex);
        merge_CGPA_Do(A,startIndex,middleIndex,lastIndex);
    }
}

/*                 Research Score sort for Domestic Student              */
void merge_RScore_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    DomesticStudent * temp = new DomesticStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getResearchScore() > A[j].getResearchScore())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_RScore_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_RScore_Do(A, startIndex, middleIndex);
        mergeSort_RScore_Do(A, middleIndex + 1, lastIndex);
        merge_RScore_Do(A,startIndex,middleIndex,lastIndex);
    }
}

/*                  First name sort for Domestic student                */
void merge_FN_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    DomesticStudent * temp = new DomesticStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getFirstName() < A[j].getFirstName())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_FN_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_FN_Do(A, startIndex, middleIndex);
        mergeSort_FN_Do(A, middleIndex + 1, lastIndex);
        merge_FN_Do(A,startIndex,middleIndex,lastIndex);
    }
}

/*                  Last name sort for Domestic student                */
void merge_LN_Do(DomesticStudent * A, const int& startIndex, const int& middleIndex, const int& lastIndex)
{
    int size = lastIndex - startIndex + 1;
    DomesticStudent * temp = new DomesticStudent [size];
    
    int i = startIndex;
    int j = middleIndex + 1;
    int k = 0;
    
    while (i <= middleIndex && j <= lastIndex)
    {
        if (A[i].getLastName() < A[j].getLastName())
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= middleIndex)
        temp[k++] = A[i++];
    while (j <= lastIndex)
        temp[k++] = A[j++];
    for (int k = 0; k < size; k++)
        A[startIndex+k] = temp [k];
    delete [] temp;
}
void mergeSort_LN_Do (DomesticStudent *A, const int& startIndex, const int& lastIndex)
{
    if (startIndex >= lastIndex)
        return;
    else
    {
        int middleIndex = (startIndex + lastIndex) / 2;
        mergeSort_LN_Do(A, startIndex, middleIndex);
        mergeSort_LN_Do(A, middleIndex + 1, lastIndex);
        merge_LN_Do(A,startIndex,middleIndex,lastIndex);
    }
}

InternationalStudent * Field_Sort_IN (InternationalStudent * A, const int size)
{
    int startIndex = 0;
    int lastIndex = size - 1;
    InternationalStudent * temp = new InternationalStudent[size];
    for (int i =0; i < size; i++)
        temp[i] = A[i];
    
    char choice;
        cout << "Right now you are in International student field sort." << endl;
        cout << "Which field would you like to sort?" << endl;
        cout << "'C' for CGPA, 'R' for research socre, 'F' for first name, 'L' for last name" << endl;
        cout << "If you want to exit press 'E'." << endl;
        cin >> choice;
        
        if (choice == 'C')
        {
            mergeSort_CGPA_In(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'R')
        {
            mergeSort_RScore_In(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'F')
        {
            mergeSort_FN_In(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'L')
        {
            mergeSort_LN_In(temp, startIndex, lastIndex);
            return temp;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return 0;
        }

}

DomesticStudent * Field_Sort_Do (DomesticStudent * A, const int size)
{
    int startIndex = 0;
    int lastIndex = size - 1;
    DomesticStudent * temp = new DomesticStudent[size];
    for (int i =0; i < size; i++)
        temp[i] = A[i];
    
    char choice;
        cout << "Right now you are in International student field sort." << endl;
        cout << "Which field would you like to sort?" << endl;
        cout << "'C' for CGPA, 'R' for research socre, 'F' for first name, 'L' for last name" << endl;
        cout << "If you want to exit press 'E'." << endl;
        cin >> choice;
        
        if (choice == 'C')
        {
            mergeSort_CGPA_Do(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'R')
        {
            mergeSort_RScore_Do(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'F')
        {
            mergeSort_FN_Do(temp, startIndex, lastIndex);
            return temp;
        }
        else if (choice == 'L')
        {
            mergeSort_LN_Do(temp, startIndex, lastIndex);
            return temp;
        }
        else
        {
            cout << "Invalid Input" << endl;
            return 0;
        }

}
