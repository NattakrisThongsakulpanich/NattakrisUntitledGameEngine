build:
	g++ ./tester/BaseAppRTE_tester.cpp ./core/Application.cpp ./platform/platformSDL.cpp -o ./bin/test.exe -I./dependencies/include -L./dependencies/lib -lSDL3
