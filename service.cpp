#include "service.h"

ServiceServer::PendingEmail::PendingEmail(Email email):
        email{email} {}

ServiceServer::ServiceServer(std::size_t servers): servers{servers} {}

void ServiceServer::push(Email e) {
    queue.emplace(e);
}
