# for C++17
CXX := g++
CXXFLAGS := -std=c++1z
# for C99
CC := gcc
CFLAGS := -std=c99

SRCDIR := src
BINDIR := bin
OBJDIR := src
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
BINS := $(BINDIR)/main
RM := rm -f

ifeq ($(DEBUG),FALSE)
	CXXFLAGS += -O3
	CFLAGS += -O3
else
	CXXFLAGS += -Wall -Wextra -pg
	CFLAGS +=  -Wall -Wextra -pg
endif


# Implicit makefile rule
%.o : %.cpp %.h
	echo $<
	echo $@
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : all clean run echo

all : $(BINS)

run : all
	# Running from Makefile:
	$(BINS)

echo :
	@echo "-- SRCS:"
	@echo $(SRCS)
	@echo "-- OBJS:"
	@echo $(OBJS)
	@echo "-- BINS:"
	@echo $(BINS)

$(BINS) : $(OBJS) $(SRCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean :
	$(RM) $(OBJS) $(BINS)
