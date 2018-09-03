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



// SOLUTION:


// First:
// Check if the meeting in the array happens before the next one:
bool compareMeetingsByStartTime(
    const Meeting& firstMeeting,
    const Meeting& secondMeeting)
{
    return firstMeeting.getStartTime() < secondMeeting.getStartTime();
}

// Now our merge algorithm
vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    // First, sort by start time:
    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareMeetingsByStartTime);
    
    // Initialize mergedMeetings with the earliest meeting:
    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings.front());
    
    for (const Meeting& currentMeeting : sortedMeetings)
    {
        Meeting& lastMergedMeeting = mergedMeetings.back();
        
        if (currentMeeting.getStartTime() <= lastMergedMeeting.getEndTime())
        {
            // If the current meeting overlaps with the last merged meeting,
            // later end time of the two
            lastMergedMeeting.setEndTime(max(lastMergedMeeting.getEndTime(),
                currentMeeting.getEndTime()));
        }
        else
        {
            // Add the current meeting since it doesn't overlap
            mergedMeetings.push_back(currentMeeting);
        }
    }
    
    return mergedMeetings;
}