#include <iostream>
#include <matplotlibcpp.h>
#include "elevator_example/Elevator.h"
#include "util/Graph.cpp"

namespace plt = matplotlibcpp;

int main() {

    Elevator elevator = Elevator();

    double max_time = 20.0;
    double dt = 0.05;
    double time = 0.0;

    while(time <= max_time) {
        elevator.update(dt);

        time += dt;

        Graph::instance().add_xvalue(time);
    }

    Graph::instance().plot("Elevator Controller");

    return 0;
}