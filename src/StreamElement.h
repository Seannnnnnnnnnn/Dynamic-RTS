#pragma once

struct StreamElement {
    int value;
    int weight; 

    StreamElement(int value, int weight) : 
        value(value), weight(weight) {}
};
