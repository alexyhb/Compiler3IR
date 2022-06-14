OBJ := ./obj
CFLAGS:=-I$(IDIR) -I$(IDIR2) -I$(IDIR3) -I$(IDIR4) -I$(IDIR5) -I$(IDIR6) -I.
SRC := $(shell find ./src -name "*.cpp")
DEPS := $(shell find ./include -name "*.h")
OBJ := $(patsubst ./src/%,./obj/%,$(SRC:.cpp=.o))
INCLUDE := -I include -I. -Iinclude/ast
CXX := g++
compiler: lex.yy.c obj/parser.tab.o  $(OBJ) $(DEPS) 
	g++ -g -w -ocompiler  lex.yy.c -fPIE $(OBJ) $(INCLUDE) -std=c++17 obj/parser.tab.o
obj/%.o:src/%.cpp obj/parser.tab.o 
	$(CXX) -g -w -std=c++17 -fPIE -c $< -o $@ $(INCLUDE)

tree: 
		 dot -Tpdf ast.dot -otree.pdf
st:
		 dot -Tpdf st.dot -ost.pdf
cfg:
		 dot -Tpdf cfg.dot -ocfg.pdf

obj/parser.tab.o: parser.tab.cc
		g++ -g -w -c $< -o $@ -std=c++17 $(INCLUDE)
parser.tab.cc: src/parser.yy
		bison src/parser.yy
lex.yy.c: src/lexer.ll
		flex src/lexer.ll
clean:
		rm -f obj/*; rm parser.tab.cc parser.tab.hh; rm lex.yy.c  parser.tab.o compiler
