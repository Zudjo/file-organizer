#include "./headers/FileTalker.h"
#include <map>
#include <filesystem>
#include <iostream>
using namespace std;

namespace fs = std::filesystem;

map<int, string> FileTalker::menuFunctions = {
  { 10, "extension" },
  { 11, "creationDate" },
  { 12, "editDay" },
  { 21, "creationDate" },
  { 31, "identicalCopy" }
};

int FileTalker::runFunction(int menuNumber, string filter, string pathDirectory) {
  for (const fs::directory_entry& dir_entry :
      fs::recursive_directory_iterator(pathDirectory)) {

    std::cout << dir_entry;
  }
  return 0;
}

bool FileTalker::checkMenuNumber(int menuNumber) {
  if(FileTalker::menuFunctions.count(menuNumber)) {
    return true;
  }
  return false;
}

int FileTalker::folderer(string file, string filter) {

  return 0;
}

int FileTalker::renamer(string file, string filter) {
  return 0;
}

int FileTalker::deleter(string pathDirectory, string filter) {
  return 0;
}
