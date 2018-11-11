#include "shapes.h"
#ifndef PAD
#define PAD

class Pad{

	public:

		int vx;
		Rect r;

		Pad(){

			r = Rect(180, 15, 40, 10);
			return;
		}

		void Draw(){
			r.Draw();
			return;
		}

};

#endif
