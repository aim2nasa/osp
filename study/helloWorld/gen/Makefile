CXX = g++
CXXFLAGS = -fPIC -g -O2 -Wall -Wextra -std=c++11

LIBNAME = libHelloWorldData
TARGET = $(LIBNAME).so
SRCS = HelloWorldData.cpp HelloWorldDataDcps.cpp HelloWorldDataDcps_impl.cpp HelloWorldDataSplDcps.cpp
OBJS = ${SRCS:.cpp=.o}

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
INCLUDES = $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp

all : $(TARGET)
	@echo $@:$^...

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -shared -Wl,-soname,$@ -o $@ $(OBJS) $(LIBS)

%.o : %.cpp
	@echo $@:$^...
	$(CXX) -c $< $(INCLUDES) $(CXXFLAGS)

clean:
	@echo $@...
	rm -rf *.o $(TARGET)
	rm -rf *.cpp *.h *.hpp
