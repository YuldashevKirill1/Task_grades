#include "FileUtils.hpp"
#include <fstream>
#include <filesystem>

namespace Utils {

    void createDir(const std::string& path) {
        std::error_code ec;
        bool success = std::filesystem::create_directories(path, ec);

        if (ec) {
            std::string error = path + " error create." + ec.message();
            throw std::runtime_error(error);
        }
    }

    void writeFile(const std::string& path, const std::string& content) {
        std::ofstream file(path, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error(path + " error open.");
        }

        file << content;

        if (!file.good()) {
            throw std::runtime_error(path + " error write.");
        }
    }

    std::string readFile(const std::string& path) {
        std::ifstream file(path, std::ios::binary);

        if (!file.is_open()) {
            throw std::runtime_error(path + " error open.");
        }

        file.seekg(0, std::ios::end);
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::string content;
        content.resize(static_cast<size_t>(size));

        if (!file.read(&content[0], size)) {
            throw std::runtime_error(path + " error read.");
        }

        return content;
    }

    bool exists(const std::string& path) {
        return std::filesystem::exists(path);
    }

    std::vector<std::string> listFiles(const std::string& dir) {
        std::vector<std::string> files;
        std::error_code ec;

        for (const auto& entry : std::filesystem::directory_iterator(dir, ec)) {
            if (ec) {
                break;
            }
            if (entry.is_regular_file()) {
                files.push_back(entry.path().filename().string());
            }
        }

        return files;
    }

}