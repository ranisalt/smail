#pragma once

#include <cstdint>

enum EmailType {
    LOCAL,
    REMOTE,
};

class Email {
public:
    Email(double created_at, EmailType sender, EmailType receiver) :
            created_at{created_at}, sender{sender}, receiver{receiver} {}

    Email(const Email& email) = default;

    const double created_at;
    const EmailType sender;
    const EmailType receiver;
};
