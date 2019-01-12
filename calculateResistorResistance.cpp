#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<string> colorData = {"(1) black","(2) brown","(3) red","(4) orange","(5) yellow","(6) green","(7) blue","(8) violet","(9) gray","(10) white"}; // actual values correspond to positions, zero-indexed, in this vector;
    string response, tolerance, colorFirst, colorSecond, colorThird, colorFourth;
    // Gold is tolerance of +/5%, silver is 10%;
    float resistance;

    cout << "\n\nCalculate the resistance of an axial 3, or 4-band resistor";
    cout << "\n==============================================================\n";

    while (response!="3" && response!="4") {
        cout << "\nHow many colored bands are on your resistor, NOT including the silver or gold one on the end?: ";
        getline(cin, response);
        if (response=="3" || response =="4") {
            cout << "\n\nOk, " + response + " bands!\n\nTurn your resistor so that the gold or silver band is on the right.";
        }
    }

    cout << "\n\nWhat color is the first band?";
    for (auto c:colorData) {
        cout << "\n\t"+ c;
    }
    cout << "\n\nType a number and press enter: ";
    getline(cin, colorFirst);


    cout << "\n\nWhat color is the second band?: ";
    for (auto c:colorData) {
        cout << "\n\t"+ c;
    }
    cout << "\n\nType a number and press enter: ";
    getline(cin, colorSecond);

    cout << "\n\nWhat color is the third band?: ";
    for (auto c:colorData) {
        cout << "\n\t"+ c;
    }
    cout << "\n\nType a number and press enter: ";
    getline(cin, colorThird);

    if (response == "4") {
        cout << "\n\nWhat color is the fourth band?: ";
        for (auto c:colorData) {
            cout << "\n\t"+ c;
        }
        cout << "\n\nType a number and press enter: ";
        getline(cin, colorFourth);
    }

    cout << "\n\nIs the final band (s)ilver or (g)old?";
    cout << "\nType the letter in parentheses and press enter: ";
    getline(cin, colorFourth);

    if (response == "3") {
        resistance = pow(10, stoi(colorThird)) * (stoi(colorFirst)*10 + stoi(colorSecond));
    } else if (response == "4") {
        resistance = pow(10, stoi(colorFourth)) * (stoi(colorFirst)*100 + stoi(colorSecond)*10 + stoi(colorThird));
    } else {
        ;
    }

    if (colorFourth=="g" || colorFourth=="G") {
        tolerance = "5%";
    } else {
        tolerance = "10%";
    }

    cout << "\n\nThe resistance is " << resistance << " Ohms, plus or minus " << tolerance << "." << endl;

    return resistance;
}
