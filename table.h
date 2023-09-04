#ifndef table_h
#define table_h

#include "storable.cpp"
#include "error.cpp"

#include <vector>
#include <string>
#include <fstream>

using namespace std;
       
/*this is a generic class and represents in-memory database table*/
/*table can be of 'Vehicle' , 'User' , 'Trip'*/

template<class T> class Table
{
    private:
        /*Name of database file*/
        string fileName;

        /*files stream used for read and write data from database file*/
        fstream filesStream;

        /*Original data is stored here*/
        /*'vector' is a container type and behaves like dynamic array*/
        vector<Storable *> *records = NULL;

        /*This is a private method*/
        /*We will share pointer of record with recordId = 'recordId'*/
        /*This is intentional and and hence kept as private method*/
        T * getRefrenceOfRecordForId(long recordId) const throw
        (NoSuchRecordError);

        /*This is a private function . It is called after inserting new record or
        updating data*/
        /*This function writes data to a file*/
        void writeToFile() throw (IOError);

        /*
        Add new record to database 
        input : fileName of Database
        .this method can throw 'MemoryError' or 'IOError'*/
        const T * const addNewRecord(T data) throw (MemoryError , IOError);

        /*Update record in database
        input : new Record of generic type 'T'
        .This method can Throw IO error
        */
       void updateRecord(T updatedRecord) throw 
       (IOError , NoSuchRecordError);
    
    public:
        /*Constructor:
        Input: fileName of database*/
        Table(string fileName) throw (MemoryError);
        ~Table();

        /*get recordId for next record*/
        long getNextRecordId() const;

        /*get record for particular 'recordId'
        input : recordId of record
        
        We will return const T* const (constant pointer to constant record)
        So user can not modify that record accidently
        .This method can throw 'NoSuchRecord' Exception */
        const T* const getRecordForId(long recordId) const throw(
            NoSuchRecordError);

        /*class database can use this class's private methods and vars*/
        /*We will use 'getRefrencerecordForId' to get actual record refrence*/
        friend class Database;
};
#endif


