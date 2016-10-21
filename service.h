#pragma once

#include <queue>

class ServiceServer {
    struct PendingEmail {
        PendingEmail(Email email);

        Email email;
        std::size_t arrival;
        std::size_t departure;
    };

public:
    ServiceServer(std::size_t servers);

    void push(Email email);

    Email pop();

    std::size_t size() const {
        return queue.size();
    }

private:
    std::size_t servers;
    std::size_t occupied = 0;
    std::queue<PendingEmail> queue;
    std::vector<PendingEmail> history;
};
