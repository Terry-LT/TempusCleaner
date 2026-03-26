#include "PathUtils.h"

void getTempPath(std::string& adminTempPath, std::string& userTempPath, std::string userName) {
    adminTempPath = "C:\\Windows\\Temp";
    userTempPath = "C:\\Users\\" + userName + "\\AppData\\Local\\Temp";
}