clean:
	rm -rf *o imagegenerator

debug:
	g++ -Wall -O3 -DDEBUG imagegenerator.cpp -o imagegenerator `pkg-config --libs --cflags opencv`

all:
	g++ -Wall -Werror -O3 imagegenerator.cpp -o imagegenerator `pkg-config --libs --cflags opencv`
