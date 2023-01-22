#include "./headers/FileTalker.h"
#include <map>
#include <filesystem>
using namespace std;

namespace fs = std::filesystem;
typedef int (*pFunction)(string, string);

map<int, string> FileTalker::menuFunctions = {
  { 10, "extension" },
  { 11, "creationDate" },
  { 12, "editDay" },
  { 21, "creationDate" },
  { 31, "identicalCopy" }
};

string FileTalker::outputDirectory;

int FileTalker::runFunction(int menuNumber, string pathDirectory) {
  pFunction function = FileTalker::getFunction(menuNumber);
  string path;
  FileTalker::outputDirectory = pathDirectory + "\\..\\FileOrganizer";

  fs::create_directory(FileTalker::outputDirectory);

  for (const fs::directory_entry& dir_entry :
      fs::recursive_directory_iterator(pathDirectory)) {

    if (!dir_entry.is_directory()) {

      path = dir_entry.path().string();
      function(path, FileTalker::menuFunctions[menuNumber]);
    }

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

int FileTalker::folderer(string file, string filter) {
  if (filter == "extension") {
    string fileName = file.substr(file.find_last_of("/\\") + 1);
    string extension = file.substr(file.find_last_of(".") + 1);
    string extensionDirectory = FileTalker::outputDirectory + "\\" + extension;

    if (!fs::exists(extensionDirectory)) {
      fs::create_directory(extensionDirectory);
    }

    fs::rename(file, extensionDirectory + "\\" + fileName);
  }
  return 0;
}

int FileTalker::renamer(string file, string filter) {
  return 0;
}

int FileTalker::deleter(string pathDirectory, string filter) {
  return 0;
}
