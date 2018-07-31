CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o
IDL = HelloWorldData.idl
IDLGD = gen

OSPL_CPP_INCLUDES = -I$(OSPL_HOME)/include/dcps/C++
INCLUDES = -I$(shell pwd)/$(IDLGD) $(OSPL_CPP_INCLUDES)/SACPP $(OSPL_CPP_INCLUDES)/isocpp 

all : $(TARGET)
	@echo $@:$^...

clean:
	@echo $@...
	rm -rf $(IDLGD)
	rm -rf *.o *.gch $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -o $@ $^

%.o : %.cpp
	@echo $@:$^...
	$(CXX) -c $< $(INCLUDES)

idl : $(IDL)
	rm -rf $(IDLGD)
	mkdir $(IDLGD)
	idlpp -l isocpp $< -d $(IDLGD)
