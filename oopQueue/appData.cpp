#include <iostream>
#include <fstream>
using namespace std;

#include "appData.h"

AppData::AppData()
	: data(0)
{
}

AppData::~AppData()
{
}

AppData::AppData(const AppData & origElement)
//copy constructor, assigns data on right of '=' to what is on the left
{
	data = origElement.data;
}

const AppData & AppData::operator=(const AppData &rhs)
//assignment op overload, assigns data on right of '=' to what is on the left
{
	if (this != &rhs)
	{
		data = rhs.data;
	}

	return *this;
}

void AppData::setData(double data)
//mutator
{
        data = data;
}

double AppData::getData()
//accessor
{
	return(data);
}

ostream& operator<<(ostream& out, const AppData &it)
//stream insertion overload
{
    out << it.data;

    return out;
}

istream& operator>>(istream& in, AppData &it)
//stream extraction overload
{
    double dummy;

    in >> dummy;
    it.data = dummy;

    return in;
}

