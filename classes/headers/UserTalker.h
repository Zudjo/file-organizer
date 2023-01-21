#include <string>
using namespace std;

class UserTalker {
private:
  static string menuFunctions;
public:
  static int getMenuNumber();
  static string getPathDirectory();
  static void print(string text);
  static void print(int text);
};
