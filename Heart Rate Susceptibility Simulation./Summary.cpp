/*
Name: Harrison Kromoh Yeboah
Linked List Implementation
*/

#include <iostream>
#include "Summary.h" // Assuming Summary.h defines the Month structure
#include <cassert>
using namespace std;
#include <string>
#include <fstream>

const int SUMMARYSIZE = 100;


Summary::Summary(void) {
    /*
    This is the default constuctor is it how we decare our 
    empyt month summary with 0 total months.
    */

    head = nullptr;
    ageYear = 0;
}

Summary::Summary(const Summary& mylist) {
    /*
    This is my copy constructor. This has the precondition that a templated list 
    Must be passed through. If the list is empty then the new list created will also
    have an empty head. Otherwise while the other list Month is not null. We create a new Month 
    with the other list item then have our list current = to the new Month that contains the otherList
    item. Then when finished to prevent a dangling pointer. We have current->next = NULL.
    */
    if (mylist.head == nullptr) {
        head = nullptr;
    } else {
        head = new Month(); 
        head->chestPain = mylist.head->chestPain;
        head->ca = mylist.head->ca;
        head->thal = mylist.head->thal;
        head->thalach = mylist.head->thalach;
    
        Month* myListCurrent = mylist.head->next;
        Month* current = head;
    
        while (myListCurrent != NULL) {
            Month* newMonth = new Month(); 
            newMonth->chestPain = myListCurrent->chestPain;
            newMonth->ca = myListCurrent->ca;
            newMonth->thal = myListCurrent->thal;
            newMonth->thalach = myListCurrent->thalach;
            newMonth->age = myListCurrent->age;

            current->next = newMonth;
    
            current = current->next;
            myListCurrent = myListCurrent->next;
        }
        current->next = nullptr;
        ageYear = mylist.ageYear;
    }
}

Summary::~Summary(void) {
    /*
    This is the destructor. This funciton utilizes 
    the clear function to delet the entire linked list.
    */
    clear();
}

Summary Summary::operator= (const Summary &mylist) { 
    /*
    This method returns this. This method iterates through other list 
    To add to itself. Then it returns itself.
    */
    clear();
    // Copy construct mylist to this.
    Month* current = mylist.head;
    while (current != NULL) {
        append(current->chestPain, current->ca, current->thal, current->thalach, current->age);
        current = current->next;
    }

    return *this;
    
}



void Summary::append(double chestPain, double ca, double thal, double thalach, double age) {
    /*
    This is the append method for adding new data to the circular doubly linked list.
    It ensures the list has a maximum of 12 elements, deleting the oldest node when full.
    
    */

    assert(age >= 18);
    Month* newMonth = new Month(); // Assuming Month is the new struct/class for nodes
    newMonth->chestPain = chestPain;
    newMonth->ca = ca;
    newMonth->thal = thal;
    newMonth->thalach = thalach;
    newMonth->age = age;

    double forCp = chestPainScore(chestPain);
    double forCa = caScore(ca);
    double forThal = thalScore(thal);
    double forThalach = thalachScore(thalach);
    double forAge = ageMultiplier(age);

    newMonth->heartDiseaseScore = totalScore(forCp, forCa, forThal, forThalach, forAge);
    Month* current = head;
    if (ageYear < SUMMARYSIZE) {
        if (head == NULL) {
            head = newMonth;
            newMonth->next = NULL;
        } else {
            while(current->next != NULL) {
                current = current->next;
        }
        current->next = newMonth;
        newMonth->next = NULL;
    }
        ageYear++;
    }
    else {
        Month* temp = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newMonth;
        newMonth->next = NULL;
        head = head->next;
        delete temp; 
    }

}



void Summary::operator[](int index) { 
    /*
    This is operator equals whihc returns its dereference type. The 
    precondtion is integer index that is greater than or equal to 0 and less
    than the lenght of the linked list.
    Current is set to head, we iterate through the linked list 
    changing the value of current nextMonth until its index is reached. 
    Then we return the item of the Month.
    */
    assert(index >= 0 && index < ageYear && head != NULL);
    Month* current = head;
    if (current != NULL) {
        for (int i = 0 ; i < index; i++) {
            current = current->next;
        }
    }
    cout << "On Month " << index + 1 << endl;
    cout << "Your Chest Pain: " << current->chestPain << endl;
    cout << "Your CA: " << current->ca << endl;
    cout << "Thal: " << current->thal << endl;
    cout << "Thalach: " << current->thalach << endl;
    cout << "Your age is: " << current->age << endl;
    cout << "Your score is " << current->heartDiseaseScore << endl;
    cout << endl;

}


