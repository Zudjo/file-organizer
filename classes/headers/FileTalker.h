#include <map>
#include <string>
using namespace std;
typedef int (*pFunction)(string, string);

class FileTalker {
private:
  static map<int, string> menuFunctions;
  static string outputDirectory;
  static int folderer(string file, string filter);
  static int renamer(string file, string filter);
  static int deleter(string pathDirectory, string filter);
  static pFunction getFunction(int menuNumber);
public:
  static int runFunction(int menuNumber, string pathDirectory);
  static bool checkMenuNumber(int menuNumber);
};
