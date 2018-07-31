CXX = g++

TARGET = HelloWorldPub
OBJS = HelloWorldPub.o
SRCS =$(OBJS:.o=.c)

all : $(TARGET)
	@echo $@:$(TARGET)...

$(TARGET) : $(OBJS)
	@echo $@:$(OBJS)...
	$(CXX) -o $@ $^

.c.o:
	$(CXX) -c $<

HelloWorldPub.o : HelloWorldPub.cpp

clean:
	@echo $@...
	rm -rf *.o *.gch $(TARGET)
