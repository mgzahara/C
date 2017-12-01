////////////////////////////////////////////////////////////////////////////
/*Programmed by: Matt Zahara                                              */
/*Course: CSCI 201 F '16                                                  */
/*                                                                        */
/*To compile: Call the compiler with "g++", then use the "-o" argument    */
/*    to rename the executable that will be created. Then type all the    */
/*    filenames required to run this application; which happen to be      */
/*    "application.cpp", "queue.cpp", and "queue.h", then hit ENTER.      */
/*                                                                        */
/*To run: Type "./" then the name to chose to call the resultant          */
/*    executable from the previous step, then hit ENTER.                  */
/*                                                                        */
////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    char response; float data, dq;
    queueNode *front = NULL, *back = NULL;

    printf("Welcome to the best queue of your life!\n");

    do
    {       //menu
        printf("\n\tE - Enqueue data.\n");
        printf("\tD - Dequeue data.\n");
        printf("\tP - Print entire queue.\n");
        printf("\tI - Check if queue is empty.\n");
        printf("\tQ - Quit.\n");
        printf("Awaiting response: ");

        scanf("%c", &response);
	fflush(stdin);//get rid of ws for next response

	switch(response)//take input and take proper action
        {
            case 'e':
            case 'E': printf("\nEnter data to enqueue: ");
                      scanf("%f", &data); fflush(stdin);//store data to 'data' & flush ws
                      enqueue(data,  &front, &back);//send data to the back of the line
                      break;
            case 'd':
            case 'D': dq = dequeue(&front, &back);//remove first item from queue
		      if (dq != NULL)
		          printf("\nData removed: %f", dq);
                      break;
            case 'p':
            case 'P': printAll(front, back);//display each node's data
                      break;
            case 'i':
            case 'I': if(isEmpty(front))
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

    deleteAll(&front, &back);//deletes all existing nodes

    return (0);
}

