////
//// Created by 张自爆 on 2019/5/19.
////
//
//
//#ifndef _DB_POOL_H_
//#define _BD_POOL_H_
//
//#include <QtWidgets>
//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlQuery>
//#include <QtWidgets/QMessageBox>
//
//using namespace std;
//QSqlDatabase db;
//
//bool createConnection() {
//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("zhangzibao.xyz");
//    db.setPort(3306);
//    db.setDatabaseName("chat");       //这里输入你的数据库名
//    db.setUserName("root");
//    db.setPassword("root");   //这里输入你的密码
//    //支持中文
//    bool ok = db.open();
//    if (!ok) {
//        QMessageBox::critical(0, QObject::tr("无法打开数据库"),
//                              "无法创建数据库连接！ ", QMessageBox::Cancel);
//        return false;
//    } else {
//        QMessageBox::information(0, QObject::tr("Tips"), QObject::tr(" 连接数据库成功！！！ "));
//        return true;
//    }
//}
//
//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    // 使数据库支持中文
//    if (createConnection()) {
//        QSqlQuery query(db);
//        db.exec("alter table Student convert to character set utf8");
//        query.exec("select * from messages");
//        while (query.next())//遍历数据表nengxin.student每一行，从第0行到最后一行
//        {
//            quint32 id = query.value(0).toInt();//value(0)，0代表第几列的值。在该例中，代表id=3的行，第0列
//            QString user_id = query.value(1).toString();
//            QString friend_id = query.value(2).toString();
//            QString message_content = query.value(3).toString();
//            QString add_time = query.value(4).toString();
//            QString is_receive = query.value(5).toString();
//            qDebug() << id << user_id << friend_id << message_content
//                     << is_receive;//输出MySql数据库表mqtt.a10001中id=3的MAC和state
//
//        }
//        return app.exec();
//    }
//}
//
//#endif