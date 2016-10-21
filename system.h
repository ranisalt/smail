#pragma once

#include <cstdint>
#include "mainwindow.h"

class System {
public:
    System() = delete;

    static void run();

    static double time();

    static bool paused;
    static double tecLocal;
    static double tecRemote;
    static int serverCountL;
    static int serverCountR;
    static MainWindow* ui;
};
