#include "headers/Timer.hpp"

Timer::Timer() {
    startTime = pauseTime = 0;
    set = paused = false;
}

void Timer::start() {
    if (set) {
        return;
    }
    set = true;
    startTime = glutGet(GLUT_ELAPSED_TIME);
}
void Timer::stop() {
    set = paused = false;
    startTime = pauseTime = 0;
}
void Timer::pause() {
    if (!set) {
        return;
    }
    if (!paused) {
        paused = true;
        pauseTime = glutGet(GLUT_ELAPSED_TIME) - startTime;
    }
}
void Timer::resume() {
    if (!set) {
        return;
    }
    if (!paused) {
        return;
    } else {
        startTime = pauseTime;
        paused = false;
    }
}
void Timer::restart() {
    startTime = glutGet(GLUT_ELAPSED_TIME);
    pauseTime = 0;
    paused = false;
}
double Timer::getElapsedTime() const {
    if (!set) {
        return 0;
    }
    if (paused) {
        return pauseTime / 1000;
    }

    return (glutGet(GLUT_ELAPSED_TIME) - startTime + pauseTime) / 1000;
}
bool Timer::isSet() const {
    return set;
}