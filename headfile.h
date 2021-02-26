#ifndef _headfile_h_INCLUDED_
#define _headfile_h_INCLUDED_

//#include "11.h"

class Point {
public:
//members
	int x, y;
public:
//construction/destruction
	Point(int f_x, int f_y) {
		this->x = f_x;
		this->y = f_y;
	}
	Point() {
		x = 0;
		y = 0;
	}
	Point & Point::operator=(const Point &other)
	{
	  this->x=other.x;
	  this->y=other.y;
	  return *this;
	

	}


/*Point & Point :: bool operator!=(const Point &c1,const Point &c2 ){

return!(c1 = c2);

}

Point & Point :: bool operator==(const Point &c1,const Point &c2 ){
 
return!(c1 == c2);

}


//methods

	void Set (const Point &other) {
		this->x = other.x;
		this->y = other.y;
	}
	void Set (const Point *other) {
		this->x = other->x;
		this->y = other->y;
	}
*/
	void Set (int f_x, int f_y) {
		this->x = f_x;
		this->y = f_y;
	}
};
class Line {
private:
//members
	Point m_p1, m_p2;
	int A, B, C;
public:
//construction/destruction
	Line();
	Line(Point &f_p1, Point &f_p2);
    Line(Point *f_p1, Point *f_p2);

//methods
	void SetP(Point &f_p1, Point &f_p2);
	Point getP1() { return m_p1; }
	Point getP2() { return m_p2; }
	int getSign(Point &m_p1);
	double LineLenght();
	int checkCrossed(Line &f_l);
	void Draw(CPaintDC& f_dc);
	

};

void CorrectDraw(CPaintDC& dc,Point *pointCounter,int *size,int *lpi_TWO_pointCounter);
void diagonally(CPaintDC& dc,HWND f_hWnd,int *lpi_TWO_pointCounter, int size,Point *pointCounter);
void additional_function(int *lpi_TWO_pointCounter,int *size ,Point *fpp_pointCounter);
void DrawFigure(CPaintDC& dc,Point *fpp_pointCounter,int *size,int *lpi_TWO_pointCounter);


class Array {
public:

	Point p1,p2;
	float abs;

public:
	Array();
	Array(Point &p1,Point &p2, float &abs);
	Array(Point *p1,Point *p2, float *abs);
Array & Array ::operator=(const Array &other);

};

/*Complex operator=(Complex cm)
    {
        real = cm.real;
        imag = cm.imag;
        return *this; // возвращает объект, который сгенерировал вызов
    }*/

#endif // _headfile_h_INCLUDED_