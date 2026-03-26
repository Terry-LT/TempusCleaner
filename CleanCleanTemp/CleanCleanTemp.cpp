#include <iostream>
#include "Cleaner.h"
#include "Message.h"
#include "PathUtils.h"
#include "UserUtils.h"

int main() {

	std::string adminTempPath, userTempPath;
	getTempPath(adminTempPath, userTempPath,getUsername());
    std::vector<Message> results;
    uintmax_t totalBytes = 0;
    int count = 0;

    cleanFolder(adminTempPath, results, count, totalBytes);
    cleanFolder(userTempPath, results, count, totalBytes);

    
    for (const Message& message : results) {
        std::cout << message.text << ": " << message.filePath;
		std::cout << (message.errorMessage.empty() ? "" : " - " + message.errorMessage) << std::endl;
    }

    double mb = totalBytes / (1024.0 * 1024.0);
    double gb = totalBytes / (1024.0 * 1024 * 1024);

	std::cout << "Total files deleted: " << count << std::endl;
    std::cout << "Freed space: " << mb << "MB" << std::endl;
    std::cout << "Freed space: " << gb << "GB" << std::endl;

    std::cout << "\nPress ENTER to exit...";
    std::cin.get();

    return 0;
}