#ifndef _BASIC_LOGGER_HH_
#define _BASIC_LOGGER_HH_

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <unordered_map>


namespace basiclogger
{


enum LogLevel
{
    DEBUG,
    WARNING,
    INFO,
    ERROR,
    FATAL
};



class BasicLogger
{
public:
    static const std::unordered_map<LogLevel, std::string> level_string_;

    BasicLogger();

    BasicLogger(LogLevel level);

    BasicLogger(LogLevel level, std::string datefmt);

    BasicLogger(LogLevel level, std::string datefmt, bool log_to_file=true, std::string log_path = "./log.txt");

    void Log(LogLevel level, std::string content);

    void Debug(std::string content);

    void Warning(std::string content);

    void Info(std::string content);

    void Error(std::string content);

    void Fatal(std::string content);

private:
    LogLevel level_;

    std::string datefmt_;

    std::string log_path_;

    bool log_to_file_;

    std::string currentTime();
};


}  // namespace basiclogger


#endif  // _BASIC_LOGGER_HH_