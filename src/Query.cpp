#include "Query.h"

// Constructor
Query::Query(int l, int r, int tau) 
    : l(l), r(r), tau(tau), count(0), alive(true) {}

bool Query::isAlive() const {
    return l < r;
}

bool Query::stabsInterval(int value) const {
    return l <= value && value <= r;
}