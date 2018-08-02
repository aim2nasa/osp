CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++11

TARGET = HelloWorldPub
SRCS = HelloWorldPub.cpp
OBJS = ${SRCS:.cpp=.o}
IDL = HelloWorldData.idl
IDLGD = gen

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
INCLUDES = -I$(shell pwd)/$(IDLGD) $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp 

LIBS = -L$(OSPL_HOME)/lib -ldcpsisocpp -L$(shell pwd) -lHelloWorldData

all : pre-build main-build

pre-build:
	@echo PRE
	@cd gen;make

post-build:
	@echo POST

main-build: $(TARGET)

clean:
	@echo $@...
	@cd gen;make clean
	rm -rf *.o *.gch *.so $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -o $@ $^ $(LIBS)

%.o : $(IDL) %.cpp
	@echo $@:$^...
	$(CXX) -c $(word 2,$^) $(CXXFLAGS) $(INCLUDES)

idl:
	idlpp -l isocpp $(IDL) -d $(IDLGD)
