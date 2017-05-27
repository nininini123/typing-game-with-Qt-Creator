#include "letterpic.h"
#include "randChar.h"

letterPic::letterPic(QChar id,int x,int y,int width,int height,int speed)
//letterPic(QChar id=ID,int x=X,int y=Y,int width=WIDTH,int height=HEIGHT,int speed=SPEED)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->id=id;
    this->speed=speed;
	//////////////////////////////////
    QString* str=new QString(":/img/images/");
    this->pixMap=new QPixmap( str->append(this->id).append(".gif") );
    this->rect=new QRect(x,y,width,height);
    delete str;
}

int letterPic::setX(int x)
{
    this->x=x;
    rect->setX(x);
    return x;
}
int letterPic::setY(int x)
{
     y=x;
    rect->setY(x);
    return x;
}
int letterPic::setWidth(int x)
{
    width=x;
    rect->setWidth(x);
    return x;
}
int letterPic::setHeight(int x)
{
    height=x;
    rect->setHeight(x);
    return x;
}
QChar letterPic::setId(QChar c)
{
    id=c;
    return c;
}
int letterPic::setSpeed(int sp)
{
    speed=sp;
    return sp;
}
int letterPic::getX()
{
    return x;
}
int letterPic::getY()
{
    return y;
}
int letterPic::getWidth()
{
    return width;
}
int letterPic::getHeight()
{
    return height;
}
QChar letterPic::getId()
{
    return id;
}
 int letterPic::getSpeed()
{
    return speed;
}

letterPic::~letterPic()
{
    delete rect;
    delete pixMap;
}
