#include <filesystem>
#include <vector>
#include "Message.h"
#include "Cleaner.h"
namespace fs = std::filesystem;

void cleanFolder(const std::string& folder, std::vector<Message>& results, int& count, uintmax_t& totalBytes) {
    //Use error code to handle exceptions insted of try catch
    std::error_code exists_ec;
    std::error_code empty_ec;

    // Check if the folder exists and handle any potential errors
    bool folderExists = fs::exists(folder, exists_ec);
    if (exists_ec) {
        results.push_back({
            "Error accessing folder",
            folder,
            exists_ec.message(),
            MessageType::ERROR_TYPE
            });
        return; //stops execution of this function if there's an error accessing the folder
    }

    if (!folderExists) {
        results.push_back({
                "Folder does not exist",
                folder,
                "",
                MessageType::WARNING
            });
        return; //stops execution of this function if folder doesn't exist
    }
    // Check if the folder is empty and handle any potential errors
    if (fs::is_empty(folder, empty_ec)) {
        if (empty_ec) {
            results.push_back({
                "Error accessing folder",
                folder,
                empty_ec.message(),
                MessageType::ERROR_TYPE
                });
        }
        else {
            results.push_back({
                "Folder is empty",
                folder,
                "",
                MessageType::INFO
                });
        }
        return;//stops execution of this function if folder is empty

    }
    // Iterate through the folder and delete files, handling any potential errors
    std::error_code ec;
    for (const auto& entry : fs::directory_iterator(folder, ec)) {
        if (ec) {
            results.push_back({
            "Error accessing folder",
            folder,
            ec.message(),
            MessageType::ERROR_TYPE
                });
            break;
        }
        std::error_code remove_ec;
        // Get file size before deletion and handle any potential errors
        uintmax_t size = 0;
        std::error_code size_ec;

        if (fs::is_regular_file(entry.path(), size_ec)) {
            size = fs::file_size(entry.path(), size_ec);
        }

        fs::remove_all(entry.path(), remove_ec);

        if (remove_ec) {
            results.push_back({
                "Error deleting",
                entry.path().string(),
                remove_ec.message(),
                MessageType::ERROR_TYPE
                });
        }
        else {
            if (size_ec) {
                results.push_back({
                    "File Deleted (size unknown)",
                    entry.path().string(),
                    size_ec.message(),
                    MessageType::WARNING
                    });
            }
            else {
                totalBytes += size;

                results.push_back({
                    "File Deleted",
                    entry.path().string(),
                    "",
                    MessageType::INFO
                    });
            }
            count++;
        }
    }

}