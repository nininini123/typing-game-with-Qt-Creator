#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isOver=false;
    isStopped=false;
    /*********
     * 将当前窗口设为1000*650
     * 并将其作为画布
     * ***********/
    QRect rect=this->geometry();
    rect.setWidth(1000);
    rect.setHeight(650);
    rect.setY(30);
    rect.setX(30);
    this->setGeometry(rect);
    for(int i=0;i<3;i++)
    {
        letterpic[i]=NULL;
    }
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    /*******
     * 若图片非空则画出来
     ********/
    QPainter painter(this);
    for (int i=0;i<3;++i)
    {
        if (letterpic[i]!=NULL)
            painter.drawPixmap( *(letterpic[i]->rect),*(letterpic[i]->pixMap) );
    }
    /**********
     * 游戏结束显示的图片
     * ********/
    if (isOver)
    {
        QPixmap *endPic=new QPixmap(":/img/images/gameover.png");
        painter.drawPixmap(this->geometry(),*endPic);
        delete endPic;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //repaint();
}

/*********
 * 空格键：暂停<->继续
 * 按到对应图片的键图片删除
 * 游戏结束时F1重来 ESC关闭
 * ******/
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int KeyPressed= event->key();
    switch (KeyPressed)
    {
    case Qt::Key_Space:
        isStopped=!isStopped;
        break;
    case Qt::Key_F2:
        on_actionhelp_triggered();
        break;
    case Qt::Key_F1:
        if(isOver)
        {
            for (int i=0;i<3;i++)
            {
                if ( letterpic[i]!=NULL)
                {
                    delete letterpic[i];
                    letterpic[i]=NULL;
                    letterpic[i]= new letterPic( randChar(), X, Y+190*i );
                }
            }
            isOver=false;
        }
        break;
    case Qt::Key_Escape:
        if(isOver)
        {
            close();
        }
        break;
    default:if (!isStopped && !isOver)
    {
        int temp = KeyPressed - Qt::Key_0;
        if( (temp >= 0 ) && (temp <= 9) )
        {
            KeyPressed = '0' + temp;
        }
        else
        {
            temp = KeyPressed - Qt::Key_A;
            if (temp>=0 && temp<=25)
            {
                KeyPressed = 'a' + temp;
            }
        }
        for (int i=0;i<3;i++)
        {
            if ( letterpic[i]->getId()==QChar(KeyPressed) )
            {
                delete letterpic[i];
                letterpic[i]=NULL;
            }
        }
    }
        break;
    }
    run();
    //update会重绘窗口
    update();
}

//关闭窗口
void MainWindow::on_actionexit_triggered()
{
    close();
}

//游戏初始化
void MainWindow::initGame()
{
    //letterPic* letterpic[3];

	srand(time(0));
	for (int i = 0; i < 3; ++i)
	{
        if( NULL != letterpic[i])
        {
            //delete letterpic[i];
            letterpic[i]=NULL;
        }
        letterpic[i]= new letterPic( randChar(), X, Y+190*i );
		//imgNum[i]=randChar();
	}
    gameTimer = new QTimer(this);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(run()));      //close()));//
    gameTimer->start(INTERVAL);//   INTERVAL=300ms
}

/**********
 * 若图片为空则随机产生一张开始
 * 非空的图片横坐标加3*speed像素，即右移
 **********/
void MainWindow::run()
{
    if(!isOver && !isStopped)
    {
        for(int i=0;i<3;i++)
        {
            if(letterpic[i]==NULL)
            {
                letterpic[i]= new letterPic( randChar(), X, Y+190*i );///////
            }
            else
            {
                letterpic[i]->setX(letterpic[i]->getX()+letterpic[i]->getSpeed()*3);
                if(letterpic[i]->getX()>920)
                {
                    isOver=true;
                }
            }
        }
        repaint();
    }
        //update();
}

void MainWindow::on_actionhelp_triggered()
{
    QMessageBox *msgHelp = new QMessageBox(QMessageBox::NoIcon,"welcome","1．	程序启动时在画面左边随机产生字母，以一定的速度自左向右移动\n2．	使用键盘敲击对应的字母即消失，并重新在画面最左端随机产生一个字母 \n3．	当字母由画面最左端移动至最右端，没有被键盘敲击到，则游戏结束\n4．	运行状态下按下空格可暂停，暂停状态下按一次空格键即继续游戏\n5．	一局后结束按F1继续游戏，按ESC即可退出\n6．	按F2显示帮助信息");
    msgHelp->show();
    //delete msgHelp;
}
