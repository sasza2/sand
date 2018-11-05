ifeq ($(DEBUG),)
DEBUG := 0
endif

VERSION = -g -std=c++11 -Wall -D "DEBUG=$(DEBUG)"

all:
	mkdir -p build/dev
	mkdir -p build/prod
	g++ -c vm/*.cpp $(VERSION)
	g++ -c vm/class/*.cpp $(VERSION)
	g++ -c vm/instruction/types/arthmetic/*.cpp $(VERSION)
	g++ -c vm/instruction/types/call/*.cpp $(VERSION)
	g++ -c vm/instruction/types/catch/*.cpp $(VERSION)
	g++ -c vm/instruction/types/comparision/*.cpp $(VERSION)
	g++ -c vm/instruction/types/conditions/*.cpp $(VERSION)
	g++ -c vm/instruction/types/for/*.cpp $(VERSION)
	g++ -c vm/instruction/types/push/*.cpp $(VERSION)
	g++ -c vm/instruction/types/while/*.cpp $(VERSION)
	g++ -c vm/instruction/types/*.cpp $(VERSION)
	g++ -c vm/instruction/*.cpp $(VERSION)
	g++ -c vm/method/*.cpp $(VERSION)
	g++ -c vm/mutex/*.cpp $(VERSION)
	g++ -c vm/trace/*.cpp $(VERSION)
	g++ -c vm/var/factory/*.cpp $(VERSION)
	g++ -c vm/var/*.cpp $(VERSION)
	g++ -c *.cpp $(VERSION)
	rm -rf build/dev/*.o
	rm -rf build/prod/*.o
	cp *.o build/dev
	cp *.o build/prod
	rm *.o
	rm -rf build/prod/Test.o
	rm -rf build/dev/App.o
	g++ -o test build/dev/*.o $(VERSION);
	g++ -o app build/prod/*.o $(VERSION);
	rm -rf build/prod/*
	rm -rf build/dev/*
