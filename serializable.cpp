//Included standard CPP headers
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
/*This(serializable) is a abstract class and any class derived from this class 
must implement to_string() function*/
class Serializable
{
    public:
    /*to_string() is a pure virtual function and serializable class don't know what 
    this method will do but it's the responsiblity of derived classes 
    to implement this in their own way*/
        virtual string toString() = 0;
};
