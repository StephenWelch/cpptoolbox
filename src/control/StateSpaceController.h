//
// Created by stephen on 9/3/19.
//

#ifndef JOURNEY_STATESPACECONTROLLER_H
#define JOURNEY_STATESPACECONTROLLER_H

#include <Eigen/Core>
#include "StateSpaceModel.h"
#include "../util/Graph.h"
#include "../util/util.h"
#include <iostream>
#include <numeric>

using Eigen::Matrix;

template<int num_states, int num_inputs, int num_outputs = num_inputs>
class StateSpaceController {
private:
    typedef StateSpaceModel<num_states, num_inputs, num_outputs> Model;

    Model model;
    typename Model::Gains K = Eigen::Matrix<double, num_inputs, num_states>::Zero();
    typename Model::State R = Eigen::Matrix<double, num_states, 1>::Zero();
    typename Model::Input min_u = Eigen::Matrix<double, num_inputs, 1>::Constant(-std::numeric_limits<double>::infinity());
    typename Model::Input max_u = Eigen::Matrix<double, num_inputs, 1>::Constant(std::numeric_limits<double>::infinity());
//    typename Model::Output y = Eigen::Matrix<double, num_outputs, 1>::Zero();

public:
    StateSpaceController(Model &model) : model(model) {}

    typename Model::Input calculate_input(const typename Model::State &x) const {
        typename Model::Input u = K * (R - x);

        return cap_matrix(u, min_u, max_u);
    }

    typename Model::State update(const typename Model::State &x) const {
        typename Model::Input u = calculate_input(x);
        typename Model::State d_x = model.get_change_in_state(x, u);

        return d_x;
    }

    void set_reference(const typename Model::State &r) {
        this->R = r;
    }

    typename Model::State get_reference() {
        return R;
    }

    void set_gains(const typename Model::Gains &k) {
        this->K = k;
    }

    typename Model::Gains get_gains() {
        return K;
    }
    
    void set_min_u(typename Model::Input min_u) {
        this->min_u = min_u;
    }
    
    typename Model::Input get_min_u() {
        return min_u;
    }

    void set_max_u(typename Model::Input max_u) {
        this->max_u = max_u;
    }

    typename Model::Input get_max_u() {
        return max_u;
    }
    
};

#endif //JOURNEY_STATESPACECONTROLLER_H
