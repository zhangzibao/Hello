//
// Created by 张自爆 on 2019/5/17.
//

#include <minwindef.h>
#include <processthreadsapi.h>
#include "Util.h"
#include <math.h>

Util::Util() {

}

int Util::random_unint(unsigned int min, unsigned int max) {
    {
        DWORD id = GetCurrentThreadId();
        static std::default_random_engine e(id);
        static std::uniform_int_distribution<int> u(min, max);
        return u(e);
    }
}

double Util::random_double(int min, int max) {
    {
        DWORD id = GetCurrentThreadId();
        static std::default_random_engine e(id);
        static std::uniform_real_distribution<double> u(min, max);
        return u(e);
    }
}

double Util::randomGaussian() {
    {
        DWORD id = GetCurrentThreadId();
        static std::default_random_engine e(id);
        static std::normal_distribution<double> dis(0, 1);
        return dis(e);
    }
}

MatrixXd Util::crossover(MatrixXd m, MatrixXd partner) {
    MatrixXd child = m;
    int RandC = floor(random_double(0, m.rows()));
    int RandR = floor(random_double(0, m.cols()));
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            if ((i < RandR) or (i == RandR && j <= RandC)) {
                child(i, j) = m(i, j);
            } else {
                child(i, j) = partner(i, j);
            }
        }
    }
    return child;
}
// 激励函数
MatrixXd Util::ReLu(MatrixXd m) {
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            m(i, j) = m(i, j) > 0 ? m(i, j) : 0;
        }
    }
    return m;
}

MatrixXd Util::addBias(MatrixXd m) {
    MatrixXd n = m;
    n.resize(m.rows() + 1, 1);
    for (int i = 0; i < m.rows(); ++i) {
        n(i, 0) = m(i, 0);
    }
    n(m.rows(), 0) = 1;
    return n;
}
