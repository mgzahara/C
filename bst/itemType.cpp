#include <iostream>
#include <string.h>
#include "itemType.h"

using namespace std;

ItemType::ItemType()
//constructor
{
    fname[0] = '\0';
    lname[0] = '\0';
    id = badID;
    salary = 0;
}

ItemType::~ItemType()
//destructor
{
    id = badID;
    salary = 0;
    lname[0] = '\0';
    fname[0] = '\0';
}

ItemType::ItemType(const ItemType & item)
//copy constructor
{
    id = item.id;
    salary = item.salary;
    strncpy(lname, item.lname, NAMESIZE+1);
    strncpy(fname, item.fname, NAMESIZE+1);
}

void ItemType::getLName(char destName[])
//last name getter
{
    strncpy(destName, lname, NAMESIZE+1);

    return;
}

void ItemType::setLName(char theName[])
//last name setter
{
    strncpy(lname, theName, NAMESIZE+1);

    return;
}

void ItemType::getFName(char destName[])
//first name getter
{
    strncpy(destName, fname, NAMESIZE+1);

    return;
}

void ItemType::setFName(char theName[])
//first name setter
{
    strncpy(fname, theName, NAMESIZE+1);

    return;
}

double ItemType::getSalary()
//salary getter
{
    return(salary);
}

void ItemType::setSalary(double newValue)
//salary setter
{
    if (newValue >= 0)
        salary = newValue;
    else
        cout << "ERROR: Bad salary value " << newValue << " in setSalary()\n";

    return;
}

long ItemType::getID()
//ID getter
{
    return(id);
}

void ItemType::setID(long newID)
//ID setter
{
    if (newID > 0)
    {
        id = newID;
    }

    else
    {
        //Should throw an error, but we don't know how yet.
        cout << "ERROR: ID numbers are not allowed to be negative\n";
    }
}

const ItemType ItemType::operator=(const ItemType &rhs)
//assigment operator overload
{
    id = rhs.id;
    salary = rhs.salary;
    strncpy(lname, rhs.lname, NAMESIZE+1);
    strncpy(fname, rhs.fname, NAMESIZE+1);

    return *this;
}

bool operator<(const ItemType &lhs, const ItemType &rhs)
//less than operator overload
{
    int result;
    result = strncmp(lhs.lname, rhs.lname, NAMESIZE);

    if (result < 0)
        return(true);

    else if (result > 0)
        return(false);

    else
    {
        result = strncmp(lhs.fname, rhs.fname, NAMESIZE);

        if (result < 0)
            return(true);

        else if (result > 0)
            return(false);

        else
            return(lhs.id < rhs.id);
    }
}

bool operator>(const ItemType &lhs, const ItemType &rhs)
//greater than operator overload
{
    return(rhs < lhs);
}

bool operator<=(const ItemType &lhs, const ItemType &rhs)
//less than or equal to operator overload
{
    return( !(rhs < lhs) );
}

bool operator>=(const ItemType &lhs, const ItemType &rhs)
//greater than or equal to operator overload
{
    return( !(lhs < rhs) );
}

bool operator==(const ItemType &lhs, const ItemType &rhs)
//equal to operator overload
{
    return( !(lhs < rhs) && !(rhs < lhs) );
}

bool operator!=(const ItemType &lhs, const ItemType &rhs)
//not equal to operator overload
{
    return((lhs < rhs) || (rhs < lhs));
}

ostream & operator<< (ostream & output, const ItemType & item)
//stream insertion operator overload
{
    output << item.lname << ", " << item.fname << " ID: " << item.id;
    output << " Salary: $" << fixed << setprecision(2) << item.salary << endl;

    return output;
}

istream & operator>> (istream & input, ItemType & item)
//stream extraction operator overload
{
    input >> item.lname;

    input >> item.fname;

    input >> item.id;

    input >> item.salary;

    return input;
}

