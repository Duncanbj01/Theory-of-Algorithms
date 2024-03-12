#include "Interval.h"
#include "IntegerComparator.h"
#include <vector>
#include <algorithm>
using namespace std;

#ifndef GREEDYINTERVALS_H_
#define GREEDYINTERVALS_H_

class GreedyIntervals {

private:

	struct sort_by_start {
		bool operator()(const Interval &arg1, const Interval &arg2) const {
			return arg1.start < arg2.start;
		}
	};

	struct sort_by_end {
		bool operator()(const Interval &arg1, const Interval &arg2) const {
			return arg1.end < arg2.end;
		}
	};

	static void sortIntervalsByStartTime(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), sort_by_start());
	}

	static void sortIntervalsByEndTime(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), sort_by_end());
	}

public:

    static vector<Interval> schedule(vector<Interval> &intervals) 
	{ // complete this method

		sortIntervalsByEndTime(intervals); 
		vector<Interval> optimal; 
		optimal.push_back(intervals[0]); 
		for (size_t i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start >= optimal.back().end)
			{
				optimal.push_back(intervals[i]); 
			}
		}

		return optimal; 
    }

    static int color(vector<Interval> &intervals) 
	{ // complete this method
		sortIntervalsByStartTime(intervals); 
		priority_queue<int, vector<int>, greater<int>> endTime; 
		endTime.push(intervals[0].end); 

		for (size_t i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start >= endTime.top())
			{
				endTime.pop(); 
			}
			endTime.push(intervals[i].end); 
		}
		return endTime.size(); 
    }
};

#endif /* GREEDYINTERVALS_H_ */
