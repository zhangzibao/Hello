//
// Created by 张自爆 on 2019/5/17.
//

#ifndef HELLO_UTIL_H
#define HELLO_UTIL_H

#include <Dense>
#include <QtCore/QList>

using Eigen::MatrixXd;

#include <random>

class Util {
public:
    Util();

    static int random_unint(unsigned int min, unsigned int max);

    static double random_double(int min, int max);

    static double randomGaussian();

    static MatrixXd ReLu(MatrixXd m);

    static MatrixXd addBias(MatrixXd m);

    static MatrixXd crossover(MatrixXd m, MatrixXd partner);

//    static double  dis_double( int min,  int max);
};


#endif //HELLO_UTIL_H
