

#ifndef IntegerComparator_h
#define IntegerComparator_h

struct IntegerComparator {
    int operator()(const int arg1,
                   const int arg2) const {
        return arg1 > arg2;
    }
};

#endif /* IntegerComparator_h */
