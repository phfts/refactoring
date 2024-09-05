run:
	rm -rf bin
	mkdir bin
	g++ -O3 main.cpp -o bin/main
	bin/main