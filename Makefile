default:
	g++ -c main.cpp
	g++ main.o map.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

run: default
	./main

clean: default
	rm -rf main.o main
