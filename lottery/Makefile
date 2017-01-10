ROOT_PATH=$(shell pwd)
CC=g++
FLAG = -ljson_linux-gcc-4.4.7_libmt -ljsoncpp -lpthread -ldl -lrt -g
LDFLAG=#-static
BIN=fd
COMM=$(ROOT_PATH)/common
REDIS=$(ROOT_PATH)/redis/redisCPP

INCLUDE= -I $(COMM)  -I/usr/include -I/usr/include/hiredis -I $(REDIS)  -I/home/lau/boost_1_55_0/sdk/include/boost
ADDSRC=/home/lau/redis-cplusplus-client-master/anet.c
LIB_PATH= -L $(ROOT_PATH)/lib -L/home/lau/boost_1_55_0/sdk/lib  -lredisclient  -L/usr/lib -lboost_thread  
LINK_LIB= #  -lhiredis

all:$(BIN)
.PHONY:all
#SRC=$(shell ls -R | grep -E '^*.cpp')
SRC=$(shell ls -R | grep -E '^*.cpp' | grep -v 'sql_connect.cpp' | grep -v 'libjsoncpp.a')
OBJ=$(SRC:.cpp=.o)
$(BIN):$(OBJ)
	@$(CC) -o $@ $^ $(ADDSRC) $(INCLUDE) $(LIB_PATH) $(LDFLAG)  $(LINK_LIB) $(FLAG)
	@echo "Linking [ $^ ] to [ $@ ] ... done"
%.o:$(COMM)/%.cpp
	@$(CC) -c $<  $(INCLUDE)  $(LIB_PATH) $(LDFLAG) $(LINK_LIB) $(FLAG)
	@echo "Compiling [ $< ] to [ $@ ] ... done"
%.o:$(REDIS)/%.cpp
	@$(CC) -c $<   $(ADDSRC) $(INCLUDE)  $(LIB_PATH) $(LDFLAG) $(LINK_LIB) $(FLAG)
	@echo "Compiling [ $< ] to [ $@ ] ... done"
%.o:%.cpp
	@$(CC) -c $<  $(INCLUDE)  $(LIB_PATH) $(LDFLAG) $(LINK_LIB) $(FLAG)
	@echo "Compiling [ $< ] to [ $@ ] ... done"

.PHONY:clean
clean:
	$(RM) $(BIN)
	$(RM) *.o
	$(RM) *.txt
	$(RM) *.aof
	$(RM) *.rdb
	$(RM) nodes-*.conf
