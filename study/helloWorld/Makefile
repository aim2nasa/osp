CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o

all : $(TARGET)
	@echo $@:$(TARGET)...

clean:
	@echo $@...
	rm -rf *.o *.gch $(TARGET)

$(TARGET) : $(OBJS)
	@echo $@:$(OBJS)...
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) -c $<
