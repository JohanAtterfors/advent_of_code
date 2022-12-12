#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char shared_token(string first, string second)
{
  for (size_t i = 0; i < first.length(); i++)
  {
    for (size_t j = 0; j < second.length(); j++)
    {
      if (first[i] == second[j])
        return first[i];
    }
  }
  return '0';
}

int eval_char(const char c)
{
  if (c <= 'Z')
  {
    return c - 65 + 27;
  }
  else
  {
    return c - 96;
  }
}

void trimTo(string & s, size_t pos = 0, size_t len = string::npos)
{ 
    s.erase(pos + len);
    s.erase(pos, len);
}

int main()
{
  ifstream rfile;
  string first;
  string second;
  string third;
  rfile.open("../input/input3_test.txt");
  if (!rfile.is_open())
    return 1;

  char prio_char;
  int prio = 0;
  int sum = 0;
  while (getline(rfile, first))
  {
    //prio_char = shared_token(first.substr(0, first.length()/2), first.substr(first.length()/2, first.length()/2));
    getline(rfile, second);
    getline(rfile, third);

    char common_char = shared_token(first, second);
    if(third.find(common_char) != string::npos){
      trimTo(first, 0, first.find(common_char));
      trimTo(second, 0, second.find(common_char));
    }

    prio = eval_char(prio_char);
    sum += prio;
  }
  rfile.close();
  cout << sum << endl;
  return 0;
}