#include <limits>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void initializeSingleSource();
void relax(int, int);
void queueInit();
void sortQ(int);
void postDijkSort();
void troubleshoot();
int  findIndex(int);

int adjMatrix[20][20], V = 0, parents[20], distances[20], queueNodes[20];


int main(int argc, char *argv[])
{
  ifstream input_file;


  if (argc == 2)
    {
      //cout << "file provided: " << argv[1] << endl;

      input_file.open(argv[1]);
      if (input_file.fail())
        {
	  cout << "Unable to open input file " << argv[1] << endl;
	  exit(-1);
        }
    }
  else
    {
      cout << "Incorrect number of parameters\nUsage: " << argv[0] << " <input filename>" << endl;
      exit(-1);
    }

  //  int hold = 0;
  //  cout << "Please provide input:" << endl;

  input_file >> V;
  //read in adj matrix
  for(int i = 0; i < V; i++)
    {
      for(int j = 0; j < V; j++)
        {
          input_file >> adjMatrix[i][j];
        }
    }

  initializeSingleSource();
  queueInit();

  /*//debugging info
  cout << "after initializeSingleSource()" << endl;
  for(int i = 0; i < V; i++)
    {
      cout << "distances[" << i << "] -> " << distances[i] << "\t";
      cout << "parents[" << i << "] -> " << parents[i] << endl;;
    }
 
  cout << "\nafter queueInit() " << endl;
  for(int i = 0; i < V; i++)
    {
      cout << "queueNodes[" << i << "] -> " << queueNodes[i] << "\n";
    }
  */

   
  for(int i = 0; i < V; i++)
    {//dijkstras algo
      sortQ(i);
 
      for(int j = 0; j < V; j++)
	{//try to reduce the travel distance to j through the next cheapest node at queueNodes[i]
	  relax(queueNodes[i], j);
	}
   }
      
  postDijkSort();

  //print out parents[] and distances[] - the answer to the assignment

  cout << "distances \t parents" << endl;
  for(int i = 0; i < V; i++)
    {
      cout << distances[i] << "\t\t" << parents[i] << endl;
    }

  return 0;
}

void initializeSingleSource()
{
  for(int i = 0; i < V; i++)
    {
      distances[i] = 214748364;
      parents[i] = -1;
    }
  distances[0] = 0;
  return;
}

void relax(int u1, int v1)
{//u and v are vertecies, or indecies, or both... both is good
  //w is the weight from u to v, not passed, can be found in adjMatrix[][]

  //  cout << "\n\tstart of relax()" << endl;
  //  cout << "from " << u1 << "\tto " << v1 << endl;
 
  int u = findIndex(u1);
  int v = findIndex(v1);
  //  cout << "u == " << u << "\tv == " << v << endl;
  //  troubleshoot();

  //  cout << "relax() if statement:" << endl;
  //  cout << "\tif(" << distances[v] << " > (" << distances[u] << " + " << adjMatrix[u1][v1] << ") && " << adjMatrix[u1][v1] << " > 0)" << endl;

  if(distances[v] > (distances[u] + adjMatrix[u1][v1]) && adjMatrix[u1][v1] > 0)
    {//getting to v is cheaper through u && u has an edge to v
      //      cout << "\tgot into if-statement" << endl;
      
      distances[v] = distances[u] + adjMatrix[u1][v1];
      
      parents[v] = u1;
    }
  //  cout << "end of relax()" << endl;
  //  troubleshoot();

  return;
}

void queueInit()
{//Q = G.V
  for(int i = 0; i < V; i++)
    {
      queueNodes[i] = i;
    }

  return;
}

void sortQ(int start)
{//sort all three arrays based on the values of the distances array
  for(int i = start; i < V - 1; i++)
    {
      int lowValue = distances[i];
      int lowIndex = i;
      for(int j = i + 1; j < V; j++)
        {
          if(lowValue > distances[j])
            {
              lowValue = distances[j];
              lowIndex = j;
            }
        }//end inner loop

      //swap weights
      int temp = distances[lowIndex];
      distances[lowIndex] = distances[i];
      distances[i] = temp;

      //swap parents to match swapped distances
      temp = parents[lowIndex];
      parents[lowIndex] = parents[i];
      parents[i] = temp;

      //swap queueNodes to match swapped distances and parents
      temp = queueNodes[lowIndex];
      queueNodes[lowIndex] = queueNodes[i];
      queueNodes[i] = temp;
    }//end of outer loop

  //  cout << "\nend of sortQ with start == " << start << endl;
  //  troubleshoot();

  return;
}

void postDijkSort()
{//sort all three arrays based on the values in queueNodes

  for(int i = 0; i < V; i++)
    {
      int lowValue = queueNodes[i];
      int lowIndex = i;

      for(int j = i; j < V; j++)
	{
	  if(lowValue > queueNodes[j])
	    {
	      lowValue = queueNodes[j];
	      lowIndex = j;
	    }
	}//end of inner loop

      //swap weights
      int temp = distances[lowIndex];
      distances[lowIndex] = distances[i];
      distances[i] = temp;

      //swap parents to match swapped distances
      temp = parents[lowIndex];
      parents[lowIndex] = parents[i];
      parents[i] = temp;

      //swap queueNodes to match swapped distances and weights
      temp = queueNodes[lowIndex];
      queueNodes[lowIndex] = queueNodes[i];
      queueNodes[i] = temp;



    }//end of outer loop

  //  cout << "end of postDijkSort()" << endl;
  //  troubleshoot();

  return;
}

void troubleshoot()
{
  cout << "\nqueueNodes \t distances \t parents\n--------------------------------------" << endl;

  for (int i = 0; i < V; i++)
    {
      cout << queueNodes[i] << "\t\t" << distances[i] << "\t\t" << parents[i] << endl;
    }

  return;
}

int findIndex(int value)
{//parameter 'value' is the value whose index I want from queueNodes[]
  
  int curr = -1, found = -1;

  while(found != value)
    {
      curr++;
      found = queueNodes[curr];
    }
  return curr;
}
