CXX = clang++   # set the C++ compiler

# set compiler flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -target arm64-apple-macos11

# set source and header file paths
SRCDIR = src
INCDIR = include

# list all source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# generate object file names from source file names
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=%.o)

# set the output binary name
EXECUTABLE = main

# define the build rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# define the clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

