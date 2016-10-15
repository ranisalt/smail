#pragma once

enum class EmailType {
    LOCAL,
    REMOTE,
};

class Email {
public:
    Email(EmailType sender, EmailType receiver):
            sender{sender}, receiver{receiver} {}

    Email(const Email& email) = default;

    const EmailType sender;
    const EmailType receiver;
};