void Summary::insert(double chestPain, double ca, double thal, double thalach, double age ,double index) {
    /*
    This is the insert method which returns the void type. 
    The pre conditions are the item of the type and an intger for
    the index. What must be asserted is index must be greater than or 
    equal to zero and less than or equal to the length. If index is 0 then 
    if list is empty then head points to the new Month. Other side new Month next
    will be the head. And the head changes.

    Case 2: If index == 0. We will act as if it an an append funciton. 

    Case 3: Other wise loop through to the previous index. Have that Month point 
    our newMonth, and the new Month point to a temp.  
    */
    assert(index >= 0 && index <= length());
    assert(age >= 18);
    Month* newMonth = new Month(); // Assuming Month is the new struct/class for nodes
    newMonth->chestPain = chestPain;
    newMonth->ca = ca;
    newMonth->thal = thal;
    newMonth->thalach = thalach;
    newMonth->age = age;


    double forCp = chestPainScore(chestPain);
    double forCa = caScore(ca);
    double forThal = thalScore(thal);
    double forThalach = thalachScore(thalach);
    double forAge = ageMultiplier(age);

    newMonth->heartDiseaseScore = totalScore(forCp, forCa, forThal, forThalach, forAge);


    newMonth->next = NULL;
    Month* current = head;

    if (ageYear < SUMMARYSIZE) {
        if (index == 0) {
            if (head == NULL) {
                head = newMonth;
            }
            else {
                newMonth->next = head;
                head = newMonth;
            }
        }
        else if (index == length()) {
            append(chestPain, ca, thal, thalach, age);
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newMonth->next = current->next;
            current->next = newMonth;
        }
        ageYear++;
    } else {
        if (index == 0) {
            newMonth->next = head;
            head = newMonth;
        } else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newMonth->next = current->next;
            current->next = newMonth;           
        }
        while(current->next->next != nullptr) {
            current = current->next;
        }
        Month* temp = current->next;
        delete temp;
        current->next = nullptr;
    }
}



void Summary::remove(int index) {
    /*
    This is the remove funciton. This is void return type 
    and takes in an integer index as a parameter. 
    This only works if head does not equal null other wise 
    there is nothing to remove. 
   
    This function asserts that index is greater or equal to zero. 

    Case 1: Create assert index and zero and other Months
    
    Case 2: Index zero and only one Month

    Case 3: Any index that follows the assert, loop through until the 
    previous index to have the Month point to the Month over the Month it points to 
    and delete that Month. 
    */
    Month* current = head;
    Month* temp;
    if (head != NULL) {
        assert(index >= 0 && index < length());
        if (index == 0) {
            temp = head;
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
            delete temp;
        } 

    }
}

/*
// Removed 'template <class T>' and updated return and parameter types
Summary Summary::operator+ (const Summary& mylist) const { 
    
    This operator creates and returns a new List that is the concatenation
    of the current list and the given list (mylist).
    
    Summary combinedList(*this); 

    Month* myListPointer = mylist.head;
    while (myListPointer != NULL) {
        combinedList.append(myListPointer->item);
        myListPointer = myListPointer->nextMonth;
    }

    return combinedList;
}

*/

int Summary::length(void) const {
    /*
    This is the length funciton. This function returns the integer
    There are no preconditions for the parameters. It starts of with 
    number of Months being zero then loops through the linked list. 
    If the head->nextMonth is null the number of Months returned is zero. Other wise
    the funciton loops through the linked list until it points to null. 
    and increments the number of Months. Then that final number is reuturned.
    */
    return ageYear;
}


bool Summary::isEmpty(void) const {
    /*
    This function returns a boolean. This funciton
    will run another function in the class called 
    length (Which returns an integer) if the length == 0
    this funciton returns true otherwise it returns false.
    */
    return ageYear == 0;
}


void Summary::clear(void) {
    /*
    This is the clear funciton returns void 
    With preconditions. This funciton sets a temp
    pointer that points to the head and keeps iterating 
    through the linked list until the Month is null. It sets a 
    new head and deletes the previous head stored as temp.
    */
    Month* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    ageYear = 0;
    head = NULL;
}

