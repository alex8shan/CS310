#ifndef SHAN_0907_H
#define SHAN_0907_H

#include <cstdint>
#include <string>

using namespace std;

/**
 *  A class that provides functions for time. 
 *  @auuthor Minghao Shan
 *  @version 7/9/2017
 */
class Time
{
    public:
    /**
    *   Constructor with 0 paramater that sets the default value
    */
    Time()
    {
        hours = 0;
        minutes = 0;
    }

    /**
    *   Constructor with 2 paramaters that sets the passed value
    */
    Time(uint8_t hour, uint8_t minute)
    {
        hours = hour;
        minutes = minute;
    }

    /**
    *   This is the implemented lvalue copy constructor
    */
    Time(const Time &rhs)
        : hours{rhs.hours},
          minutes{rhs.minutes} 
    {
    } 

    /**
     *  This is the implemented lvalue = operator
     */
    Time &operator=(const Time &rhs)
    {
        hours = rhs.hours;
        minutes = rhs.minutes;
        return *this;
    }

    /** 
    *   This disables the rvalue copy constructor
    */

    Time(Time &&rhs) = delete;

    /**
    *   This disables the rvalue =  operator.
    */
    Time &operator=(Time &&rhs) = delete;

    /**
    *   The default destructor
    */
    ~Time() = default;

    /**
    *   This method returns the string format of the time in military time.
    *   @return 5 character string formatted as hh:mm
    */
    string to_string_24() const
    {
        return formatField(hours) + ":" + formatField(minutes);
    }

    /**
    *   This method returns the string format of the time in AM/ PM format.
    *   @return 7 character string as [h]h:mm xM, x is either A or P
    */
    string to_string_ap() const
    {
        if (hours < 13)
        {
            if (hours == 12)
            {
                return to_string(hours) + ":" + formatField(minutes) + " PM";
            }
            else
            {
                return to_string(hours) + ":" + formatField(minutes) + " AM";
            }
        }
        else
        {
            return to_string(hours - 12) + ":" + formatField(minutes) + " PM";
        }
    }

    /**
    *   This method increase the time by one minute.
    */
    void tick()
    {
        if (hours == 23 && minutes == 59)
        {
            hours = 0;
            minutes = 0;
        }
        else if (minutes == 59)
        {
            hours++;
            minutes = 0;
        }
        else
        {
            minutes++;
        }
    }

    private:
    uint8_t hours;
    uint8_t minutes;
    /**
    *   This method adds a zero if the minute or hour is less than 10.
    *   @param  the number that might needs to add zero
    *   @return string format of the number with possible zero added.
    */
    string formatField(uint8_t num) const
    {
        string retval;
        if (num < 10)
        {
            retval = "0";
        }
        return retval + to_string(num);
    }
};
#endif