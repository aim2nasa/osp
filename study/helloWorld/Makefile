CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o

all : $(TARGET)
	@echo $@:$(TARGET)...

$(TARGET) : $(OBJS)
	@echo $@:$(OBJS)...
	$(CXX) -o $@ $(OBJS)

HelloWorldPub.o : HelloWorldPub.cpp
	@echo $@...
	$(CXX) -c HelloWorldPub.cpp

clean:
	@echo $@...
	rm -rf *.o *.gch $(TARGET)
