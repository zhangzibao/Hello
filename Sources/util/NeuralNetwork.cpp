//
// Created by 张自爆 on 2019/5/20.
//

#include <Headers/Util.h>
#include "NeuralNetwork.h"

int NeuralNetwork::getINodes() const {
    return iNodes;
}

void NeuralNetwork::setINodes(int iNodes) {
    NeuralNetwork::iNodes = iNodes;
}

int NeuralNetwork::getHNodes() const {
    return hNodes;
}

void NeuralNetwork::setHNodes(int hNodes) {
    NeuralNetwork::hNodes = hNodes;
}

int NeuralNetwork::getONodes() const {
    return oNodes;
}

void NeuralNetwork::setONodes(int oNodes) {
    NeuralNetwork::oNodes = oNodes;
}

int NeuralNetwork::getHLayers() const {
    return hLayers;
}

void NeuralNetwork::setHLayers(int hLayers) {
    NeuralNetwork::hLayers = hLayers;
}

QList<MatrixXd> &NeuralNetwork::getWeights() {
    return weights;
}

void NeuralNetwork::setWeights(const QList<MatrixXd> &weights) {
    NeuralNetwork::weights = weights;
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, int hiddenLayers) {
    iNodes = input;
    hNodes = hidden;
    oNodes = output;
    hLayers = hiddenLayers;
//    初始化权值矩阵
    weights.append(MatrixXd::Random(hNodes, iNodes + 1));
    for (int i = 1; i < hLayers; i++) {
        weights.append(MatrixXd::Random(hNodes, hNodes + 1));
    }
    weights.append(MatrixXd::Random(oNodes, hNodes + 1));
}

MatrixXd NeuralNetwork::output(MatrixXd input_list) {
    MatrixXd inputs = Util::addBias(input_list);
    for (int j = 0; j < hLayers; ++j) {
        MatrixXd hidden_ip = weights[j] * inputs;
        hidden_ip = Util::ReLu(hidden_ip);
        inputs = Util::addBias(hidden_ip);
    }
    MatrixXd output_ip = weights[weights.size() - 1] * inputs;
    output_ip = Util::ReLu(output_ip);
    return output_ip;

}

NeuralNetwork *NeuralNetwork::crossover(NeuralNetwork *partner) {
    NeuralNetwork *child = new NeuralNetwork(iNodes, hNodes, oNodes, hLayers);
    for (int i = 0; i < weights.size(); i++) {
        child->getWeights()[i] = Util::crossover(weights[i], partner->weights[i]);
    }
    return child;
}

NeuralNetwork *NeuralNetwork::clone() {
    NeuralNetwork *clone = new NeuralNetwork(iNodes, hNodes, oNodes, hLayers);
    clone->weights = weights;
    return clone;
}

void NeuralNetwork::mutate(double mr) {
    for (int i = 0; i < weights.size(); i++) {
        // 将矩阵改写为-1和1组成的矩阵
        for (int j = 0; j < weights[i].rows(); ++j) {
            for (int k = 0; k < weights[i].cols(); ++k) {
                double rand = Util::random_double(0, 1);
                if (rand < mr) {
                    weights[i](j, k) += Util::randomGaussian() / 5;

                    if (weights[i](j, k) > 1) {
                        weights[i](j, k) = 1;
                    }
                    if (weights[i](j, k) < -1) {
                        weights[i](j, k) = -1;
                    }
                }

            }
        }
    }
}
// load 即 setWeights
//void NeuralNetwork::load(QList<MatrixXd>) {
//
//}

QList<MatrixXd> NeuralNetwork::pull() {
    QList<MatrixXd> model = weights;
    return model;
}

NeuralNetwork::~NeuralNetwork() {

}

