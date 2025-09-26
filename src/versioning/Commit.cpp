#include "Commit.hpp"

namespace Versioning {

    Commit::Commit(
        std::string id,
        std::string message,
        std::string author,
        std::time_t timestamp,
        std::time_t expires_at,
        std::string snapshot_id,
        std::string parent_id)
        : id(id),
        message(message),
        author(author),
        timestamp(timestamp),
        expires_at(expires_at),
        snapshot_id(snapshot_id),
        parent_id(parent_id)
    {}

    bool Commit::isExpired() const {
        return std::time(nullptr) >= expires_at;
    }

}