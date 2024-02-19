
#ifndef INTEGERCOMPARATOR_H_
#define INTEGERCOMPARATOR_H_

struct IntegerComparator {
	bool operator()(const int &arg1, const int &arg2) const {
		return arg1 < arg2;
	}
};

#endif /* INTEGERCOMPARATOR_H_ */
