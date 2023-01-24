#include <iostream>
#include <string>
#include "./headers/UserTalker.h"
#include "./headers/FileTalker.h"
using namespace std;

// PROPERTIES
string UserTalker::menuFunctions =
  "\n"
  "  Organizzati in cartelle, per\n"
  "    10 -> estensione\n"
  "    11 -> data di creazione\n"
  "    12 -> data di modifica\n"
  "\n"
  "  Rinominati, per\n"
  "    21 -> data di creazione\n"
  "\n"
  "  Eliminati, per\n"
  "    31 -> copie esatte\n"
  "    32 -> cartella vuota\n";

// METHODS
int UserTalker::getMenuNumber() {
  int menuNumber;

  cout << UserTalker::menuFunctions;

  do {
    cout << "\nChoose: ";
    cin >> menuNumber;

  } while(!FileTalker::checkMenuNumber(menuNumber));

  return menuNumber;
}

string UserTalker::getPathDirectory() {
  string pathDirectory;

  cout << "Insert the path of the directory: ";
  cin >> pathDirectory;

  return pathDirectory;
}

void UserTalker::print(string text) {
  cout << text;
}

void UserTalker::print(int number) {
  cout << number;
}
