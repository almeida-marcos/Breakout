#include <GL/glut.h>
#include <cmath>
#ifndef SHAPES
#define SHAPES

#define PI 3.14159265

class Point{

	public:
		int x;
		int y;

		Point(int _x, int _y){
			x = _x;
			y = _y;
		}

		Point(){
			x = 0;
			y = 0;
		}
};

class Rect{

	public:

		Point pos;
		int width;
		int height;

		Rect(int x, int y, int w, int h){
			pos = Point(x,y);
			width = w;
			height = h;
		}

		Rect(){
			width = 0;
			height = 0;
		}

		void SetPos(Point p){
			pos = p;
		}

		void SetWidth(int w){
			width = w;
		}

		void SetHeight(int h){
			height = h;
		}

		void Draw(){
			glBegin(GL_POLYGON);
				glVertex2i(pos.x,pos.y);
				glVertex2i(pos.x+width,pos.y);
				glVertex2i(pos.x+width,pos.y+height);
				glVertex2i(pos.x,pos.y+height);
			glEnd();
		}

};

class Circle{

	public:

		int cx, cy, r;

		Circle(){
			cx = 0;
			cy = 0;
			r = 1;
		}

		Circle(int _cx, int _cy, int _r){
			cx = _cx;
			cy = _cy;
			r = _r;
		}

		void Draw(){

			glBegin(GL_POLYGON);
			for(int i = 0; i <= 64; i++){
				glVertex2i(cx + r*cos(2*i*PI/64.0), cy+r*sin(2*i*PI/64.0));
			}
			glEnd();

			return;

		}

};

int SquareDist(Point p1, Point p2){
	
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	return (dx*dx + dy*dy);

}

bool CircleSegInter(Circle c, Point p1, Point p2){

	//Compute if there is an intersection between the circle c and the line segment connecting p1 and p2

	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;

	double t = c.cx*dx + c.cy*dy - p1.x*dx - p1.y*dy;
	t /= (dx*dx + dy*dy);

	if(t < 0 or t > 1)
		return false;

	int closest_x = (int)round(p1.x + (p2.x-p1.x)*t);
	int closest_y = (int)round(p1.y + (p2.y-p1.y)*t);
	Point closest(closest_x, closest_y);
	Point circle_center(c.cx, c.cy);
	return (SquareDist(closest, circle_center) < c.r*c.r);
	
}
					
#endif
