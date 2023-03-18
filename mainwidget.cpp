#include "mainwidget.h"
#include "ui_mainwidget.h"


mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setWindowTitle("smithCircle");
    size = 200;


    num=0;
    maxnum = 20;
    Create_zcp();
//    nowzcp = &zcps[0];

    freemode = 0;
}

mainWidget::~mainWidget()
{
    delete ui;
}

bool mainWidget::Create_zcp(){
    if(num>=maxnum){
        qDebug()<<">max character";
        return false;
    }
    QListWidgetItem * item = new QListWidgetItem;
    zcpoint* temp = new zcpoint;
    item->setText(temp->Tostring(0));
    item->setData(Qt::UserRole,QVariant::fromValue((void *) temp));
    ui->listWidget->addItem(item);
    NowItem = item;
    nowzcp = temp;
    zcps.append(temp);

    num++;

    return true;
}
void mainWidget::drawcircle(QPainter& p,circle temp){

    int realx = size*(temp.x+1);
    int realy = size*(1-temp.y);
    int realr = size* temp.r;
    p.drawEllipse(QPoint(realx,realy),realr,realr);
}

void mainWidget::movezcp(QPoint p1){
//    double tempx = ;
//    double tempy = ;
    QPointF temp(p1.x()-size,size-p1.y());
    QPointF next = temp/size;
    if((next-QPoint(1,0)).manhattanLength()<0.001){
        next.setX(0.999);//防止0
    }
//    if(tempx+)
    switch (freemode) {
    case 0:{

        break;
    }
    case 1:{
        next = nowzcp->Cref.getnear(next);
        break;
    }
    case 2:{
        next = nowzcp->Cr.getnear(next);
        break;
    }
    case 3:{
        next = nowzcp->Cx.getnear(next);
        break;
    }
    default:
        break;
    }
    if((next-QPoint(1,0)).manhattanLength()<0.001){
        next.setX(0.999);//防止0
    }
    nowzcp->reflect.setreal(next.rx());
    nowzcp->reflect.setimag(next.ry());

    nowzcp->updatebyref();

    updategraph();
}
void mainWidget::updategraph(){

    ui->label->setText( nowzcp->Tostring(0));
    ui->label_2->setText(nowzcp->Tostring(1));
    ui->label_13->setText(QString::number(180*nowzcp->ang/3.141592));
    ui->label_14->setText(QString::number( (1-nowzcp->ang/3.141592)/4)) ;
    ui->label_18->setText(QString::number(nowzcp->r));
    ui->label_19->setText(QString::number(nowzcp->ro));

    update();
    NowItem->setText(nowzcp->Tostring());
}
void mainWidget::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    QPainter p(this);
//    p.setBrush()//不要
    zcpoint* temp ;
    drawcircle(p,circle(0,0,1));

    //drawcircle(p,circle(0,0,0.5));
    int trans = 105;
    for(int i=0;i<num;i++){
        temp = zcps[i];
        if(temp->ifdrawline){
            if(temp == nowzcp){
                trans = 255;
            }
            else{
                trans = 55;
            }
            p.setPen(QPen(QColor(204,202,2,trans)));
            drawcircle(p,temp->Cr);
            p.setPen(QPen(QColor(20,22,202,trans)));
            drawcircle(p,temp->Cx);
            p.setPen(QPen(QColor(200,22,102,trans)));
            drawcircle(p,temp->Cref);
            p.setPen(QPen(QColor(255,0,133,trans)));
            drawcircle(p,circle(temp->x,temp->y,0.01));
        }
    }
}

void mainWidget::mousePressEvent(QMouseEvent* event){

//    if(event->button()==Qt::RightButton){
//        screenPos = event->globalPosition().toPoint();
//        mouse_clicked_R = true;
//        mouse_moved_R = false;
//    }
    if(event->button()==Qt::LeftButton){
        mouse_clicked_L = true;
//        screenPos = event->globalPosition().toPoint();

        movezcp(event->pos());

        mouse_moved_L = false;
    }

}
void mainWidget::mouseMoveEvent(QMouseEvent* event){
    if(mouse_clicked_L){
        QPoint tPos = event->globalPosition().toPoint()-screenPos;
//        screenPos = event->globalPosition().toPoint();
        mouse_moved_L = true;

        movezcp(event->pos());
        nowzcp->updatebyref();
        nowzcp->update();

        updategraph();

    }

}
void mainWidget::mouseReleaseEvent(QMouseEvent* event){
    Q_UNUSED(event);

}
void mainWidget::resizeEvent(QResizeEvent *event){
    size = 200*event->size().height()/420.0;

}


///////////////
void mainWidget::on_radioButton_clicked()
{
    freemode = 1;
}

void mainWidget::on_radioButton_2_clicked()
{
    freemode = 2;
}


void mainWidget::on_radioButton_3_clicked()
{
    freemode = 3;
}

void mainWidget::on_radioButton_4_clicked()
{
    //free
    freemode = 0;
}


void mainWidget::on_pushButton_clicked()
{
    //set reflect
    nowzcp->reflect.setreal(ui->textEdit->toPlainText().toDouble());
    nowzcp->reflect.setimag(ui->textEdit_2->toPlainText().toDouble());

    nowzcp->updatebyref();
    nowzcp->update();
    updategraph();
}


void mainWidget::on_pushButton_2_clicked()
{
    nowzcp->zl.setreal(ui->textEdit_3->toPlainText().toDouble());
    nowzcp->zl.setimag(ui->textEdit_4->toPlainText().toDouble());

    nowzcp->updatebyz();
    nowzcp->update();
    updategraph();

}


void mainWidget::on_pushButton_3_clicked()
{
    //new
    Create_zcp();
    updategraph();
}


void mainWidget::on_pushButton_4_clicked()
{

    //delete
    if(num>1){
        ui->listWidget->removeItemWidget(NowItem);
        delete NowItem;
        num--;
        NowItem =  ui->listWidget->item(num-1);
        zcps.removeOne(nowzcp);

        nowzcp = (zcpoint*)NowItem->data(Qt::UserRole).value<void *>();
        updategraph();
    }
}



void mainWidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}


void mainWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    NowItem = item;
    ui->label_13->setText(item->text());
    nowzcp = (zcpoint*)NowItem->data(Qt::UserRole).value<void *>();
    updategraph();
}

