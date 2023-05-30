main: main.cpp ASTNode.o Parser.o
	g++ main.cpp ASTNode.o Parser.o -o main -g

ASTNode.o: ASTNode.cpp
	g++ ASTNode.cpp -c ASTNode.o

Parser.o: Parser.cpp
	g++ Parser.cpp -c Parser.o

clean:
	rm main