all: nyanCompile

nyanCompile: NYANDriver.o UserInterface.o UserProfile.o List.o SubscribedAccount.o DescribedAccount.o StandardAccount.o Account.o Reader.o Writer.o Cryptography.o Generator.o
	g++ NYANDriver.o UserInterface.o UserProfile.o List.o SubscribedAccount.o DescribedAccount.o StandardAccount.o Account.o Reader.o Writer.o Cryptography.o Generator.o -o NYAN
	
NYANDriver.o: ./src/NYANDriver.cpp 
	g++ -c ./src/NYANDriver.cpp
	
UserInterface.o: ./src/UserInterface.cpp
	g++ -c ./src/UserInterface.cpp
	
UserProfile.o: ./src/UserProfile.cpp
	g++ -c ./src/UserProfile.cpp
	
List.o: ./src/List.cpp
	g++ -c ./src/List.cpp

SubscribedAccount.o: ./src/SubscribedAccount.cpp
	g++ -c ./src/SubscribedAccount.cpp

DescribedAccount.o: ./src/DescribedAccount.cpp
	g++ -c ./src/DescribedAccount.cpp

StandardAccount.o: ./src/StandardAccount.cpp
	g++ -c ./src/StandardAccount.cpp

Account.o: ./src/Account.cpp
	g++ -c ./src/Account.cpp
	
Reader.o: ./src/Reader.cpp
	g++ -c ./src/Reader.cpp
	
Writer.o: ./src/Writer.cpp
	g++ -c ./src/Writer.cpp
	
Cryptography.o: ./src/Cryptography.cpp
	g++ -c ./src/Cryptography.cpp

Generator.o: ./src/Generator.cpp
	g++ -c ./src/Generator.cpp
	
clean:
	rm -rf *.o NYAN
	
	