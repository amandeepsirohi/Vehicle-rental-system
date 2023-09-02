#ifndef Date_h
#define Date_h
/*include custom headers */
#include "storable.cpp"
/*include standard cpp headers*/
#include <ctime>
#include <string>

using namespace std;

typedef struct Date 
{
    private:
        /*structure holding date and time info*/
        struct tm date;
        bool empty;
    public:
        /*Constructor create date from string*/
        Date(string date);
        /*Create Date from current time*/
        Date();

        /*Add given Number of Days on this Date*/
        Date operator + (int days);

        /*If this date is greater than given date*/
        bool operator > (Date date) const;

        /*if this date is greater than or equal to given date*/
        bool operator >= (Date date) const;

        /*If this date is smaller than given date*/
        bool operator < (Date date) const;

        /*if this date is greater than or equal to given date*/
        bool operator <= (Date date) const;

        bool is_Empty() const;

        string to_String() const;
} Date;
#endif