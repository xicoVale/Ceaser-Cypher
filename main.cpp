#include <iostream>
#include <stdlib.h>
#include "ceaser.h"

using namespace std;

// Help function
void help() {
  string help = "To chyper: write your text and press enter. Then input your shift value. This value must be positive.";
  cout << help << endl;
  help = "To decypher: write your cyphered text and press enter. Then input your shift value. This value must be negative.";
  cout << help << endl;
  return ;
}

int main () {
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

  return 0;
  exit (0);
}
