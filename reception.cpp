#include "reception.h"



ReceptionServer::PendingEmail::PendingEmail(Email email):
    email{email} {}

void ReceptionServer::push(Email e) {
    queue.emplace(e);
}
