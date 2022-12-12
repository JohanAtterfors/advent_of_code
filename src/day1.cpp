#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void add_top_three(vector<int> &vec, int val)
{
  int index_of_minimum = 0;
  int temp_top_three = 0;
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (vec[i] > val)
      continue;
    temp_top_three = vec[i];
    vec[i] = val;
    val = temp_top_three;
  }
}

int is_top_three(vector<int> &vec, int val)
{
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (val > vec[i])
      return true;
  }
  return false;
}

int main()
{
  ifstream rfile;
  rfile.open("../input/input1.txt");
  string line;
  if (!rfile.is_open())
    return 1;

  int current_cal = 0;
  int sum_cal = 0;
  int max_cal = 0;
  vector<int> top_three(3, 0);

  while (getline(rfile, line))
  {
    if (line.size())
    {
      current_cal = stoi(line);
      sum_cal = sum_cal + current_cal;
      continue;
    }
    if (is_top_three(top_three, sum_cal))
    {
      max_cal = sum_cal;
      add_top_three(top_three, sum_cal);
    }
    if (sum_cal > max_cal)
      max_cal = sum_cal;
    sum_cal = 0;
    current_cal = 0;
  }
  cout << "Top three: " << top_three[0] + top_three[1] + top_three[2] << endl;
  cout << "Max cal: " << max_cal << endl;
  rfile.close();
  return 0;
}