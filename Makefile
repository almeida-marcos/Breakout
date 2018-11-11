#Makefile
	
all: breakout

breakout: main.cpp libs/shapes.h libs/blocks.h libs/scene.h libs/ball.h libs/game.h libs/pad.h
	g++ main.cpp libs/shapes.h libs/blocks.h libs/scene.h libs/ball.h libs/game.h libs/pad.h -lglut -lGL -lGLU -o breakout
