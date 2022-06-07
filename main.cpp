#include <iostream>
#include <chrono>
#include <algorithm>
#include "txt.h"

using HRClock = std::chrono::high_resolution_clock;
using Nanosec = std::chrono::nanoseconds;
using TPoint  = std::chrono::system_clock::time_point;


l1::Txt getTempObject(l1::Txt copy, TPoint& start);
uint64_t getTime(const TPoint& start, const TPoint& end);


l1::Txt getTempObject(l1::Txt copy, TPoint& start)
{
    start = HRClock::now();

    return copy;
}


uint64_t getTime(const TPoint& start, const TPoint& end)
{
    return std::chrono::duration_cast<Nanosec>(end - start).count();
}

int main(int argc, char* argv[])
{
    TPoint start, end;


    //Default constructor
    start = HRClock::now();

    l1::Txt a;

    end = HRClock::now();

    std::cout << "Default constructor: " << getTime(start, end) << " nanoseconds, "
              << "a.size(): " << a.size() << "\n";


    //Custom constructor
    start = HRClock::now();

    l1::Txt b(argv[1]);

    end = HRClock::now();

    std::cout << "Custom constructor: " << getTime(start, end) << " nanoseconds, "
              << "b.size(): " << b.size() << "\n";


    //Copying assignment (to empty obj)
    start = HRClock::now();

    a = b;

    end = HRClock::now();

    std::cout << "Copying assignment (to empty obj): " << getTime(start, end) << " nanoseconds, "
              << "a.size(): " << a.size() << "\n";


    //Copying assignment (to non-empty obj)
    start = HRClock::now();

    a = b;

    end = HRClock::now();

    std::cout << "Copying assignment (to non-empty obj): " << getTime(start, end) << " nanoseconds, "
              << "a.size(): " << a.size() << "\n";


    //Moving assignment (to empty obj)
    l1::Txt c;

    c = getTempObject(argv[1], start);

    end = HRClock::now();

    std::cout << "Moving assignment (to empty obj): " << getTime(start, end) << " nanoseconds, "
              << "c.size(): " << c.size() << "\n";


    //Moving assignment (to non-empty obj)
    c = getTempObject(argv[1], start);

    end = HRClock::now();

    std::cout << "Moving assignment (to non-empty obj): " << getTime(start, end) << " nanoseconds, "
              << "c.size(): " << c.size() << "\n";


    //Destructor
    start = HRClock::now();

    a.clear();

    end = HRClock::now();

    std::cout << "Destructor: " << getTime(start, end) << " nanoseconds\n";



    return 0;
}
