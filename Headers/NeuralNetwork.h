//
// Created by 张自爆 on 2019/5/20.
//

#ifndef HELLO_NEURALNETWORK_H
#define HELLO_NEURALNETWORK_H

#include <Dense>
#include <QtCore/QList>

using Eigen::MatrixXd;


// 四层神经网络
class NeuralNetwork {
private:
    int iNodes;
    int hNodes;
    int oNodes;
    int hLayers;
    QList<MatrixXd> weights;
public:
    int getINodes() const;

    void setINodes(int iNodes);

    int getHNodes() const;

    void setHNodes(int hNodes);

    int getONodes() const;

    void setONodes(int oNodes);

    int getHLayers() const;

    void setHLayers(int hLayers);

public:

    QList<MatrixXd> &getWeights() ;

    void setWeights(const QList<MatrixXd> &weights);

public:
    NeuralNetwork(int input, int hidden, int output, int hiddenLayers);

    MatrixXd output(MatrixXd input_list);

    NeuralNetwork *crossover(NeuralNetwork *partner);

    NeuralNetwork *clone();

    void mutate(double mr);

    void load(QList<MatrixXd>);

    virtual ~NeuralNetwork();

    QList<MatrixXd> pull();

};


#endif //HELLO_NEURALNETWORK_H
