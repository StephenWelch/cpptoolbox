//
// Created by stephen on 9/3/19.
//

#ifndef JOURNEY_ELEVATOR_H
#define JOURNEY_ELEVATOR_H

#include "ElevatorModel.h"
#include "../control/StateSpaceController.h"
#include <iostream>

using Eigen::Matrix;

class Elevator {
private:
    ElevatorModel model = ElevatorModel(10, 100);
    StateSpaceController<2, 1, 1> controller = StateSpaceController<2, 1, 1>(model);
    ElevatorModel::State x = ElevatorModel::State();
    ElevatorModel::State gravity(const double &dt){
        Matrix<double, 2, 1> gravity;
        gravity << .5 * -9.81 * dt * dt,
                -9.81 * dt;
        return gravity;
    }
public:
    Elevator() {

        ElevatorModel::Gains k;
        ElevatorModel::Input min_u;
        ElevatorModel::Input max_u;
        k << 30, 70;
        min_u << -500;
        max_u << 500;
        controller.set_gains(k);
        controller.set_min_u(min_u);
        controller.set_max_u(max_u);

//        ElevatorModel::State goal = ElevatorModel::State();
//        goal << 10,
//                0;
//
//        controller.set_reference(goal);
        ElevatorModel::State start = ElevatorModel::State();
        start << 10,
                0;

        x = start;
    }

    void update(double dt) {
        auto& graph = Graph::instance();
        graph.add_yvalue("Position", get_position());
        graph.add_yvalue("Velocity", get_velocity());
        graph.add_yvalue("Position Reference", controller.get_reference()(0, 0));
        graph.add_yvalue("Input", controller.calculate_input(x)(0, 0));

        ElevatorModel::State d_x = controller.update(x);
        x += d_x * dt;

//        x += gravity(dt);
    }

    double get_position() const {
        return x(0, 0);
    }

    double get_velocity() const {
        return x(1, 0);
    }

};

#endif //JOURNEY_ELEVATOR_H
