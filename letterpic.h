#ifndef _LETTER_PIC_
#define _LETTER_PIC_

#include <QRect>
#include <QPixmap>
#include <QChar>
#include <QString>

#define SPEED 10
#define WIDTH 70
#define HEIGHT 70
#define X 0
#define Y 80
#define ID '0'
class letterPic
{
	public:
        //letterPic(QChar id,int x,int y,int width,int height,int speed);
		~letterPic();
        letterPic(QChar _id=ID,int _x=X,int _y=Y,int _width=WIDTH,int _height=HEIGHT,int _speed=SPEED);
	private:
        int x,y,height,width;
		int speed;
		QChar id;/////////////
	public:
        QPixmap *pixMap;
        QRect *rect;
		int setX(int x);
		int setY(int x);
		int setWidth(int x);
		int setHeight(int x);
		int setSpeed(int x);
		QChar setId(QChar c);
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		int getSpeed();
		QChar getId();
        //void destroy();
};
#endif
