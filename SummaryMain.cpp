#include "Summary.h"

int main () {
    Summary SummaryOne;

SummaryOne.append(0, 0, 0, 170, 18);
SummaryOne.append(0, 0, 0, 170, 18);
SummaryOne.append(0, 0, 0, 169, 19);
SummaryOne.append(0, 0, 0, 168, 20);
SummaryOne.append(0, 0, 0, 167, 21);
SummaryOne.append(0, 0, 0, 166, 22);
SummaryOne.append(0, 0, 0, 165, 23);
SummaryOne.append(0, 0, 0, 164, 24);
SummaryOne.append(0, 0, 0, 163, 25);
SummaryOne.append(0, 0, 0, 162, 26);
SummaryOne.append(0, 0, 0, 161, 27);
SummaryOne.append(0, 0, 0, 160, 28);
SummaryOne.append(0, 0, 0, 159, 29);
SummaryOne.append(1, 1, 1, 158, 30);
SummaryOne.append(1, 1, 1, 157, 31);
SummaryOne.append(1, 1, 1, 156, 32);
SummaryOne.append(1, 1, 1, 155, 33);
SummaryOne.append(1, 1, 1, 154, 34);
SummaryOne.append(1, 1, 1, 153, 35);
SummaryOne.append(1, 1, 1, 152, 36);
SummaryOne.append(1, 1, 1, 151, 37);
SummaryOne.append(1, 1, 1, 150, 38);
SummaryOne.append(1, 1, 1, 149, 39);
SummaryOne.append(1, 1, 1, 148, 40);
SummaryOne.append(2, 2, 2, 147, 41);
SummaryOne.append(2, 2, 2, 146, 42);
SummaryOne.append(2, 2, 2, 145, 43);
SummaryOne.append(2, 2, 2, 144, 44);
SummaryOne.append(2, 2, 2, 143, 45);
SummaryOne.append(2, 2, 2, 142, 46);
SummaryOne.append(2, 2, 2, 141, 47);
SummaryOne.append(2, 2, 2, 140, 48);
SummaryOne.append(2, 2, 2, 139, 49);
SummaryOne.append(2, 2, 2, 138, 50);
SummaryOne.append(2, 2, 2, 137, 51);
SummaryOne.append(3, 3, 3, 136, 52);
SummaryOne.append(3, 3, 3, 135, 53);
SummaryOne.append(3, 3, 3, 134, 54);
SummaryOne.append(3, 3, 3, 133, 55);
SummaryOne.append(3, 3, 3, 132, 56);
SummaryOne.append(3, 3, 3, 131, 57);
SummaryOne.append(3, 3, 3, 130, 58);
SummaryOne.append(3, 3, 3, 129, 59);
SummaryOne.append(3, 3, 3, 128, 60);
SummaryOne.append(3, 3, 3, 127, 61);
SummaryOne.append(3, 3, 3, 126, 62);
SummaryOne.append(3, 3, 3, 125, 63);
SummaryOne.append(3, 3, 3, 123, 64);
SummaryOne.append(3, 3, 3, 121, 65);
SummaryOne.append(3, 3, 3, 119, 66);
SummaryOne.append(3, 3, 3, 117, 67);
SummaryOne.append(3, 3, 3, 114, 68);
SummaryOne.append(3, 3, 3, 111, 69);
SummaryOne.append(3, 3, 3, 109, 70);
SummaryOne.append(3, 3, 3, 107, 71);
SummaryOne.append(3, 3, 3, 105, 72);
SummaryOne.append(3, 3, 3, 103, 73);
SummaryOne.append(3, 3, 3, 101, 74);
SummaryOne.append(3, 3, 3, 100, 75);
SummaryOne.append(3, 3, 3, 99, 76);


    
    cout << SummaryOne;
    SummaryOne.createPlotTxtFile("data.txt");
    return 0;
}