#pragma once

#include <string>
#include <ctime>

namespace Versioning {

    struct Commit {
        std::string id; std::string message;
        std::string author; std::time_t timestamp;
        std::time_t expires_at; std::string snapshot_id;
        std::string parent_id;

        Commit(
            std::string id, std::string message,
            std::string author, std::time_t timestamp,
            std::time_t expires_at, std::string snapshot_id,
            std::string parent_id = ""
        );

        bool isExpired() const;
    };

}