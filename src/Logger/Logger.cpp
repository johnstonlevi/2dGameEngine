#include "Logger.h"
#include <iostream>
#include <ctime>
#include <algorithm>

std::vector<LogEntry> Logger::messages;

void Logger::Log(const std::string& message)
{
    // Create a timestamp
    time_t now = time(0);
    std::string dt = ctime(&now);

    // Remove the newline
    dt.erase(std::remove(dt.begin(), dt.end(), '\n'), dt.end());

    // Create log entry
    LogEntry logEntry;
    logEntry.type = LOG_INFO;

    // Write message to log
    logEntry.message = "\33[32mLOG: [" + dt + "] - " + message;


    // Push to vector
    messages.push_back(logEntry);
}

void Logger::Wrn(const std::string& message)
{
    // Create a timestamp
    time_t now = time(0);
    std::string dt = ctime(&now);

    // Remove the newline
    dt.erase(std::remove(dt.begin(), dt.end(), '\n'), dt.end());

    // Create log entry
    LogEntry logEntry;
    logEntry.type = LOG_WARNING;

    // Write message to log
    logEntry.message = "\33[33mLOG: [" + dt + "] - " + message;


    // Push to vector
    messages.push_back(logEntry);
}

void Logger::Err(const std::string& message)
{
    // Create a timestamp
    time_t now = time(0);
    std::string dt = ctime(&now);

    // Remove the newline
    dt.erase(std::remove(dt.begin(), dt.end(), '\n'), dt.end());

    // Create log entry
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;

    // Write message to log
    logEntry.message = "\33[31mERROR: [" + dt + "] - " + message;

    // Push to vector
    messages.push_back(logEntry);
}