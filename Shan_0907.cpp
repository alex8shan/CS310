/**
 *  A driver program for the time class
 *  @author Minghao Shan
 *  @version 7/9/2017
 */
#include "Shan_0907.h"

#include <iostream>

using namespace std;

/**
*   This method addes the second parameter to the time
*   @param &time The reference of time needs to be increased
*   @param hour The number of hours needs to be added
*/
void advance_hours(Time &time, uint8_t hour)
{
    for (uint8_t i = 0; i < hour * 60; ++i)
    {
        time.tick();
    }
}

int main()
{
    Time t1(1, 14);
    Time *t2 = new Time(13, 55);
    Time t3(7, 31);

    cout << "time 1 is: " << t1.to_string_24() << endl;
    cout << "time 2 is: " << t2->to_string_ap() << endl;

    advance_hours(t3, 2);
    cout << "after adding two hours, time 3 is: " << t3.to_string_ap() << endl;
    return 0;
}
