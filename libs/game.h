#include "blocks.h"
#include "scene.h"
#include "ball.h"
#include "shapes.h"
#include "pad.h"
#ifndef GAME
#define GAME

short BlockColide(Ball ball, Block block){

	//Detect colision

	Point p1, p2;

	p1 = Point(block.pos.x, block.pos.y);
	p2 = Point(block.pos.x+block.width, block.pos.y);
	if(CircleSegInter(ball.c, p1, p2))
		return 1;

	p2 = Point(block.pos.x, block.pos.y+block.height);
	if(CircleSegInter(ball.c, p1, p2))
		return 2;

	p1 = p2;
	p2 = Point(block.pos.x+block.width, block.pos.y+block.height);
	if(CircleSegInter(ball.c, p1, p2))
		return 3;

	p1 = p2;
	p2 = Point(block.pos.x+block.width, block.pos.y);
	if(CircleSegInter(ball.c, p1, p2)){
		return 4;
	}

	return 0;

}

short SceneColide(Ball ball, Scene scene){

	if(BlockColide(ball, Block(scene.left)))
		return 1;
	if(BlockColide(ball, Block(scene.top)))
		return 2;
	if(BlockColide(ball, Block(scene.right)))
		return 3;

	return 0;

}

bool CheckBlockColide(Ball &ball, BlockList blocks){

	BlockListNode *walk = blocks.head;
	while(walk->next != NULL){
		short colide_det = BlockColide(ball, walk->next->block);
		if(colide_det != 0){
			BlockListNode *temp = walk->next;
			walk->next = walk->next->next;
			delete temp;
			if(colide_det == 1 or colide_det == 3)
				ball.vy *= -1;
			else
				ball.vx *= -1;
			return true;
		}
		walk = walk->next;
	}

	return false;

}

void UpdatePad(Pad &pad){
	
	pad.r.pos.x += pad.vx;
	if(pad.r.pos.x < 10)
		pad.r.pos.x = 10;
	if(pad.r.pos.x > 350)
		pad.r.pos.x = 350;

	return;
}

#endif
