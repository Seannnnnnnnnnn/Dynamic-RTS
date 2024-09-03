#include <iostream>


struct Query{
    // represents an (D)RTS query
    int l; 
    int r;
    int delta;  // shift factor for DRTS queries
    int tau;
    bool alive = true;
    bool is_valid(){return l < r;}
};



class EndPointTree(){
    
}


int main(){
    Query q = Query();
}
