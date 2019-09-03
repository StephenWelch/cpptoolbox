//
// Created by stephen on 8/31/19.
//

#ifndef JOURNEY_STATESPACECONTROLLER_H
#define JOURNEY_STATESPACECONTROLLER_H

#include <Eigen/Dense>

using Eigen::Matrix;

template<int X, int U, int Y=X> class StateSpaceController {

private:
    Matrix<double, X, X> state_transition_matrix;
    Matrix<double, X, U> input_matrix;
    Matrix<double, Y, X> observation_matrix;
    Matrix<double, Y, U> direct_transmission_matrix;
    Matrix<double, X, U> gains;

public:

};


#endif //JOURNEY_STATESPACECONTROLLER_H
