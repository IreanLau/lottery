CC=g++
FLAG= -g -lpthread -ldl -lrt #-D_DEBUG_ 
BIN=fd
INCLUDE=-I ./ -I/usr/include -L /usr/lib -ljson
HEAD=my_json.h

all:$(BIN)

.PHONY:all
SRC=$(shell ls -R | grep -E '^*.cpp')
OBJ=$(SRC:.cpp=.o)

echo "OBJ1=$(OBJ1)"
$(BIN):$(OBJ)
	$(CC) -o $@ $^ $(INCLUDE) $(FLAG)
%.o:%.cpp	
	 $(CC) -c $< $(INCLUDE) $(FLAG)
.PHONY:clean
clean:
	$(RM)  $(BIN)
	$(RM) *.o
	$(RM) *.txt
