CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o

all : $(TARGET)
	@echo $@:$^...

clean:
	@echo $@...
	rm -rf *.o *.gch $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$^...
	$(CXX) -o $@ $^

%.o : %.cpp
	@echo $@:$^...
	$(CXX) -c $<
