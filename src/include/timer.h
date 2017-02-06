#ifndef SRC_INCLUDE_TIMER_H_
#define SRC_INCLUDE_TIMER_H_

#include <cstdint>

class Timer {
    public:
        Timer();

        void Start();
        void Stop();
        void Pause();
        void Unpause();

        uint32_t getTicks();
        bool isStarted() { return started_; }
        bool isPaused() { return paused_; }

    private:
        uint32_t startTicks_;
        uint32_t pausedTicks_;
        bool paused_;
        bool started_;
};

#endif

