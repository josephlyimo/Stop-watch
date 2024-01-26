M#include <iostream>
#include <chrono>
#include <thread>

class Stopwatch {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;

public:
    void start() {
        start_time = std::chrono::steady_clock::now();
    }

    void stop() {
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";
    }

    double elapsed_seconds() {
        auto end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        return elapsed_seconds.count();
    }
};

int main() {
    Stopwatch stopwatch;
    char input;

    std::cout << "Press any key to start the stopwatch...";
    std::cin.get();

    stopwatch.start();

    std::cout << "Stopwatch started. Press any key to stop...\n";

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Update display every 100 milliseconds
        std::cout << "\rElapsed time: " << stopwatch.elapsed_seconds() << " seconds" << std::flush;
        if (std::cin.get() != '\n') // Stop when any key is pressed
            break;
    }

    stopwatch.stop();

    return 0;
}
