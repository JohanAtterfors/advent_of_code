#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define O_ROCK 'A'
#define O_PAPER 'B'
#define O_SCISSOR 'C'
#define P_ROCK 'X'
#define P_PAPER 'Y'
#define P_SCISSOR 'Z'
#define LOSE 0
#define DRAW 3
#define WIN 6

using namespace std;

int outcome(const char *line)
{
  switch (line[0])
  {
  case O_ROCK:
    if (line[2] == P_ROCK)
      return 3;
    if (line[2] == P_PAPER)
      return 6;
    if (line[2] == P_SCISSOR)
      return 0;
    break;

  case O_PAPER:
    if (line[2] == P_ROCK)
      return 0;
    if (line[2] == P_PAPER)
      return 3;
    if (line[2] == P_SCISSOR)
      return 6;
    break;

  case O_SCISSOR:
    if (line[2] == P_ROCK)
      return 6;
    if (line[2] == P_PAPER)
      return 0;
    if (line[2] == P_SCISSOR)
      return 3;
    break;
  }
  return 0;
}

int shape(const char *line)
{
  if (line[2] == P_ROCK)
    return 1;
  if (line[2] == P_PAPER)
    return 2;
  if (line[2] == P_SCISSOR)
    return 3;
  return 0;
}

char get_token(char * line){
  int required_outcome = 0;
  switch (line[2]){
    case 'X': 
      required_outcome = 0;
    break;
    case 'Y': 
      required_outcome = 3;
    break;
    case 'Z': 
      required_outcome = 6;
    break;
  }
  line[2] = P_ROCK;
  if(outcome(line) == required_outcome) return P_ROCK;
  line[2] = P_PAPER;
  if(outcome(line) == required_outcome) return P_PAPER;
  line[2] = P_SCISSOR;
  if(outcome(line) == required_outcome) return P_SCISSOR;
  return P_PAPER;
}

int main()
{
  ifstream rfile;
  string line;
  rfile.open("../input/input2.txt");
  if (!rfile.is_open())
    return 1;

  int total_score = 0;
  int temp = 0;
  char tokens[3];
  char selected_token;
  while (getline(rfile, line))
  {
    strcpy(tokens, line.c_str());
    selected_token = get_token(tokens);
    temp = outcome(tokens) + shape(tokens);
    total_score += outcome(tokens) + shape(tokens);
  }
  rfile.close();
  cout << "Score: " << total_score << endl;
  return 0;
}