#include "reception.h"
#include "system.h"
#include "service.h"

ReceptionServer::PendingEmail::PendingEmail(Email email):
    email{email}, arrival{System::time()} {}

void ReceptionServer::push(Email e) {
    queue.emplace(e);
}

void ReceptionServer::next(ServiceServer& sl, ServiceServer& sr) {
    auto system_time = System::time();
    if (system_time > next_tick and queue.size() > 0) {
        auto e = queue.front();
        queue.pop();
        e.departure = system_time;
        history.push_back(e);
        switch (e.email.receiver) {
            case LOCAL:
                sl.push(e.email);
                break;
            case REMOTE:
            default:
                sr.push(e.email);
                break;
        }
        next_tick = system_time +
    }
}
