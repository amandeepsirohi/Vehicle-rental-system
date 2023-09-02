#ifndef storable_cpp
#define storable_cpp

/*include custom headers */
#include "serializable.cpp"

/*include standard cpp headers*/

#include <string>
#include <iostream>

using namespace std;
/*Storable is a class which can be stored in a file. 
Anything which is Storable must have a recordId(unique Key).
derived from serializable i.e. if anything is storable must be serializable.
(must have to_string() method)*/
 class Storable : public Serializable
 {
    protected:
        //unique recordId , acts as primary key to find data
        /*this property(recordId) is protected . so only derived
        class member can access it directly */
        long recordId;
    public:
        /*constructor function , i/p is recordId*/
        Storable(long recordId) {this->recordId = recordId;}
        long getRecordId() const{return this->recordId;}
        /*Pure Virtual function.
        Every Subclass of this class must provide a suitable way to set 
        this object from Storable *s*/
        //similar to copy constructor
        virtual void setDataFrom(Storable *s) = 0;
        /*Friend's Declaration*/
        /*Table and database can access private members of this class*/
        /*Table class : It sets 'recordId' of object inside 'addNewRecord' method
        */
        /*Database class : It sets 'recordId' of object inside 'addNewRecord' method
        */
        template<class T> friend class Table;
        friend class Database;
 };
#endif