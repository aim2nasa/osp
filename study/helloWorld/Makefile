CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o
IDL = HelloWorldData.idl
IDLGD = gen

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
OSPL_INCLUDES = $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp
INCLUDES = -I$(shell pwd)/$(IDLGD) $(OSPL_INCLUDES)

all : $(TARGET)
	@echo $@:$^...

clean:
	@echo $@...
	rm -rf $(IDLGD)
	rm -rf *.o *.gch $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -o $@ $^

%.o : %.cpp idl
	@echo $@:$^...
	$(CXX) -c $< $(INCLUDES)

idl : $(IDL)
	rm -rf $(IDLGD)
	mkdir $(IDLGD)
	idlpp -l isocpp $< -d $(IDLGD)
