#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool is_overlapping(string a, string b);
bool is_some_overlapping(string a, string b);

int main()
{
  ifstream rfile;
  string line;
  rfile.open("../input/input4.txt");
  if (!rfile.is_open())
  {
    cout << "Failed to open" << endl;
    return 1;
  }

  int nr_overlapping_seqs = 0;
  int nr_some_overlapping_seqs = 0;

  while (getline(rfile, line))
  {
    int pos_comma = line.find(",");
    if (is_overlapping(line.substr(0, pos_comma), line.substr(pos_comma + 1)))
    {
      nr_overlapping_seqs++;
    }
    if (is_some_overlapping(line.substr(0, pos_comma), line.substr(pos_comma + 1)))
    {
      nr_some_overlapping_seqs++;
    }
  }
  rfile.close();
  cout << nr_overlapping_seqs << endl;
  cout << nr_some_overlapping_seqs << endl;
  return 0;
}

bool is_overlapping(string a, string b)
{
  int index_sep_a = a.find("-");
  int index_sep_b = b.find("-");
  int a_lower = stoi(a.substr(0, index_sep_a));
  int a_upper = stoi(a.substr(index_sep_a + 1));
  int b_lower = stoi(b.substr(0, index_sep_b));
  int b_upper = stoi(b.substr(index_sep_b + 1));

  if (a_lower <= b_lower && a_upper >= b_upper)
    return true;
  if (b_lower <= a_lower && b_upper >= a_upper)
    return true;
  return false;
}

bool is_some_overlapping(string a, string b)
{
  int index_sep_a = a.find("-");
  int index_sep_b = b.find("-");
  int a_lower = stoi(a.substr(0, index_sep_a));
  int a_upper = stoi(a.substr(index_sep_a + 1));
  int b_lower = stoi(b.substr(0, index_sep_b));
  int b_upper = stoi(b.substr(index_sep_b + 1));

  if (a_lower <= b_upper && b_lower <= a_upper)
    return true;
  if (a_upper >= b_lower && a_lower <= b_lower)
    return true;
  if(is_overlapping(a, b))
    return true;
  return false;
}