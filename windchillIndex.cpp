// Description: A function to calculate windchill index
// Inputs: Wind speed in m/s, temp in C <=10
// Output: Windchill index in degrees C


#include <cmath>
#include <iostream>

using namespace std;



double windchillIndex(double windSpeed, double tempC) {
    double w;

    if (tempC > 10) {

        cout << "\nSorry, this program calculates windchill for temperatures under 10 degrees C. Aborting.\n";

        return 0;

    } else {

        w =  13.12 + (0.6215*tempC) - (11.37*pow(windSpeed, 0.16)) + (0.3965*tempC*pow(windSpeed, 0.016));
        return w;
    }
}


int main() {
    double ans = windchillIndex(1.79,4);

    cout << ans << "\n" ;
    return 0;
}
