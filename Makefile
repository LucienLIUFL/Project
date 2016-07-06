DIR_SRC = ./src
DIR_OBJ = ./obj
DIR_BIN = ./bin
DIR_INC = ./inc

COMPILER = g++ -std=c++11
GC_FRAMEWORK = -framework OpenGL -framework GLUT -framework Foundation
COMPILER_OP = -g -Wall -Wno-deprecated


SRC = ${wildcard ${DIR_SRC}/*.cpp}
OBJ = ${patsubst %.cpp, ${DIR_OBJ}/%.o, ${notdir ${SRC}}}
BIN = ${DIR_BIN}/Main

${BIN}: ${OBJ}
	${COMPILER} ${COMPILER_OP} ${GC_FRAMEWORK} ${OBJ} -o $@
${DIR_OBJ}/%.o: ${DIR_SRC}/%.cpp
	${COMPILER} ${COMPILER_OP} -c $< -o $@
clean:
	rm -rf ${DIR_OBJ}/* *.dSYM ${BIN}
config:
	touch README.md
	mkdir bin src obj pys doc
	touch ./src/Main.cpp
	@echo "#!/usr/env python" > ./pys/Create.py
	@echo "#-*- coding: utf8 -*-" >> ./pys/Create.py
	@echo "import os" >> ./pys/Create.py
	@echo "import sys" >> ./pys/Create.py
	@echo "def main():" >> ./pys/Create.py
	@echo "    filename = sys.argv[1];" >> ./pys/Create.py
	@echo "    with open(\"src/\" + filename + \".h\", \"w\") as outfile:" >> ./pys/Create.py
	@echo "        outfile.write(\"#ifndef \" + filename.upper() + \"_H_\" + \"\\\n\");" >> ./pys/Create.py
	@echo "        outfile.write(\"#define \" + filename.upper() + \"_H_\" + \"\\\n\\\n\\\n\");" >> ./pys/Create.py
	@echo "        outfile.write(\"class \" + filename + \" {\" + \"\\\npublic:\\\n\\\nprivate:\\\n\\\n};\\\n\\\n\");" >> ./pys/Create.py
	@echo "        outfile.write(\"#endif\\\n\\\n\\\n\");" >> ./pys/Create.py
	@echo "    with open(\"src/\" + filename + \".cpp\", \"w\") as outfile:">> ./pys/Create.py
	@echo "        outfile.write(\"#include \\\"\" + filename + \".h\\\"\" + \"\\\n\");">> ./pys/Create.py
	@echo "    with open(\"doc/\" + filename + \".md\", \"w\") as outfile:">> ./pys/Create.py
	@echo "        outfile.write(\"# \" + filename + \"\\\n\");">> ./pys/Create.py
	@echo "if __name__ == '__main__':">> ./pys/Create.py
	@echo "    main()">> ./pys/Create.py
	@echo "import os"> ./pys/Remove.py
	@echo "import sys">> ./pys/Remove.py
	@echo "filename = sys.argv[1];">> ./pys/Remove.py
	@echo "os.remove(\"src/\" + filename + \".h\");">> ./pys/Remove.py
	@echo "os.remove(\"src/\" + filename + \".cpp\");">> ./pys/Remove.py
