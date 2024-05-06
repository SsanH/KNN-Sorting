all: client server

client: clientMain.cpp
	g++ -std=c++11 -o client ./inputOutput/*.cpp ./clientFolder/*.cpp clientMain.cpp ./Commands/Command.cpp ./Commands/ClientCommands/*.cpp -lpthread

server: serverMain.cpp
	g++ -std=c++11 -o server ./inputOutput/*.cpp ./Calc/Metrics/*.cpp ./Calc/*.cpp ./serverFolder/*.cpp ./Commands/Command.cpp serverMain.cpp ./Commands/ServerCommands/*.cpp -lpthread

clean:
	rm -rf *.o