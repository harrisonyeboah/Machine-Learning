//========================================================
// Harrison Yeboah
// June 2025
// Summary.h
// This file contains the Summary class declaration.
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef SUMMARY_H
#define SUMMARY_H

#define DEFAULT_LIST_CAPACITY 10

class Summary {
private:
    struct Month {
        double chestPain;
        double ca;
        double thal;
        double thalach; 
        float heartDiseaseScore;  
        double age;
        Month* next;
    };
    int ageYear;

    Month* head; 

public:
    Summary(); // Tested
    Summary(const Summary &mylist);  //Tested
    ~Summary(); //Tested
    Summary operator= (const Summary &mylist); // Tested

    void append(double chestPain, double ca, double thal, double thalach, double age); // Tested 
    void insert(double chestPain, double ca, double thal, double thalach, double age ,double index); //Tested
    void remove(int index); // Tested
    int length(void) const; // Tested
    bool isEmpty(void) const; // Tested
    void clear(void); // Tested
    void operator[](int index);



    double chestPainScore(double reportedChestpain);
    double caScore(double reportedCa);
    double thalScore(double reportedThal);
    double thalachScore(double reportedThalach);
    double ageMultiplier(double reportedAge);

    double totalScore(double chestScore, double caScore, double thalScore, double thalachScore, double ageMultplier);
    
    void createPlotTxtFile(string fileName);
    friend ostream & operator<< (ostream &os, Summary &mylist) {
        Month* ptr = mylist.head;
        int age = ptr->age;
        while (ptr != nullptr) {
            os << "Age: " << age << " ChestPain: " << ptr->chestPain << ", " << "Colored Vessels: " <<ptr->ca << " Thal: : " << ", "<< ptr->thal << ", "<< "Thalach: " <<ptr->thalach << ", " << "Score:" <<ptr->heartDiseaseScore  << ", " << "Age: " << ptr->age << ")" << endl;
            age++;
            ptr = ptr->next;
        }
        return os;
    } // Tested
    
};

#endif
