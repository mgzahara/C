#include <iostream>
//prototype
int GCD(int large, int small, int &deep);

using namespace std;

int main()
{
    int num1, num2, depth, answer, temp;

    cout << "To terminate, enter a 0 for either number.";

    do 
    {
	depth = 0;//zero out depth counter between runs

	cout << "\n\nEnter first number: ";
	cin >> num1;

	cout << "Enter second number: ";
	cin >> num2;

	if (num1 != 0 && num2 != 0)
	{
	    cout << "The GCD of " << num1 << " and " << num2 << " is " << GCD(num1, num2, depth);
	    cout << "\nThe recursive calculation required a depth of " << depth;
	}

    }while ( (num1 != 0) && (num2 != 0) );

    return 0;
}

int GCD(int large, int small, int &deep)
//recursively finds the greatest common divisor 
//among the two integers passed
{
    int temp;

    if (large < small)//make sure 'large' is the bigger of the two
    {
	temp = large;
	large = small;
	small = temp;
    }

    if (large != small)
    {
	large -= small;
	deep++;
	return GCD(large, small, deep);
    }
    else if(large == small)
	return large;

    return 0;
}
