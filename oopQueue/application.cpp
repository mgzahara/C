////////////////////////////////////////////////////////////////////////////
/*Program 2: Class Implimented Queue                                      */
/*Programmed by: Matt Zahara                                              */
/*Course: CSCI 201 F '16                                                  */
/*                                                                        */
/*To compile: Call the compiler with "g++", then use the "-o" argument    */
/*    to rename the executable that will be created. Then type all the    */
/*    filenames required to run this application; which happen to be      */
/*    "application.cpp", "queue.cpp", "appData.cpp", "appData.h", and     */
/*    "queue.h", then hit ENTER.                                          */
/*                                                                        */
/*To run: Type "./" then the name to chose to call the resultant          */
/*    executable from the previous step, then hit ENTER.                  */
/*                                                                        */
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "appData.h"

using namespace std;

int main()
{
    char response; AppData input, dq; Queue q;

    printf("\nWelcome to the best queue of your life!");

    do
    {       //menu
        printf("\n\tE - Enqueue data.");
        printf("\n\tD - Dequeue data.");
        printf("\n\tP - Print entire queue.");
        printf("\n\tI - Check if queue is empty.");
        printf("\n\tQ - Quit.\n");
        printf("Awaiting response: ");

	cin >> response;
	fflush(stdin);//get rid of ws for next response

	switch(response)//take input and take proper action
        {
            case 'e':
            case 'E': cout << "\nEnter data to enqueue: ";
                      cin >> input; fflush(stdin);  //store data to 'data' & flush ws
                      q.enqueue(input);  //send data to the back of the line
                      break;
            case 'd':
            case 'D': dq = q.dequeue();  //remove first item from queue

		      cout << "\nData removed: " << dq << endl;
                      break;
            case 'p':
            case 'P': q.printAll();  //display each node's data
                      break;
            case 'i':
            case 'I': if(q.isEmpty()) 
                          printf("\nQueue is empty.");
                      else
                          printf("\nQueue is not empty.");
		      break;
            case 'q':
            case 'Q': break;
                                //if user enters non-menu character
            default: printf("\nERROR: invalid response %c", response);
        }
    }while(response != 'Q' && response != 'q');  //loop until user inputs Q/q

    return (0);
}

