#include <iostream>
#include "./headers/UserTalker.h"

int UserTalker::get_input() {
  int a;
  std::cout << "insert a number: ";
  std::cin >> a;
  std::cout << a;
  return a;
}
