//
// Created by stephen on 9/3/19.
//

#ifndef JOURNEY_STATESPACEMODEL_H
#define JOURNEY_STATESPACEMODEL_H

#include <Eigen/Core>
#include <iostream>

using Eigen::Matrix;

template<int num_states, int num_inputs, int num_outputs = num_inputs> class StateSpaceModel {

protected:
    StateSpaceModel() {

    }

    Matrix<double, num_states, num_states> A; // State transition
    Matrix<double, num_states, num_inputs> B; // Input
    Matrix<double, num_outputs, num_states> C; // Observation
    Matrix<double, num_outputs, num_inputs> D; // Direct transmission

public:

    typedef Matrix<double, num_inputs, num_states> Gains;
    typedef Matrix<double, num_states, 1> State;
    typedef Matrix<double, num_inputs, 1> Input;
    typedef Matrix<double, num_outputs, 1> Output;

    State get_change_in_state(const State& x, const Input& u) const {
        return (A * x) + (B * u);
    }

    int get_num_states() const {
        return num_states;
    }

    int get_num_inputs() const {
        return num_inputs;
    }

    int get_num_outputs() const {
        return num_outputs;
    }

    Matrix<double, num_states, num_states> &getA() const {
        return A;
    }

    Matrix<double, num_states, num_inputs> &getB() const {
        return B;
    }

    Matrix<double, num_outputs, num_states> &getC() const {
        return C;
    }

    Matrix<double, num_outputs, num_inputs> &getD() const {
        return D;
    }

};

#endif //JOURNEY_STATESPACEMODEL_H
