#pragma once

struct Query {
    int l;      // Left endpoint of the interval
    int r;      // Right endpoint of the intervals
    int tau;    // Threshold value
    int count;  // Running count of weights
    bool alive; // Status of the query

    Query(int l, int r, int tau);

    bool isAlive() const;
    bool stabsInterval(int value) const;
    
    int getLeft() const { return l; }
    int getRight() const { return r; }

    // methods for distributed tracking
    void updateThreshold(int weight);
    int getThreshold() const { return tau; };
};
