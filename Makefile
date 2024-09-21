all:
	g++ -c src/*.cpp -std=c++14 -g -Wall -I include -I A:/Development/SDL2-win64/include && g++ *.o -o bin/debug/main -L A:/Development/SDL2-win64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/debug/main"
