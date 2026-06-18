#include <iostream>
#include <cmath>
using namespace std;

double angleClock(int hour, int minutes) {
    if (hour == 12)
        hour = 0;

    double hourAngle = 30 * hour + minutes * 0.5;
    double minuteAngle = minutes * 6;

    double angle = abs(hourAngle - minuteAngle);

    return min(angle, 360 - angle);
}

int main() {
    int hour, minutes;

    cout << "Enter hour: ";
    cin >> hour;

    cout << "Enter minutes: ";
    cin >> minutes;

    cout << "Smaller angle: " << angleClock(hour, minutes) << " degrees" << endl;

    return 0;
}