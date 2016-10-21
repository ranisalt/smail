#include "generator.h"
#include "random.h"
#include "system.h"

Generator::Generator(std::function<double()> fn, EmailType type):
        last_tick{fn()}, fn{std::move(fn)}, type{type} {}

void Generator::next(ReceptionServer& rs) {
    if (System::time() > last_tick) {
        auto created_at = last_tick + fn();
        auto dest_type = random_type();
        rs.push({created_at, type, dest_type});
    }
}

EmailType Generator::random_type() {
    auto r = uniform_random(0.0, 1.0);
    switch (type) {
        case LOCAL:
            if (r < 0.67) {
                System::ui->updateLocalLocalCount(++llcount);
                return LOCAL;
            } else {
                System::ui->updateLocalRemoteCount(++lrcount);
                return REMOTE;
            }
        case REMOTE:
        default:
            if (r < 0.75) {
                System::ui->updateRemoteLocalCount(++rlcount);
                return LOCAL;
            } else {
                System::ui->updateRemoteRemoteCount(++rrcount);
                return REMOTE;
            }
    }
}
