#include <QtWidgets>
#include <qmainwindow.h>
#include <Headers/Mainwindow.h>
#include <Util.h>
#include <QList>
#include <Headers/GameWorld.h>
#include <Headers/TrainingPanel.h>

using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    // 去掉系统边框
    w.setWindowIcon(QIcon("G:\\C++\\Hello\\Data\\snake.png"));
    QWidget *widget = new QWidget();
    w.setCentralWidget(widget);
    QHBoxLayout *hbLayout = new QHBoxLayout();
    hbLayout->setMargin(0);
    hbLayout->setSpacing(0);
    GameWorld *g = GameWorld::getInstance();
    g->Creation();
    hbLayout->addWidget(g,5);
    TrainingPanel *t = TrainingPanel::getInstance();
    t->resize(400,500);
    t->initialize();
    hbLayout->addWidget(t,4);
    w.centralWidget()->setLayout(hbLayout);
    w.show();
    return app.exec();
}
