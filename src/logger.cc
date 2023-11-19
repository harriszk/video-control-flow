// @file logger.cc
// Created on 07/17/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Logger::logger_;

void Logger::Initialize() {
  // See for pattern formatting:
  // https://internal.dunescience.org/doxygen/classspdlog_1_1pattern__formatter.html 
  spdlog::set_pattern("[%x %T] [%n] [%^%l%$] %v");
  logger_ = spdlog::stdout_color_mt("VFC");
  logger_->set_level(spdlog::level::trace);

  LOG_INFO("Initialized logger!");
}