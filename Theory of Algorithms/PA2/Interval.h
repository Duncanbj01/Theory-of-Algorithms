#include <string>
using namespace std;

#ifndef INTERVAL_H_
#define INTERVAL_H_

class Interval {
public:
	char name;
	int start, end;

	Interval(char n, int s, int e) {
		name = n;
		start = s;
		end = e;
	}

	string toString() {
		string out = "(";
		out += name;
		out += ", ";
		out += to_string(start);
		out += ", ";
		out += to_string(end) + ")";
		return out;
	}
};

#endif /* INTERVAL_H_ */
