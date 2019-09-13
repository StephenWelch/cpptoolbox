//
// Created by stephen on 9/5/19.
//

#ifndef JOURNEY_UTIL_H
#define JOURNEY_UTIL_H

#include <Eigen/Core>

using Eigen::Matrix;

// From: https://github.com/frc1678/muan/blob/master/utils/math_utils.h
template <class T>
T cap(T val, T min, T max) {
    T ret = val;
    if (val < min) {
        ret = min;
    } else if (val > max) {
        ret = max;
    }
    return ret;
}

// From: https://github.com/frc1678/muan/blob/master/utils/math_utils.h
template <int A, int B>
Eigen::Matrix<double, A, B> cap_matrix(const Eigen::Matrix<double, A, B>& val,
                                      const Eigen::Matrix<double, A, B>& min,
                                      const Eigen::Matrix<double, A, B>& max) {
    Eigen::Matrix<double, A, B> ret;
    for (uint32_t i = 0; i < A; i++) {
        for (uint32_t j = 0; j < B; j++) {
            ret(i, j) = cap(val(i, j), min(i, j), max(i, j));
        }
    }
    return ret;
}

#endif //JOURNEY_UTIL_H
