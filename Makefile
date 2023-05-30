main: main.cpp ASTNode.o Parser.o Ir.o
	g++ main.cpp ASTNode.o Parser.o Ir.o -o main -g

ASTNode.o: ASTNode.cpp
	g++ ASTNode.cpp -c ASTNode.o

Parser.o: Parser.cpp
	g++ Parser.cpp -c Parser.o

Ir.o: Ir.cpp
	g++ Ir.cpp -c Ir.o

clean:
	rm main
	rm ASTNode.o
	rm Parser.o
	rm Ir.o