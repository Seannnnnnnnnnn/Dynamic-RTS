#pragma once

struct StreamElement {
    int weight; 
    int value;

    StreamElement(int value, int weight) : 
        value(value), weight(weight) {}
};
