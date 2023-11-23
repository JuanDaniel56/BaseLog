#ifndef BASE_LOGGER_HH
#define BASE_LOGGER_HH

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>


namespace logger
{

/**
 * \brief The level of log
*/
enum LogLevel
{
    DEBUG,
    WARNING,
    INFO,
    ERROR,
    FATAL
};

class BaseLogger
{
public:
    BaseLogger(LogLevel level);

    void log(LogLevel level, std::string msg);

    void DEBUG(std::string msg);

    void WARNING(std::string msg);

    void INFO(std::string msg);

    void ERROR(std::string msg);

    void FATAL(std::string msg);

private:
    LogLevel _level;

    std::string currentTime();
};

}  // namespace logger

#endif // BASE_LOGGER_HH