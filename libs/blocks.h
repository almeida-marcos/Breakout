#include <iostream>
#include "shapes.h"
#ifndef BLOCKS
#define BLOCKS

using namespace std;

class Block : public Rect{

	public:

		int id;
		Block() : Rect(0,0,0,0){
			id = -1;
		}
		
		Block(int x, int y, int w, int h, int _id) : Rect(x,y,w,h){
			id = _id;
		}

		Block(Rect rect) : Rect(rect){
			id = -1;
		}

};

class BlockListNode{
	
	public:
		BlockListNode *next;
		Block block;

		BlockListNode(){
			next = NULL;
		}

};

class BlockList{

	public:
		BlockListNode *head;
		BlockListNode *end;

		BlockList(){
			
			head = new BlockListNode();
			end = head;

		}

		void AddBlock(Block b){

			end->next = new BlockListNode();
			end->next->block = b;
			end = end->next;
		}

		void DeleteBlock(int id){

			BlockListNode *walk = head;
			while(walk->next != NULL){
				if(walk->next->block.id == id){
					walk->next = walk->next->next;
					return;
				}
				walk = walk->next;
			}

			cerr << "Error! ID not found in list\n";
			return;
		}

		void DrawBlocks(){
			
			BlockListNode *walk = head;
			while(walk->next != NULL){
				walk->next->block.Draw();
				walk = walk->next;
			}
		}

};


#endif
