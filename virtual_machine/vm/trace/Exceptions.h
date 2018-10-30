#ifndef EXCEPTIONS_H 
#define EXCEPTIONS_H

#include <vector>

class Exceptions {
  
    private:
        std::vector <int> positions;
        
    public:
        void push(int position);
        int pop(); //-1 if empty
        int last(); //-1 if empty
        
};

#endif