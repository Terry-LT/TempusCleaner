#include "UserUtils.h"

std::string getUsername() {
    char username[UNLEN + 1];
    DWORD size = UNLEN + 1;

    if (GetUserNameA(username, &size)) {
        return std::string(username);
    }
    return "Unknown";
}