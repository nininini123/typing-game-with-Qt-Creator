#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isOver=false;
    isStopped=false;
    QRect rect=this->geometry();
    rect.setWidth(1000);
    rect.setHeight(650);
    rect.setY(30);
    rect.setX(30);
    this->setGeometry(rect);
    //this->repaint();
    //this->update();
    for(int i=0;i<3;i++)
    {
        letterpic[i]=NULL;
    }
    initGame();//   start point should be changed
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    // Img1=new QPixmap(":/img/images/0.gif");///记得delete
    // imgRect1=new QRect(0,80,width,height);///记得delete
    // QPainter painter(this);
    // painter.drawPixmap(*imgRect1,*Img1);
    QPainter painter(this);
    for (int i=0;i<3;++i)
    {
        if (letterpic[i]!=NULL)
            painter.drawPixmap( *(letterpic[i]->rect),*(letterpic[i]->pixMap) );
    }
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int KeyPressed= event->key();
    switch (KeyPressed)
    {
    case Qt::Key_Space:
        isStopped=!isStopped;
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
    default:if (!isStopped)
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
    update();
}

void MainWindow::on_actionexit_triggered()
{
    close();
}
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
