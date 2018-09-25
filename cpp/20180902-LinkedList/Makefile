CXX := g++
CXXFLAGS := -std=c++1z
SRCDIR := src
BINDIR := bin
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)
BINS := $(BINDIR)/main
RM := rm -f

ifeq ($(DEBUG),FALSE)
	CXXFLAGS += -O3
else
	CXXFLAGS += -Wall -Wextra -pg
endif


# Implicit makefile rule
%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : all clean run

all : $(BINS)

run : all
	# Running from Makefile:
	$(BINS)

$(BINS) : $(OBJS) $(SRCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
	$(RM) $(OBJS) $(BINS)
