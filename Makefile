all:
	g++ -g -std=c++11 ./src/Main.cpp ./src/core/utils/GameTime.cpp ./src/core/Core.cpp ./src/core/CoreEventHandler.cpp ./src/core/shaders/Shader.cpp ./src/core/entities/Graphic2D.cpp ./src/game/scene/StartScn.cpp ./src/game/characters/Paddle.cpp ./src/game/Game.cpp -o ../main -lGL -lGLU -lGLEW -lSDL2 -lSDL2main
