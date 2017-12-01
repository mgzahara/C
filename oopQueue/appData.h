#include <iostream>
using namespace std;

#ifndef APPDATA
#define APPDATA

class AppData
{
    public:
	AppData();                      // Constructor
	~AppData();                     // Destructor
	AppData(const AppData & origElement);		// Copy constructor
	const AppData & operator=(const AppData &rhs);  // Assignment op overload
	void setData(double data);	// Mutator
	double getData();		// Accessor

	// Stream operator overloads...
	friend ostream& operator<< (ostream& out, const AppData &it);
	friend istream& operator>> (istream& in, AppData &it);

    private:
	// Our data
	double data;
};

#endif

