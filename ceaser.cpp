#include <string>
#include <cmath>
#include "ceaser.hpp"

using namespace std;

Caeser::Caeser(void) {}

// Convert all characters in input text to upper case
string Caeser::upper(string text){
  string result;
  for(int i = 0; i < text.length(); i++) {
    result += string(1, toupper(text[i]));
  }
  return result;
}

// Cypher input text with shift_value shifted alphabet
string Caeser::cypher(string text, int shift_value) {
  // if value is beyond alphabet size it must be converted to a >26 equivalent
  if (shift_value > alphabet.length()) {
    shift_value = shift_value - alphabet.length();
  }
  char space = ' ';
  string upped_text = upper(text);
  string result = "";

  for (int i = 0; i < upped_text.length(); i++) {
    // spaces and symbols are not cyphered and are skipped
    if (upped_text[i] == space || alphabet.find(upped_text[i]) == -1) {
      continue;
    }
    // fetch character to cypher
    string original = string(1, upped_text[i]);
    // index of cyphered character
    int index = alphabet.find(original) + shift_value;
    // if index is <26 it must be converted to <26 equivalent
    if (index > alphabet.length() - 1) {
      index = index - alphabet.length();
    }
    result += alphabet[index];
  }
  return result;
}

string Caeser::decypher(string text, int shift_value) {
  // if value is beyond alphabet size it must be converted to a >26 equivalent
  if (abs(shift_value) > alphabet.length()) {
    shift_value = shift_value + alphabet.length();
  }
  char space = ' ';
  string upped_text = upper(text);
  string result = "";

  for (int i = 0; i < upped_text.length(); i++) {
    // spaces are not cyphered and are skipped
    if (upped_text[i] == space || alphabet.find(upped_text[i]) == -1) {
      continue;
    }
    // fetch character to cypher
    string original = string(1, upped_text[i]);
    // index of cyphered character
    int index = alphabet.find(original) + shift_value;
    // if index is <26 it must be converted to <26 equivalent
    if (index < 0) {
      index = index + alphabet.length();
    }
    result += alphabet[index];
  }
  return result;
}

string Caeser::crack(string text) {
  string result;
  for (int i = 1; i < alphabet.length(); i++) {
    char attempt[(int) text.length()];
    sprintf(attempt, "%d\t%s\n", i, decypher(text, -i).c_str());
    string res(attempt);
    result+= res;
  }
  return result;
}
