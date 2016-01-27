clean:
	rm -rf *o imagegenerator

debug:
	g++ -std=c++11 -Wall -O3 -DDEBUG imagegenerator.cpp -o imagegenerator `pkg-config --libs --cflags opencv`

all:
	g++ -std=c++11 -Wall -Werror -O3 imagegenerator.cpp -o imagegenerator `pkg-config --libs --cflags opencv`
