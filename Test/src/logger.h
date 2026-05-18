#include <atomic>

class Logger {
    private:
        static std::atomic_flag disponible;

    public:
        static void Log(string message);
};