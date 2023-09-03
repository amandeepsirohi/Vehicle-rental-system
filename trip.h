#ifndef trip_h
#define trip_h

/*include custom headers*/
#include "vehicle.h"
#include "user.h"
#include "date.h"
#include "storable.cpp"

/*include standard headers*/
#include <string>

using namespace std;

/*Trip class helps manage trips related data*/
class Trip : public Storable
{
    private: 
        /*const pointer to const vehicle in memory.
        We will create user in memory and assign address of that vehicle to 'vehicle'
        .This is a const pointer so that it can't point to other  vehicle objects */
        const Vehicle *vehicle;

        /*const pointer to const user in memory.
        We will create user in memory and assign address of that user to 'user'
        .This is a const pointer so that it can't point to other  user objects */
        const User *user;

        /*We need to track record of starting and ending time of trip so that 
        we can see which vehicles are free*/

        /*start date of trip*/
        Date startDate;

        /*End date of trip*/
        Date endDate;

        /*we need to keep track of odometer so that fare can be calculated*/
        long startReading;
        long endReading;

        /*Fare of the trip*/
        double fare;

        /*Trip Completed or not*/
        bool completed;

    public:
        /*constructor of trip class*/
        Trip(const Vehicle *vehicle , const User *user , Date startDate , Date endDate , 
        long recordId = 0 , long startReading = 0 , long endReading = 0 , double fare = 0.0,
        bool isCompleted = false);

        /*assigning each getter function constant as defined in previous classes*/

        const User &getUser() const;
        
        const Vehicle &getVehicle() const;

        Date getStartDate() const;

        Date getEndDate() const;

        long getStartReading() const;

        long getEndReading() const;

        long getFare() const;
        
        bool isCompleted() const;

        void startTrip(long startRecording);

        double completeTrip(long endRecording);

        void display() const;

        /*overriden virtual method*/
        string toString() const;

        void setDataFrom(Storable *s);
};
#endif