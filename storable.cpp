#ifndef storable_cpp
#define storable_cpp

/*include custom headers */
#include "serializable.cpp"

/*include standard cpp headers*/

#include <string>
#include <iostream>

using namespace std;
 class Storable : public serializable
 {
    protected:
        long recordId;
    public:
        Storable(long recordId) {this->recordId = recordId;}
        long getrecId() const{return this->recordId;}
        virtual void setDataFrom(Storable *s) = 0;
        template<class T> friend class Table;
        friend class Database;
 };
#endif