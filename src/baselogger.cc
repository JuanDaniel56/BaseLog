#include "baselogger.hh"

namespace logger
{

BaseLogger::BaseLogger(LogLevel level) : _level(level)
{}

void BaseLogger::log(LogLevel level, std::string msg)
{
    if (level <= _level)
    {
        switch (level)
        {
        case LogLevel::DEBUG:
            DEBUG(msg);
            break;
        case LogLevel::WARNING:
            INFO(msg);
            break;
        case LogLevel::INFO:
            INFO(msg);
            break;
        case LogLevel::ERROR:
            ERROR(msg);
            break;
        case LogLevel::FATAL:
            FATAL(msg);
            break;
        default:
            break;
        }
    }
}


void BaseLogger::DEBUG(std::string msg)
{
    std::cout << '[' << currentTime() << "][DEBUG] " << msg << std::endl;
}

void BaseLogger::INFO(std::string msg)
{
    std::cout << '[' << currentTime() << "][INFO] " << msg << std::endl;
}

void BaseLogger::WARNING(std::string msg)
{
    std::cout << '[' << currentTime() << "][WARNING] " << msg << std::endl;
}

void BaseLogger::ERROR(std::string msg)
{
    std::cout << '[' << currentTime() << "][ERROR] " << msg << std::endl;
}

void BaseLogger::FATAL(std::string msg)
{
    std::cout << '[' << currentTime() << "][FATAL] " << msg << std::endl;
}

std::string BaseLogger::currentTime()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

}  // namespace logger