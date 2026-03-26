#pragma once

#include <string>
enum class MessageType {
    INFO,
    WARNING,
    ERROR_TYPE
};

struct Message {
    std::string text;
    std::string filePath;
    std::string errorMessage;
    MessageType type;
};