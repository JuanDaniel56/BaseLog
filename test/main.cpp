#include "basiclogger.hh"

int main()
{
    basiclogger::BasicLogger logger(basiclogger::LogLevel::INFO, "%Y-%m-%d_%H:%M:%S", true, "log.txt");

    logger.Debug("This is a debug inforamtion");
    logger.Warning("This is a warning inforamtion");
    logger.Info("This is a info inforamtion");
    logger.Error("This is a error inforamtion");
    logger.Fatal("This is a fatal inforamtion");

    return 0;
}