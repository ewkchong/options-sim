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
OBJECTS = main.o optionsPricer.o

# set the output binary name
EXECUTABLE = main

# define the build rules
all: $(EXECUTABLE)

main: main.o optionsPricer.o assetPriceGenerator.o
	$(CXX) $(CXXFLAGS) main.o optionsPricer.o assetPriceGenerator.o -o $@

main.o : src/main.cpp src/OptionsPricer.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

optionsPricer.o : src/OptionsPricer.cpp include/OptionsPricer.h
	$(CXX) $(CXXFLAGS) -c src/OptionsPricer.cpp -o $@

assetPriceGenerator.o : src/AssetPriceGenerator.cpp include/AssetPriceGenerator.h
	$(CXX) $(CXXFLAGS) -c src/AssetPriceGenerator.cpp -o $@

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -jo $@

# %.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
# 	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/%.cpp -o $@

# define the clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

