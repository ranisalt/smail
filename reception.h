#pragma once

#include <memory>
#include <queue>
#include <vector>

#include "email.h"
#include "random.h"

class ReceptionServer {
    struct PendingEmail {
        PendingEmail(Email email);

        Email email;
        std::size_t arrival;
        std::size_t departure;
    };

public:
    ReceptionServer() = default;

    void push(Email email);

    std::size_t size() const {
        return queue.size();
    }

private:
    std::queue<PendingEmail> queue;
    std::vector<PendingEmail> history;
};
