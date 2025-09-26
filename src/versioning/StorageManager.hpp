#pragma once

#include <string>
#include <map>
#include "Commit.hpp"

namespace Versioning {

    class StorageManager {
    private:
        std::string vcspath;

    public:
        StorageManager(const std::string& base_path);

        std::string saveSnap(const std::map<std::string, std::string>& files);
        std::map<std::string, std::string> loadSnap(const std::string& hash);

        void saveComm(const Commit& commit);
        Commit loadComm(const std::string& id);
        void deleteComm(const std::string& id);

        std::string readHead();
        void writeHead(const std::string& commit_id);

    };

}