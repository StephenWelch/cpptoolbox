//
// Created by stephen on 9/4/19.
//

#ifndef JOURNEY_ELEVATORMODEL_H
#define JOURNEY_ELEVATORMODEL_H

#include <Eigen/Core>
#include "../control/StateSpaceModel.h"

using Eigen::Matrix;

class ElevatorModel : public StateSpaceModel<2, 1, 1> {

public:
    const double friction_coeff;
    const double mass;

    ElevatorModel(const double frictionCoeff, const double mass) : friction_coeff(frictionCoeff), mass(mass) {
        A <<    0,  1,
                0,  -friction_coeff / mass;

        B <<    0,
                1 / mass;

        C <<    0,  1;

        D << 0   ;
    }

};

#endif //JOURNEY_ELEVATORMODEL_H
