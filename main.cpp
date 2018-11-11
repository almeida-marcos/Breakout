#include "libs/blocks.h"
#include "libs/scene.h"
#include "libs/game.h"

Scene scene(400,600);
Pad pad;
int my_time = 10;
bool pause = true;

BlockList blocks;
Ball ball(200, 30, 5, 3, 3);
void FillBlockList(){

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 8; j++){
			Block b(45+j*40, 560-i*15, 30,10,i*8+j);
			blocks.AddBlock(b);
		}
	}

	return;

}

void Display(void){

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	scene.Draw();
	blocks.DrawBlocks();
	
	pad.Draw();
	ball.c.Draw();

	glutSwapBuffers();
}

void Update(int value){

	if(!pause){


		int scene_colide = SceneColide(ball, scene);
		if(scene_colide == 1){
			ball.vx *= -1;
			ball.c.cx = max(ball.c.cx, 18);
		}
		else if(scene_colide == 2){
			ball.vy *= -1;
			ball.c.cy = min(ball.c.cy, 582);
		}
		else if(scene_colide == 3){
			ball.vx *= -1;
			ball.c.cx = min(ball.c.cx, 382);
		}
		
		UpdatePad(pad);
		if(BlockColide(ball, Block(pad.r))){
			ball.vy *= -1;
			ball.c.cy = max(ball.c.cy,30);
		}

		CheckBlockColide(ball, blocks);
		if(ball.c.cy < 10){
			
			pause = true;
			ball.c.cx = 200;
			ball.c.cy = 30;
			if(ball.vy < 0)
				ball.vy *= -1;
			pad.r.pos.x = 180;
			pad.r.pos.y = 15;

		}

		ball.Move();
	}

	glutPostRedisplay();
	glutTimerFunc(my_time,Update,1);

	return;

}
	
	
void Reshape(int w, int h){

	if(w < 400 || h < 600){
		glutReshapeWindow(400,600);
	}

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-(w-400)/2, 400 + (w-400)/2, 0.0, h, -1, 1);
}

void SpecialKey(int key, int x, int y){

	pause = !pause;

	return;

}

void KeyboardHandle(unsigned char key, int x, int y){

	pause = !pause;

	return;
}

void MouseHandle(int x, int y){

	pad.vx = (x - 200)/25;
	return;

}
 
int main(int argc, char** argv){

	FillBlockList();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Breakout");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(KeyboardHandle);
	glutPassiveMotionFunc(MouseHandle);
	glutTimerFunc(33,Update,1);
    glutMainLoop();
    return 0;
}
