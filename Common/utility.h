#ifndef UTILITY_H
#define UTILITY_H
#include <chrono>

namespace ecilib::utility{
inline const uint64_t current_epoch_ms()
{
    using namespace std::chrono;
    const auto now = system_clock::now();
    const auto duration = now.time_since_epoch();
    const auto millis = duration_cast<milliseconds>(duration).count();

    return static_cast<uint64_t>(millis);
}
}
#endif // UTILITY_H