double Summary::chestPainScore(double cp) {
    /*
    This is the funciton that takes reported chest pain 
    and returns the value based on the report. 

    Pre Condtions: Chest Pain int value
    */
    cp = static_cast<int>(ceil(cp)); // I searched this up. This rounds the value up. 
    double score = 0;
    if (cp <= 0) {
        score = -1 * 3;
    } else if (cp == 1) {
        score = 2 * 3;
    } else if (cp == 2) {
        score = 6 * 3;
    } else {
        score = 10 * 3;
    }
    return score;
}

double Summary::caScore(double ca) {
    /*
    This function returns the caScore based on the ca
    parameter. The parameter is turned into an integer then
    multiplied by 2.75 and returned. 

    Pre conditions: Double Ca paramter
    Post conditions: Returned Double Value of score based on Ca
    */
    ca = static_cast<int>(ceil(ca)); // I searched this up. This rounds the value up. 

    double score = 0;
    if (ca <= 0) {
        score = 0;
    } else if (ca == 1) {
        score = 2 * 2.75;
    } else if (ca == 2) {
        score = 4 * 2.75;
    } else if (ca == 3) {
        score = 8 * 2.75;
    } else {
        score = 10 * 2.75;
    }
    return score;
}

double Summary::thalScore(double thal) {
    /*
    This function returns the thal Score based on the thal
    parameter. The parameter is turned into integer then muliplied by 2.5
    The returned. 

    Pre Condition: Double Thal Parameter
    Post Condition: Returned Double calue from Thal.
    */
    thal = static_cast<int>(ceil(thal)); // I searched this up. This rounds the value up. 

    double score = 0;
    if (thal <= 0) {
        score = 0;
    } else if (thal == 1) {
        score = 1 * 2.5;
    } else if (thal == 2) {
        score = 6 * 2.5;
    } else {
        score = 10 * 2.5;
    }
    return score;
}

double Summary::thalachScore(double thalach) {
    thalach = static_cast<int>(ceil(thalach)); // I searched this up. This rounds the value up. 
        /*
    This function returns the thalach Score based on the thal
    parameter. The parameter is turned into integer then muliplied by 2.5
    The returned. 

    Pre Condition: Double Thalach Parameter
    Post Condition: Returned Double calue from Thalach.
    */

    double score = 0;
    if (thalach >= 170) {
        score = -1 * 2.25;
    } else if (thalach >= 150) {
        score = 0;
    } else if (thalach >= 130) {
        score = 6 * 2.25;
    } else {
        score = 10 * 2.25;
    }
    return score;
}

double Summary::totalScore(double chestScore, double caScore, double thalScore, double thalachScore, double ageMultiplier) {
    /*
    This funciton returns the score for heart rate succeptibility. 

    Preconditions: Calculated Chest Pain Score, Ca Score, Thal Score, Thalach Score, Multiplier
    Postconditions: A score of the double type that is returned.
    */
    return ((chestScore + caScore + thalScore + thalachScore) * ageMultiplier) / 4.0;
}

void Summary::createPlotTxtFile(string fileName) {
    /*
    This function returns a void type and utliizes the fstream 
    C++ library. The funciton will take the fileName as parameter. 
    Then will start at the first node of the linked list. And iterate until
    throught the list until null. Then writes on the file the age and the heart Disease score
    in the txt file so it can be plotted in 2d. 

    PreCondition: String Txt File
    Post Condtion: Wrtitten Text file that formatted like 

    18 12.2
    19 18.1
    20 16.3
    Etc.....
    */
    ofstream outputFile(fileName);
    Month* current = head;
    double count = current->age;
    while (current != nullptr) {
        outputFile << count << " " << current->heartDiseaseScore << endl;
        count = count + 1;
        current = current->next;
    }
    
    outputFile.close();
}

double Summary::ageMultiplier(double reportedAge) {
    /*
    This is the age multiplir function. This function takes in reported age
    as a paramter then it then returns a double value that is a multiplier. 
    

    There are if and else statements which is basically as the person gets 
    older then heart rate succesibilyt basically get get mutiliped by a higher value 


    Pre condition: Double type age value. 
    Post conditon: Returned double value based on conditions. 
    */
    double value = 1;
    assert(reportedAge >= 18);
    if (reportedAge >= 18 && reportedAge < 35) {
        value = value + 0;
    } else if (reportedAge >= 35 && reportedAge < 50) {
        value = value + .1;
    } else if (reportedAge >= 50 && reportedAge < 65) {
        value = value + .2;
    } else {
        value = value + .35;
    }
    return value;
}


