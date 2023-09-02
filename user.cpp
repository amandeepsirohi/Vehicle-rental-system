/*Include custom headers*/
#include "user.h"
#include "string_helper.h"

/*include custom cpp headers*/
#include <iostream>

const char DELIMITER = ';';

User :: User(string name , string contact , string email , long recordId):
Storable (recordId){
    this->name =name;
    this->contact = contact;
    this->email = email;
}

string User :: getName() const {return this->name;}

string User :: getContact() const {return this->contact;}

string User :: getEmail() const {return this->email;}

void User :: setName(string newName) {this->name = newName;}

void User :: setContact(string newContact) {this->contact = newContact;}

void User :: setEmail(string newEmail) {this->email = newEmail;}

void User :: display() const {
    cout << "User Details : " << endl;
    cout << "Name : " << this->name << endl;
    cout << "Contact : " << this->contact << endl;
    cout << "Email : " << this->contact << endl;
}

string User :: to_String() const {
    stringstream ss;
    ss << recordId << DELIMITER 
        << name << DELIMITER 
        << contact << DELIMITER
        <<email;
    return ss.str();
}

void User :: setDataFrom(Storable *s)
{
    User *user = dynamic_cast<User*> (s);
    if(user)
    {
        this->contact = user->contact;
        this->name = user->name;
        this->email = user->email;
    }
} 
 