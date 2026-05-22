#pragma once
#include <atomic>
#include <Arduino.h>

class Logger {
    private:
        static std::atomic_flag disponible;

    public:
        static void Log(const String &message);
};