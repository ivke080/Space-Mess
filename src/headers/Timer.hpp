#ifndef TIMER_H_
#define TIMER_H_
#include <GL/glut.h>

class Timer {

    private:
        double startTime;
        double pauseTime;

        bool set;
        bool paused;
    public:
        Timer();

        void start();
        void stop();
        void pause();
        void resume();
        void restart();

        double getElapsedTime() const;
        bool isSet() const;
};


#endif