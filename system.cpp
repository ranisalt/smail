#include <chrono>
#include <functional>
#include <thread>
#include "generator.h"
#include "random.h"
#include "reception.h"
#include "system.h"
#include "service.h"

static double running_time;

bool System::paused = true;
double System::tecLocal = 0.5;
double System::tecRemote = 0.6;
int System::serverCountL = 10;
int System::serverCountR = 10;
MainWindow* System::ui = nullptr;

void System::run() {
    Generator lg{std::bind(&exponential_random, tecLocal), LOCAL};
    Generator rg{std::bind(&exponential_random, tecRemote), REMOTE};
    ReceptionServer rs{};
    ServiceServer sl{serverCountL};
    ServiceServer sr{serverCountR};

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds{100});

        if (paused) {
            continue;
        }

        lg.next(rs);
        rg.next(rs);
        rs.next(sl, sr);

        running_time += 0.1;
    }
}

double System::time() {
    return running_time;
}
