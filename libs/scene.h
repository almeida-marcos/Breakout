#include "shapes.h"
#ifndef SCENE
#define SCENE

int wid = 5;

class Scene{

	public:

		Rect left, top, right;

		Scene(int w, int h){
			left.SetPos(Point(wid, wid));
			left.SetWidth(wid);
			left.SetHeight(h-2*wid);

			top.SetPos(Point(wid,h-2*wid));
			top.SetWidth(w-2*wid);
			top.SetHeight(wid);
			
			right.SetPos(Point(w-2*wid,wid));
			right.SetWidth(wid);
			right.SetHeight(h-2*wid);
		}

		void Draw(){
			left.Draw();
			top.Draw();
			right.Draw();
		}

};

#endif
