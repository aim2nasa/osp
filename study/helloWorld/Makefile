CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o
IDL = HelloWorldData.idl
IDLGD = gen

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
	$(CXX) -c $<

idl : $(IDL)
	rm -rf $(IDLGD)
	mkdir $(IDLGD)
	idlpp -l isocpp $< -d $(IDLGD)
