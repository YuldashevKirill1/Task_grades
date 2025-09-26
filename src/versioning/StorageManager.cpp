#include "StorageManager.hpp"
#include "../utils/FileUtils.hpp"
#include <fstream>
#include <sstream>

namespace Versioning {

    StorageManager::StorageManager(const std::string& base_path) : vcspath(base_path + "/.vcs") {
        if (!Utils::exists(vcspath)) {
            Utils::createDir(vcspath);
            Utils::createDir(vcspath + "/commits");
            Utils::createDir(vcspath + "/objects");
        }
    }

    std::size_t simpleHash(const std::string& str) {
        std::size_t hash = 53;
        for (char c : str) {
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    std::string StorageManager::saveSnap(const std::map<std::string, std::string>& files) {
        std::string hashcontent;
        for (const auto& [path, data] : files) {
            hashcontent += path + "\0" + data + "\0";
        }

        std::size_t hashvalue = simpleHash(hashcontent);
        std::string hash = "snap_" + std::to_string(hashvalue);
        std::string object_path = vcspath + "/objects/" + hash;

        std::ostringstream content;
        for (const auto& [path, data] : files) {
            content << path << "\n" << data.size() << "\n" << data << "\n";
        }

        Utils::writeFile(object_path, content.str());
        return hash;
    }

    std::map<std::string, std::string> StorageManager::loadSnap(const std::string& hash) {
        std::string object_path = vcspath + "/objects/" + hash;
        std::string content = Utils::readFile(object_path);

        std::map<std::string, std::string> files;
        std::istringstream iss(content);
        std::string line;

        while (std::getline(iss, line)) {
            std::string path = line;
            if (!std::getline(iss, line)) break;

            size_t size = std::stoull(line);
            std::string data;
            data.resize(size);
            iss.read(&data[0], size);
            iss.ignore();

            files[path] = data;
        }

        return files;
    }

    void StorageManager::saveComm(const Commit& commit) {
        
    }

    Commit StorageManager::loadComm(const std::string& id) {
        
    }

    void StorageManager::deleteComm(const std::string& id) {
        
    }

    std::string StorageManager::readHead() {
        std::string head_path = vcspath + "/HEAD";
        if (!Utils::exists(head_path)) {
            return "";
        }
        return Utils::readFile(head_path);
    }

    void StorageManager::writeHead(const std::string& commit_id) {
        std::string head_path = vcspath + "/HEAD";
        Utils::writeFile(head_path, commit_id);
    }

}