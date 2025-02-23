TARGET = cminus
FLEX = flex
BISON = bison
CC = gcc

LEX_FILE = cminus.l
YACC_FILE = cminus.y
LEX_C = lex.yy.c
YACC_C = cminus.tab.c
YACC_H = cminus.tab.h

CFLAGS = -Wall
LDFLAGS = -lfl

all: $(TARGET)

$(YACC_H) $(YACC_C): $(YACC_FILE)
	$(BISON) -d $(YACC_FILE)

$(LEX_C): $(LEX_FILE) $(YACC_H)
	$(FLEX) $(LEX_FILE)

$(TARGET): $(LEX_C) $(YACC_C) symboltable.o ast.o
	$(CC) $(CFLAGS) -o $(TARGET) $(LEX_C) $(YACC_C) symboltable.o ast.o $(LDFLAGS)

symboltable.o: symboltable.c symboltable.h
	$(CC) $(CFLAGS) -c symboltable.c

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

clean:
	rm -f $(TARGET) $(LEX_C) $(YACC_C) $(YACC_H) *.o

.PHONY: all clean
