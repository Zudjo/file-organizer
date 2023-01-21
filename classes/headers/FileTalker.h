#include <map>
#include <string>
using namespace std;

class FileTalker {
private:
  static map<int, string> menuFunctions;
  static int folderer(string file, string filter);
  static int renamer(string file, string filter);
  static int deleter(string patDirectory, string filter);
public:
  static int runFunction(int menuNumber, string filter, string pathDirectory);
  static bool checkMenuNumber(int menuNumber);
};
