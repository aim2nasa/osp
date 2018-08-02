CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o
IDL = HelloWorldData.idl
IDLGD = gen

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
INCLUDES = -I$(shell pwd)/$(IDLGD) $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp 

LIBS = -L$(OSPL_HOME)/lib -ldcpsisocpp

all : $(TARGET)
	@echo $@:$^...

clean:
	@echo $@...
	rm -rf *.o *.gch $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -o $@ $^ $(LIBS)

%.o : $(IDL) %.cpp
	@echo $@:$^...
	$(CXX) -c $(word 2,$^) $(INCLUDES)

idl : $(IDL)
	idlpp -l isocpp $< -d $(IDLGD)
