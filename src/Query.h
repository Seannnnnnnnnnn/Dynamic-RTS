#pragma once

struct Query {
    int l;      // Left endpoint of the interval
    int r;      // Right endpoint of the interval
    int tau;    // Threshold value
    int count;  // Running count of weights
    bool alive; // Status of the query
    int dt_threshold;  // Distributed Tracking threshold

    Query(int l, int r, int tau);

    bool isAlive() const;
    bool stabsInterval(int value) const;
    
    int getLeft() const { return l; }
    int getRight() const { return r; }

    // methods for distributed tracking
    void updateThreshold(int weight) { dt_threshold += weight; };
    int getThreshold() const { return dt_threshold; };
};
