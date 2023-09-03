#ifndef users_h
#define users_h

/*include custom headers*/
#include "storable.cpp"

/*include standard headers*/
#include <string>

using namespace std;

/*user class which helps maintaining in user-related data*/
class User : public Storable
{
    private:
        //Name of user
        string name;

        //contact of user
        string contact;

        //user Email-Id

        string email;
    public:
        /*constructor for class*/
        User(string name , string contact , string email , long recordId = 0);
            /*getter methods with const attributes i.e. this method is 
            not changing any data of object.
            If this method is not marked as constant , then it can't be
            called from const object of class*/
            /*the following methods will give an error if not marked const*/
            string getName() const;
            string getEmail() const;
            string getContact() const;

            //set name of user
            void setName(string newName);

            //set contact of user
            void setContact(string newContact);

            //set email of user
            void setEmail(string newEmail);

            //display record on screen
            void display() const;

            //overriden virtual method
            string toString() const;

            void setDataFrom(Storable *s);
};
#endif