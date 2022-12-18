#include <iostream>
#include <fstream>
#include <string>

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

  int length_string = 0;
  int sequence_start = 0;
  int msg_start = 0;
  int first_index_match = 0;
  int first_index_match_msg = 0;

  getline(rfile, line);
  rfile.close();

  length_string = line.length();
  char *seq = &line[0];

  while (sequence_start - 4 < length_string)
  {
    first_index_match = find_matching_index(&seq[sequence_start], 4);
    if (first_index_match == -1)
      break;
    sequence_start += first_index_match + 1;
  }

  while(msg_start - 14 < length_string)
  {
    first_index_match_msg = find_matching_index(&seq[msg_start], 14);
    if (first_index_match_msg == -1)
      break;
    msg_start += first_index_match_msg + 1;
  }

  cout << sequence_start + 4 << endl;
  cout << msg_start + 14 << endl;
  return 0;
}

int find_matching_index(char *arr, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    for (size_t j = i + 1; j < length; j++)
    {
      if (arr[i] == arr[j])
        return i;
    }
  }
  return -1;
}