#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

int find_matching_index(char *, int);

int main()
{
  ifstream rfile;
  string line;
  rfile.open("../input/input6.txt");
  if (!rfile.is_open())
  {
    cout << "Failed to open" << endl;
    return 1;
  }

  while (getline(rfile, line))
  {
    
  }
  rfile.close();

  return 0;
}
