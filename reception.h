#pragma once

#include <queue>
#include <vector>

#include "email.h"
#include "random.h"

class ReceptionServer {
    struct PendingEmail {
        PendingEmail(Email email);

        Email email;
        double arrival;
        double departure;
    };

public:
    ReceptionServer() = default;

    void push(Email email);

    void next(ServiceServer& sl, ServiceServer& sr);

    std::size_t size() const {
        return queue.size();
    }

private:
    double next_tick = 0.0;
    std::queue<PendingEmail> queue;
    std::vector<PendingEmail> history;
};
