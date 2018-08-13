CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++11

COMMON_SRC = util.cpp
TARGET_PUB = pub
SRCS_PUB = pub.cpp ${COMMON_SRC}
OBJS_PUB = ${SRCS_PUB:.cpp=.o}

TARGET_SUB = sub
SRCS_SUB = sub.cpp ${COMMON_SRC}
OBJS_SUB = ${SRCS_SUB:.cpp=.o}

IDL = bcast.idl
IDLGD = gen

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
INCLUDES = $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp 

LIBS = -L$(OSPL_HOME)/lib -ldcpsisocpp -L$(shell pwd) -lbcast

all : pre-build main-build

pre-build:
	@echo PRE
	@cd gen;make

post-build:
	@echo POST

main-build: $(TARGET_PUB) $(TARGET_SUB)

clean:
	@echo $@...
	@cd gen;make clean
	rm -rf *.o *.gch *.so *.log $(TARGET_PUB) $(TARGET_SUB)

$(TARGET_PUB) : $(OBJS_PUB)
	@echo $@:$^...
	$(CXX) -o $@ $^ $(LIBS)

$(TARGET_SUB) : $(OBJS_SUB)
	@echo $@:$^...
	$(CXX) -o $@ $^ $(LIBS)

%.o : $(IDL) %.cpp
	@echo $@:$^...
	$(CXX) -c $(word 2,$^) $(CXXFLAGS) $(INCLUDES)

idl:
	idlpp -l isocpp $(IDL) -d $(IDLGD)
