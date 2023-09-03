/*include custom headers*/
#include "vehicle.h"
#include "string_helper.h"

const char DELIMITER = ';';

Vehicle :: Vehicle(string registrationNumber,VehicleType type,int seats,
        string companyName,double pricePerKm, string PUCExpirationDate , long recordId)
        : Storable(recordId)
        {
            this->registrationNumber = registrationNumber;
            this->type = type;
            this->seats = seats;
            this->pricePerKm = pricePerKm;
            this->companyName = companyName;
            this->PUCExpirationDate = PUCExpirationDate;
        }
string Vehicle :: getRegistrationNumber() const
{
    return this->registrationNumber;
}

VehicleType Vehicle :: getVehicleType() const 
{
    return this->type;
}

int Vehicle :: getSeats() const
{
    return this->seats;
}

string Vehicle :: getCompanyName() const
{
    return this->companyName;
}

Date Vehicle :: getPUCExpirationDate() const
{
    return this->PUCExpirationDate;
}

double Vehicle :: getPricePerKm() const
{
    return this->pricePerKm;
}

void Vehicle :: setPricePerKm(double newPrice)
{
    this->pricePerKm = newPrice;
}

string Vehicle :: getVehicleTypeName() const
{
    switch(this->type)
    {
        case VehicleType ::bike:
            return "Bike";
        case VehicleType ::car:
            return "Car";
        case VehicleType ::towera:
            return "Towera";
        default :
            return "";
    }
}

string Vehicle :: toString() const
{
    stringstream ss;
    ss << recordId << DELIMITER 
    << registrationNumber << DELIMITER
    <<type << DELIMITER
    << seats << DELIMITER
    <<companyName << DELIMITER
    <<to_string(pricePerKm) << DELIMITER
    << PUCExpirationDate;

    return ss.str();
}

void Vehicle :: display() const
{
    cout << "Vehicle Details : " << endl;
    cout << "Registration Number : " << this->registrationNumber << endl;
    cout << "Vehicle Type : " << this->getVehicleTypeName() << endl;
    cout << "No of Seats : " << this->seats << endl;
    cout << "Company Name : " << this->companyName << endl;
    cout << "Price Per Km : " << this->pricePerKm << "Rs/Km" << endl;
    cout << "PUC Expiration Date : " << this->PUCExpirationDate << endl;

}

void Vehicle :: setDataFrom(Storable *s)
{
    Vehicle *v = dynamic_cast<Vehicle*> (s);
    if(v)
    {
        this->registrationNumber = v->registrationNumber;
        this->type= v->type;
        this->seats = v->seats;
        this->companyName = v->companyName;
        this->pricePerKm = v->pricePerKm;
        this->PUCExpirationDate = v->PUCExpirationDate;
    } 
}