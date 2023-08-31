#ifndef error_cpp 
#define error_cpp 

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
class NoSuchRecordError : public Error
{
    public:
        NoSuchRecordError() : Error("No Such record Found") {};
};
class IOError : public Error
{
    public:
        IOError() : Error("I/O Error => could not open or process the file , make sure 'vehicle.txt' , 'trips.txt' and 'user.txt' files exist in the directory") {}; 
};
class MemoryError: public Error 
{
    public: 
    
        MemoryError() : Error("System Out of Memory") {};
    
};
#endif