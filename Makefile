all: main.cpp ./src/hello.cpp ./src/goodbye.cpp
	g++ -o "./build/hms" main.cpp ./src/hello.cpp ./src/goodbye.cpp

run:
	./build/hms

clean:
	rm -f ./build/*

clean(win):
	del /f build\*

