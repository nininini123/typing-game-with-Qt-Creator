#include "randChar.h"
//////////////////////////////////////////////
QChar randChar()
{
	//srand(time(0));
	int temp=rand()%36;
	if (temp<10)
	{
		return QChar('0'+temp);
	}
	else return QChar( (temp-10)+'a' );
}
