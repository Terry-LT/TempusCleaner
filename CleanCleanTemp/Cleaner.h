#pragma once

#include <vector>
#include <string>
#include "Message.h"

void cleanFolder(const std::string& folder, 
				std::vector<Message>& results, 
				int& count, 
				uintmax_t& totalBytes);