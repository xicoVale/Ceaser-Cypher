#include <iostream>
#include <stdlib.h>
#include "ceaser.hpp"

using namespace std;

// Help function
void help() {
  string help = "Usage: ceaser [OPTION] [TEXT] [KEY]";
  cout << help << endl;
  help = "\t-h --help\tdisplay this help text";
  cout << help << endl;
  return ;
}

// Interactive mode function
void interactive() {
  while (true) {
    string text;
    string result;
    string in_value;
    int value;
    Caeser caeser;

    cout << ">>>";
    getline(cin, text, '\n');
    if (text == "exit") {
      exit(0);
    }
    if (text == "help") {
      help();
      continue;
    }
    if (text == "break") {
      cout << ">>>";
      getline(cin, text, '\n');
      result = caeser.crack(text);
      cout << result;
    }
    else {
      cout << ">>>";
      getline(cin, in_value, '\n');
      value = atoi(in_value.c_str());
      if (value > 0) {
        result = caeser.cypher(text, value);
      }
      else if (value < 0) {
        result = caeser.decypher(text, value);
      }
      cout << result << endl;
    }
  }
  return ;
}

int main (int argc, char *argv[]) {
  // no arguments, interactive mode
  if (argc == 1) {
    interactive();
    exit(0);
  }
  // one argument, help or present all possible decypherings
  else if (argc == 2) {
    string arg(argv[1]);
    if (arg == "--help" || arg == "-h") {
      help();
      exit(0);
    }
    else {
      Caeser ceaser;
      string result = ceaser.crack(arg);
      cout << result;
      exit(0);
    }
  }
  // two arguments, cypher or decypher given text with given key
  else if (argc == 3) {
    string text(argv[1]);
    int value = atoi(argv[2]);
    Caeser caeser;

    if (value < 0) {
      string result = caeser.decypher(text, value);
      cout << result << endl;
      exit (0);
    }
    else if (value > 0) {
      string result = caeser.cypher(text, value);
      cout << result << endl;
      exit (0);
    }
  }
  else if(argc > 3) {
    cerr << "Too many arguments." << endl;
    exit (1);
  }
  return 0;
  exit (0);
}
