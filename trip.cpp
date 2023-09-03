/*include custom headers */
#include "trip.h"
#include "string_helper.h"

/*include standard cpp headers*/
#include <iostream>

const char DELIMITER = ';';

Trip :: Trip(const Vehicle *vehicle , const User *user , Date startDate , 
Date endDate , long recordId , long startReading , long endReading , double fare , 
bool isCompleted) : Storable(recordId)
{
    this->vehicle = vehicle;
    this->user = user;
    this->startDate = startDate;
    this->endDate = endDate;
    this->startReading = startReading;
    this->endReading = endReading;
    this->fare = fare;
    this->completed = isCompleted;
}   

const User & Trip :: getUser() const {return *this->user;}

const Vehicle & Trip :: getVehicle() const {return *this->vehicle;}

Date Trip :: getStartDate() const {return this->startDate;}

Date Trip :: getEndDate() const {return this->endDate;}

long Trip :: getStartReading() const {return this->startReading;}

long Trip :: getEndReading() const {return this->endReading;}

long Trip :: getFare() const {return this->fare;}

bool Trip :: isCompleted() const {return this->completed;}

void Trip :: startTrip(long startReading)
{
    this->startReading = startReading;
}

double Trip :: completeTrip(long endReading)
{
    if(this->completed)
    {
        return this->fare;
    }

    this->endReading = endReading;
    this->fare = (this->endReading - this->startReading) * this->vehicle->getPricePerKm();
    this->completed = true;
    return this->fare;
}

void Trip :: display() const
{
    cout << "Vehicle Details : " << endl;
    cout << "Registration Number : " <<  this->vehicle->getRegistrationNumber() << endl;
    cout << "Company Name : " << this->vehicle->getCompanyName() << endl;
    cout << "Price Per Km : " << this->vehicle->getPricePerKm() << endl;

    cout << endl;

    cout << "User Details " << endl;
    cout << "Name : " << this->user->getName() << endl;
    cout << "Contact : " << this->user->getContact() << endl;

    cout << endl;

    cout << "Trip Details : " << endl;
    cout << "Start Date : " << this->startDate.toString() << endl;
    cout << "End Date : " << this->endDate.toString() << endl;

    string tripStatus = "Not started";
    if(this->startReading != 0)
    {
        tripStatus = "On Going";
        cout << "Start reading : " << this->startReading << endl;
    }
    if(this->completed)
    {
        tripStatus = "Completed";
        cout << "End Reading " << this->endReading << endl;
        cout << "Total Run " << this->endReading - this->startReading << endl;
        cout << "Total Fare " << this->fare;
    }
    cout << "Trip Status : " << tripStatus << endl;

}

std::string Trip :: toString() const
{
    stringstream ss;

    ss<<recordId << DELIMITER 
    <<vehicle->getRecordId() << DELIMITER
    <<user->getRecordId() << DELIMITER
    <<startDate.toString() << DELIMITER
    <<endDate.toString() << DELIMITER 
    <<startReading << DELIMITER
    <<endReading << DELIMITER
    <<fare << DELIMITER
    <<completed;

    return ss.str();
}

void Trip :: setDataFrom(Storable *s)
{
    Trip *t = static_cast<Trip*> (s);
    if(t)
    {
        this->vehicle= t->vehicle;
        this->user = t->user;
        this->startDate = t->startDate;
        this->endDate = t->endDate;
        this->startReading = t->startReading;
        this->endReading = t->endReading;
        this->fare = t->fare;
        this->completed = t->completed;
    }
}