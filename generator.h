#pragma once

#include <functional>
#include "email.h"
#include "reception.h"

class Generator {
public:
    Generator(std::function<double()> fn, EmailType type);

    void next(ReceptionServer&);

private:
    EmailType random_type();

    double last_tick;
    std::function<double()> fn;
    EmailType type;
    int llcount = 0, lrcount = 0, rlcount = 0, rrcount = 0;
};
