#include "global.cpp"


// inject here

struct point{
    double x, y;

    double dist(point other){
        double diff_x = other.x - x;
        double diff_y = other.y - y;
        return sqrt(diff_x * diff_x + diff_y * diff_y);
    }
};

// inject stop

int main() {
    timer tim;
    tim.ok();
    return 0;
}