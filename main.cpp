#include "./classes/headers/UserTalker.h"
#include "./classes/headers/FileTalker.h"
using namespace std;

int main() {
  int menuNumber = UserTalker::getMenuNumber();
  FileTalker::runFunction(menuNumber, "C:\\Users\\Administrator\\Desktop\\dati_mamma");
}
