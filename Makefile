run:
	rm -rf bin
	mkdir bin
	g++ -O3 main.cpp -o bin/main
	bin/main

test:
	rm -rf bin
	mkdir bin
	g++ -O3 tests/main.cpp -o bin/test -lgtest
	bin/test