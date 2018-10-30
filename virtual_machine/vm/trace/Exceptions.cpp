#include "Exceptions.h"

void Exceptions::push(int position){
    positions.push_back(position);
}

int Exceptions::pop(){
    if(positions.empty()){
        return -1;
    }
    
    int last = positions.back();
    positions.pop_back();
    return last;
}

int Exceptions::last(){
    return positions.empty() ? -1 : positions.back();
}