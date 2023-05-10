main: main.cpp ASTNode.o
	g++ main.cpp ASTNode.o -o main -g

ASTNode.o: ASTNode.cpp
	g++ ASTNode.cpp -c ASTNode.o