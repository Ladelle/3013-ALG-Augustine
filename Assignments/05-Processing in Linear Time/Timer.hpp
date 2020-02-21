#include <time.h>
#include <chrono> 
#include <thread>

using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds Msec;
typedef std::chrono::duration<float> Fsec;


class Timer {
private:
    int seed;
    int micro;
    Time::time_point start;
    Time::time_point end;
    Fsec seconds;
    Msec milliseconds;

public:
    Timer() {
    }

    void Start() {
        start = Time::now();
    }

    void End() {
        end = Time::now();
    }

    double Seconds() {
        auto dur = end - start;
        auto secs = std::chrono::duration_cast<Fsec>(dur);
        return secs.count();
    }

    long MilliSeconds() {
        auto dur = end - start;
        auto millis = std::chrono::duration_cast<Msec>(dur);
        return millis.count();
    }

    void Sleep(long x) {
        std::this_thread::sleep_for(std::chrono::milliseconds(x));
    }

};