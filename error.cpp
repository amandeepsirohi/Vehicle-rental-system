#ifndef error_cpp 
#define error_cpp 
/*Including standard cpp h   eaders*/
#include<string>
using namespace std;

class Error
{
    private:
        string message;
    public:
        Error(string message)
        {
            this->message = message;
        }
        string getMessage() const {return this->message;}
};
/*Checks if record is present or not*/
class NoSuchRecordError : public Error
{
    public:
        NoSuchRecordError() : Error("No Such record Found") {};
};
/*checks if files exist or not or any kind of I/O error*/
class IOError : public Error
{
    public:
        IOError() : Error("I/O Error => could not open or process the file , make sure 'vehicle.txt' , 'trips.txt' and 'user.txt' files exist in the directory") {}; 
};
/*Checks wether system is out of memory*/
class MemoryError: public Error 
{
    public: 
    
        MemoryError() : Error("System Out of Memory") {};
    
};
#endif
