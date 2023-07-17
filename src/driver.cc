#include <iostream>

#include "information.h"

int main(int argc, char * argv[]) {
  std::cout << "Application version: " << VFC::get_version() << std::endl;

  return 0;
}

