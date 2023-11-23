# BaseLog
A base log implement by C++

## How to build
```bash
mkdir build
cd build
cmake ..
make
```

## Use
```C++
// include header
#include "baselogger.hh"

// Create Object
Logger::BaseLogger logger(logger::LogLevel::WARNING);

// print log
std::string msg("info msg");
logger.log(logger::LogLevel::INFO, msg);
```