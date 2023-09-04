/*Include custom headers*/
#include "table.h"

/*Include standard cpp headers */
#include <iostream>

using namespace std;

template <class T> Table<T> :: Table (string filename) throw
(MemoryError)
{
    //save file name for future use
    this->fileName = fileName;

    /*Create memory to store all records */
    /*remember we will store only addresses of records inside this vector*/
    /*Actual record can be accessed by dereferencing data data found at
    specific index of vector*/

    /*do not forgot to free up memory in destructor*/
    this->records = new vector<Storable*> ();

    if(!this->records)
    {
        throw MemoryError();
    }
}

template <class T> long Table<T> :: getNextRecordId() const 
{
    /*Next record is of total size +1 */
    return this->records->size() + 1;
}

template <class T> const T* const Table<T> :: addNewRecord (T record)
throw(MemoryError , IOError)
{
    /*We will create new record in memory , 'newRecord' is the pointer
    to new record*/
    T* newRecord = new T(record);

    if(!newRecord)
    {
        /*throw an exception*/
        throw new MemoryError();
    }
    newRecord->recordId = this->getNextRecordId();

    /*store address of new record in 'record' vector*/
    this->records->push_back(newRecord);

    /*Write data to a file*/
    try{
        this->writeToFile();
    }
    catch(IOError error)
    {
        /*clean up things*/
        this->records->pop_back();
        delete newRecord;

        /*rethrow Exception*/
        throw;
    }

    /*Return newly created record as const so no one can modify it*/
    return newRecord;
}

template <class T> void Table<T> :: updateRecord (T updatedRecord) throw 
(IOError , NoSuchRecordError)
{
    /*First find the original record index*/
    for(auto &record : *this->records)
    {
        if(record->getRecordId() == updatedRecord.getRecordId())
        {
            /*record is a pointer pointing at some record in heap memory*/
            /*we will directly change data to that address*/

            /*Now record is pointing at new updated record in memory*/
            /*We will create a backup record so if write fails , we can 
            restore from backup*/   
             T* pointerToRecord = dynamic_cast<T*> (record);
             
             if(pointerToRecord)
             {
                T oldRecord = T (*pointerToRecord);
                record->setDataFrom(&updatedRecord);

                /*write data to file*/
                try{
                    this->writeToFile();
                    return;
                }
                catch(IOError error)
                {
                    /*clean up things*/
                    record->setDataFrom(&oldRecord);

                    /*Rethrow exception*/
                    throw;
                }
             }
        }
    }
    throw NoSuchRecordError();
}

template <class T> void Table<T> :: writeToFile () throw (IOError)
{
    /*In this file we will overwrite file with all the data that we have*/
    /*so open file with mode 'ios::out | ios::trunc'*/

    this->fileStream.open(fileName , ios::out | ios::trunc);

    if(!this->fileStream)
    {
        //throw an exception
        throw IOError();
    }

    for(auto &record : *records)
    {
        /*write record to file*/
        fileStream << record->toString () << endl;
    }
    
    /*Finally close the file*/
    this->fileStream.close();
}

template <class T> const T* const Table<T> :: getRecordForId(long recordId)
const throw (NoSuchRecordError)
{
    try{
        return this->getRefrenceOfRecordForId (recordId);
    }
    catch(NoSuchRecordError error)
    {
        throw;
    }
}

template <class T> T* Table<T> :: getRefrenceOfRecordForId (long recordId)
const throw(NoSuchRecordError)
{
    for(auto &record : *records)
    {
        if(record->getRecordId() == recordId)
        {
            return dynamic_cast<T*> (record);
        }
    }
    /*we are out of loop hence no record found*/
    throw NoSuchRecordError();
}

template <class T> Table<T> :: ~Table()
{
    /*Remove any dynamically created memory*/
    for(auto  & record : *this->records)
    {
        /*to delete the in-memory data pointed to by 'record'*/
        delete dynamic_cast<T*> (record);
    }

    /*Now 'this->records' contains address of memory segments which has
    no data (or corrupted data)*/
    /*so clear all addresses from 'this->records'*/
    this->records->clear();

    /*This will reduce memory size taken by vector 'this->records'*/
    this->records->shrink_to_fit();

    /*finally delete memory pointed by 'this->records'*/
    delete this->records;
}