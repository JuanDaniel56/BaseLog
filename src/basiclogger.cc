#include "basiclogger.hh"


namespace basiclogger
{

const std::unordered_map<LogLevel, std::string> BasicLogger::level_string_ = {
    {LogLevel::DEBUG, "DEBUG"},
    {LogLevel::WARNING, "WARNING"},
    {LogLevel::INFO, "INFO"},
    {LogLevel::ERROR, "ERROR"},
    {LogLevel::FATAL, "FATAL"}
};


const std::unordered_map<LogLevel, std::string> level_output_color_= {
    {LogLevel::DEBUG, "\033[32m"},
    {LogLevel::WARNING, "\033[33m"},
    {LogLevel::INFO, "\033[37m"},
    {LogLevel::ERROR, "\033[31m"},
    {LogLevel::FATAL, "\033[1;31m"}
};


BasicLogger::BasicLogger()
: level_(LogLevel::INFO), datefmt_("%Y-%m-%d %H:%M:%S"), log_to_file_(false)
{}

BasicLogger::BasicLogger(LogLevel level)
: level_(level), datefmt_("%Y-%m-%d %H:%M:%S"), log_to_file_(false)
{}

BasicLogger::BasicLogger(LogLevel level, std::string datefmt)
: level_(level), datefmt_(datefmt), log_to_file_(false)
{}

BasicLogger::BasicLogger(LogLevel level, std::string datefmt, bool log_to_file, std::string log_path)
: level_(level), datefmt_(datefmt), log_to_file_(log_to_file), log_path_(log_path)
{}


void BasicLogger::Log(LogLevel level, std::string content)
{
    if (int(level) < int(level_))
        return;
    
    if (log_to_file_)
    {
        // 打开log文件
        std::ofstream log_file(log_path_, std::ios::app);

        if (log_file.is_open())
        {
            log_file << currentTime() << " [" << BasicLogger::level_string_.at(level) << "] " << content << std::endl; 
            // log_file << currentTime() << " "<< content << std::endl; 
            log_file.close();
        }
        else
        {
            if (int(LogLevel::ERROR) >= int(level_))
            {
                std::cout << currentTime() << " [" << BasicLogger::level_string_.at(LogLevel::ERROR) << "] " << "log file open failed.." << std::endl;
                // std::cout << currentTime() << " " << "log file open failed.." << std::endl;
            }
        }
    }

    std::string level_string =  level_output_color_.at(level) + std::string(" [") + BasicLogger::level_string_.at(level) + std::string("] \033[0m");

    // std::cout << currentTime() << " [" << BasicLogger::level_string_.at(level) << "] " << content << std::endl;
    // std::cout << currentTime() << " " << content << std::endl;
    std::cout << currentTime() << level_string << content << std::endl;

    return ;
}



void BasicLogger::Debug(std::string content)
{
    Log(LogLevel::DEBUG, content);

    return ;
}

void BasicLogger::Warning(std::string content)
{
    Log(LogLevel::WARNING, content);

    return ;
}


void BasicLogger::Info(std::string content)
{
    Log(LogLevel::INFO, content);

    return;
}


void BasicLogger::Error(std::string content)
{
    Log(LogLevel::ERROR, content);

    return;
}


void BasicLogger::Fatal(std::string content)
{
    Log(LogLevel::FATAL, content);

    return;
}


std::string BasicLogger::currentTime()
{
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time_t), datefmt_.c_str());

    return ss.str();
}


}  // namespace basiclogger