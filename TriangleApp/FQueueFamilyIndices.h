//
// Created by fush on 11/8/24.
//

#ifndef FQUEUEFAMILYINDICES_H
#define FQUEUEFAMILYINDICES_H
#include <cstdint>
#include <optional>

struct FQueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() const {
        return graphicsFamily.has_value();
    }
};

#endif //FQUEUEFAMILYINDICES_H
