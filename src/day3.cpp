#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int reverse_eval_char(const int i);

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

void shared_tokens(string first, string second, char *shared_chars)
{
  vector<int> first_map(26 * 2, 0);
  vector<int> second_map(26 * 2, 0);
  for (size_t i = 0; i < first.length(); i++)
  {
    int index = eval_char(first[i]) - 1;
    first_map[index]++;
  }

  for (size_t i = 0; i < second.length(); i++)
  {
    int index = eval_char(second[i]) - 1;
    second_map[index]++;
  }

  for (size_t i = 0; i < 26 * 2; i++)
  {
    if ((first_map[i] > 0) && (second_map[i] > 0))
    {
      shared_chars[i] = reverse_eval_char(i + 1);
    }
    else
    {
      shared_chars[i] = 0;
    }
  }
}

int reverse_eval_char(const int i)
{
  if (i > 26)
  {
    return i + 64 - 26;
  }
  else
  {
    return i + 96;
  }
}

int main()
{
  ifstream rfile;
  string first;
  string second;
  string third;
  rfile.open("../input/input3.txt");
  if (!rfile.is_open())
    return 1;

  char prio_char;
  int prio = 0;
  int grouped_prio = 0;
  int sum = 0;
  int sum_grouped = 0;
  char shared_chars[26 * 2];
  for (size_t i = 0; i < 26 * 2; i++)
  {
    shared_chars[i] = 0;
  }

  while (getline(rfile, first))
  {
    getline(rfile, second);
    getline(rfile, third);

    prio_char = shared_token(first.substr(0, first.length() / 2), first.substr(first.length() / 2, first.length() / 2));
    prio = eval_char(prio_char);
    sum += prio;
    prio_char = shared_token(second.substr(0, second.length() / 2), second.substr(second.length() / 2, second.length() / 2));
    prio = eval_char(prio_char);
    sum += prio;
    prio_char = shared_token(third.substr(0, third.length() / 2), third.substr(third.length() / 2, third.length() / 2));
    prio = eval_char(prio_char);
    sum += prio;
    
    shared_tokens(first, second, shared_chars);
    for (size_t i = 0; i < 26 * 2; i++)
    {
      if (shared_chars[i] != 0)
      {

        if (third.find(shared_chars[i]) != string::npos)
        {
          grouped_prio = eval_char(shared_chars[i]);
          sum_grouped += grouped_prio;
          break;
        }
      }
    }
    for (size_t i = 0; i < 26 * 2; i++)
    {
      shared_chars[i] = 0;
    }
  }
  rfile.close();
  cout << sum << endl;
  cout << sum_grouped << endl;
  return 0;
}