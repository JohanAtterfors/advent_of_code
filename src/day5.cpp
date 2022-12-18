#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

void reverse_forward_lists(vector< forward_list<char> > &vll);
void parse_sketch(string, vector< forward_list<char> > &);
void parse_movement(string, vector< forward_list<char> > &);

int nr_lists = 9;

int main()
{
  ifstream rfile;
  string line;
  rfile.open("../input/input5.txt");
  if (!rfile.is_open())
  {
    cout << "Failed to open" << endl;
    return 1;
  }
  vector< forward_list<char> > vector_linked_lists;
  
  forward_list<char> c0;
  forward_list<char> c1;
  forward_list<char> c2;
  forward_list<char> c3;
  forward_list<char> c4;
  forward_list<char> c5;
  forward_list<char> c6;
  forward_list<char> c7;
  forward_list<char> c8;

  vector_linked_lists.push_back(c0);
  vector_linked_lists.push_back(c1);
  vector_linked_lists.push_back(c2);
  vector_linked_lists.push_back(c3);
  vector_linked_lists.push_back(c4);
  vector_linked_lists.push_back(c5);
  vector_linked_lists.push_back(c6);
  vector_linked_lists.push_back(c7);
  vector_linked_lists.push_back(c8);

  void (*parser)(string, vector< forward_list<char> > &);
  parser = &parse_sketch;

  while (getline(rfile, line))
  {
    if (line[1] == '1')
    {
      parser = &parse_movement;
      reverse_forward_lists(vector_linked_lists);
      getline(rfile, line);
      continue;
    }

    parser(line, vector_linked_lists);
  }
  rfile.close();
  
  for (size_t i = 0; i < nr_lists; i++)
  {
    if(vector_linked_lists[i].empty())
      continue;
    cout << vector_linked_lists[i].front();
  }
  cout << endl;
  return 0;
}

void reverse_forward_lists(vector < forward_list<char> > &vll){
  for (size_t i = 0; i < nr_lists; i++)
  {
    vll[i].reverse();
  }
}

void parse_sketch(string line, vector< forward_list<char> > &vll)
{
  for (size_t i = 1; i < line.size(); i += 4)
  {
    if (line[i] == 91 || line[i] == 32)
      continue;
    vll[int(((double)i/4.0) - 0.25)].push_front(line[i]);
  }
}

void parse_movement(string line, vector< forward_list<char> > &vll)
{
  int index_second_space = line.substr(5).find(" ") + 6;
  int index_third_space = line.substr(index_second_space + 1).find(" ") + index_second_space + 1;
  int index_fourth_space = line.substr(index_third_space + 1).find(" ") + index_third_space + 1;
  int index_fifth_space = line.substr(index_fourth_space + 1).find(" ") + index_fourth_space + 1;
  int nr_boxes_move = stoi(line.substr(5, index_second_space));
  int from_stack = stoi(line.substr(index_third_space, index_fourth_space)) - 1;
  int to_stack = stoi(line.substr(index_fifth_space)) - 1;
  for (size_t i = 0; i < nr_boxes_move; i++)
  {
    vll[to_stack].push_front(vll[from_stack].front());
    vll[from_stack].pop_front();
  }
}