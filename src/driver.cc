#include "information.h"
#include "logger.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char * argv[]) {
  Logger::Initialize();

  LOG_INFO("Version {0}", VFC::get_version());

  cv::Mat frame;
  cv::VideoCapture cap;

  cap.open(0);

  // check if we succeeded
  if (!cap.isOpened()) {
      std::cerr << "ERROR! Unable to open camera\n";
      return -1;
  }

  //--- GRAB AND WRITE LOOP
  std::cout << "Start grabbing" << std::endl
      << "Press any key to terminate" << std::endl;
  
  for (;;)
  {
      // wait for a new frame from camera and store it into 'frame'
      cap.read(frame);
      // check if we succeeded
      if (frame.empty()) {
          std::cerr << "ERROR! blank frame grabbed\n";
          break;
      }
      // show live and wait for a key with timeout long enough to show images
      cv::imshow("Live", frame);
      if (cv::waitKey(5) >= 0)
          break;
  }

  return 0;
}

