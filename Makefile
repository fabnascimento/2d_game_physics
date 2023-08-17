build:
	g++ -std=c++17 -Wall ./src/*.cpp ./src/Physics/*.cpp -lSDL2 -lSDL_image -lSDL2_gfx -o app

run:
	./app

clear:
	rm app
