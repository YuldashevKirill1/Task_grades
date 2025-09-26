#pragma once

#include <string>
#include <vector>
#include <map>
#include <stdexcept>

namespace Utils {

	void createDir(const std::string& path);

	void writeFile(const std::string& path, const std::string& content);

	std::string readFile(const std::string& path);

	bool exists(const std::string& path);

	std::vector<std::string> listFiles(const std::string& dir);

	std::map<std::string, std::string> collectFiles(const std::string& dir);

}