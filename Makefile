CXX = clang++   # set the C++ compiler

# set compiler flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# set source and header file paths
SRCDIR = src
INCDIR = include

# list all source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# list all header files
INCLUDES = $(wildcard $(INCDIR)/*.h)

# generate object file names from source file names
OBJECTS = main.o OptionsPricer.o

# set the output binary name
EXECUTABLE = main

# define the build rules
all: $(EXECUTABLE)

# OptionsPricer.o : src/OptionsPricer.cpp include/OptionsPricer.h
# 	$(CXX) $(CXXFLAGS) src/OptionsPricer.cpp

# main.o : src/main.cpp include/OptionsPricer.h
main.o : $(SOURCES) $(INCLUDES)
	$(CXX) $(CXXFLAGS) src/main.cpp

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -jo $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# define the clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

