#ifndef MUTEX_H
#define MUTEX_H

#include <map>
#include <pthread.h>
#include <cstdlib>

#define LOCK_CONSOLE 0

class Mutex {
    
    private:
        //std::map <int, pthread_mutex_t*> mutex;
  
    public:
        void init();
        void lock(int id);
        void unlock(int id);
    
};

#endif