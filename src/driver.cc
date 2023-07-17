#include "information.h"
#include "logger.h"

int main(int argc, char * argv[]) {
  Logger::Initialize();

  LOG_INFO("Version {0}", VFC::get_version());

  return 0;
}

