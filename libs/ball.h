#include "shapes.h"
#ifndef BALL
#define BALL

class Ball{

	public:
		
		int vx, vy;
		Circle c;

		Ball(){
			c = Circle(0,0,1);
			return;
		}
		
		Ball(int x, int y, int r, int _vx, int _vy){
			c = Circle(x,y,r);
			vx = _vx;
			vy = _vy;
			return;
		}

		void Move(){

			c.cx += vx;
			c.cy += vy;
			return;

		}

};

#endif
