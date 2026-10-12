all:
	g++ -O2 main.cpp -o code

clean:
	rm -f code

.PHONY: all clean