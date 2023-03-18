#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QPainter>
#include <QWidget>
#include <QList>
#include "qlistwidget.h"
#include "qtablewidget.h"
#include "zcpoint.h"
#include <QMouseEvent>

//QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }

//QT_END_NAMESPACE

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    Ui::mainWidget *ui;
public:
//    int width;
//    int height;
    float size;

    int num;
    int maxnum;
    QList<zcpoint*> zcps;
    zcpoint* nowzcp;
    void movezcp(QPoint);
    ///---
    QListWidgetItem *NowItem;
    bool Create_zcp();
    void updatelist();
    void updategraph();


    //-----
    int freemode;//0,1,2,3==free,沿着反射系数圆，电阻圆，电抗圆
    void drawcircle(QPainter& p,circle temp);
    QPoint screenPos;
    bool mouse_clicked_R;
    bool mouse_moved_R;
    bool mouse_clicked_L;
    bool mouse_moved_L;
protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent *event);
private slots:
//    void on_radioButton_clicked(bool checked);
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_clicked();
    void on_radioButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
//    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);


    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton_5_clicked();
};
#endif // MAINWIDGET_H
