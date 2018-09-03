#include <iostream>
#include <vector>

using namespace std;

class Meeting
{
private:
    // number of 30 min blocks past 9:00 am
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting() :
        startTime_(0),
        endTime_(0)
    {
    }

    Meeting(unsigned int startTime, unsigned int endTime) :
        startTime_(startTime),
        endTime_(endTime)
    {
    }

    unsigned int getStartTime() const
    {
        return startTime_;
    }

    void setStartTime(unsigned int startTime)
    {
        startTime_ = startTime;
    }

    unsigned int getEndTime() const
    {
        return endTime_;
    }

    void setEndTime(unsigned int endTime)
    {
        endTime_ = endTime;
    }

    bool operator==(const Meeting& other) const
    {
        return
            startTime_ == other.startTime_
            && endTime_ == other.endTime_;
    }
};