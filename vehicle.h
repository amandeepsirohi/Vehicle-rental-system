#ifndef vehicle_h
#define vehicle_h

/*include custom headers */
#include "date.h"
#include "storable.cpp"

/*include standard cpp headers*/
#include <string>

using namespace std;

/*Support for different kind of vehicles for different purposes*/
typedef enum {bike = 1 , car = 2 , towera = 3} VehicleType;

/*vehicle class helps managing b=vehicle related data*/
class Vehicle : public Storable
{
    private:
        /*Registration Number given by RTO*/
        string registrationNumber;

        /*Type of vehicle given by 'VehicleType' enum*/
        VehicleType type;

        /*No of seats in the vehicle*/
        int seats;

        /*Name of vehicle Manufacturer*/
        string companyName;

        /*each vehicle has different per/km price.
        this will be required to calculate fare when trip ends*/
        double pricePerKm;

        /*Date when PUC will Expire*/
        string PUCExpirationDate;

    public:
        /*constructor of vehicle class*/
        Vehicle(string registrationNumber,VehicleType type,int seats,
        string companyName,double pricePerKm, string PUCExpirationDate ,
        long recordId = 0);

        /*getter methods with const attributes i.e. this method is 
            not changing any data of object.
            If this method is not marked as constant , then it can't be
            called from const object of class*/
        /*The following snippet will give error if 'getRegistrationNumber'
        is not marked with const keyword
        const Vehicle *obj = new Vehicle(.....)
        auto registrationNo = object->getRegistrationNumber()*/
        string getRegistrationNumber() const;
        VehicleType getVehicleType() const;
        string getVehicleTypeName() const;
        int getSeats() const;
        string getCompanyName() const;
        double getPricePerKm() const;
        Date getPUCExpirationDate() const;

        /*Function to set new Price of Vehicle*/
        void setPricePerKm(double newPrice);

        /*display record on screen*/
        void display() const;

        /*overriden virtual method*/
        string to_String() const;

        void setDataFrom(Storable *s);

};
#endif