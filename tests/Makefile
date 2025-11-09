CXX = g++
CXXFLAGS = -std=c++17 -I../include -I/opt/homebrew/opt/googletest/include -Wall
LIBS = -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread

SRCS = test_invoker.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = runTests

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)
