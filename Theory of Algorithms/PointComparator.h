#include "Point.h"

#ifndef POINTCOMPARATOR_H_
#define POINTCOMPARATOR_H_

struct PointComparator {
	bool operator()(const Point *arg1, const Point *arg2) const {
		return arg1->x < arg2->x;
	}
};

#endif /* POINTCOMPARATOR_H_ */
