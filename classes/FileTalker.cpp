#include "./headers/FileTalker.h"
#include <map>
#include <filesystem>
#include <iostream>
using namespace std;

namespace fs = std::filesystem;
typedef int (*pFunction)(string, string);

// PROPERTIES
map<int, string> FileTalker::menuFunctions = {
  { 10, "extension" },
  { 11, "creationDate" },
  { 12, "editDay" },
  { 21, "creationDate" },
  { 31, "identicalCopy" },
  { 32, "emptyFolder" }
};

// METHODS
string FileTalker::outputDirectory;

int FileTalker::runFunction(int menuNumber, string pathDirectory) {
  pFunction function = FileTalker::getFunction(menuNumber);
  string path;
  FileTalker::outputDirectory = pathDirectory + "\\..\\FileOrganizer";

  fs::create_directory(FileTalker::outputDirectory);

  for (const fs::directory_entry& dir_entry :
  fs::recursive_directory_iterator(pathDirectory)) {

    path = dir_entry.path().string();

    function(path, FileTalker::menuFunctions[menuNumber]);
  }
  return 0;
}

pFunction FileTalker::getFunction(int menuNumber) {
  if (menuNumber < 19) {
    return FileTalker::folderer;
  } else if (menuNumber < 29) {
    return FileTalker::renamer;
  } else if (menuNumber < 39) {
    return FileTalker::deleter;
  }
}

bool FileTalker::checkMenuNumber(int menuNumber) {
  if(FileTalker::menuFunctions.count(menuNumber)) {
    return true;
  }
  return false;
}

int FileTalker::folderer(string path, string filter) {
  if (filter == "extension" && !fs::is_directory(path)) {

    string pathName = path.substr(path.find_last_of("/\\") + 1);
    string extension = path.substr(path.find_last_of(".") + 1);
    string extensionDirectory = FileTalker::outputDirectory + "\\" + extension;

    try {
      if (!fs::exists(extensionDirectory)) {
        fs::create_directory(extensionDirectory);
      }
      fs::rename(path, extensionDirectory + "\\" + pathName);
    } catch (...) {}
  }
  return 0;
}

int FileTalker::renamer(string path, string filter) {
  return 0;
}

int FileTalker::deleter(string path, string filter) {

  if (filter == "emptyFolder") {
    // try {
      if (fs::is_directory(path)) {
        std::cout << path << '\n';
        if (fs::is_empty(path)) {
          std::cout << "is empty: " << path << '\n';
          fs::remove(path);
          std::cout << "deleted: " << path << '\n';
        }
      }
    // } catch (...) {}
  }
  return 0;
}
