BINDIR=bin
OBJDIR=obj
SRCDIR=src
TEST_DIR=test
EXEC=$(BINDIR)/bsnake
TEST_EXEC=$(BINDIR)/gtest_bsnake

SRC := $(shell find $(SRCDIR) -name \*.cpp)
OBJ := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SRC)))
TEST_SRC := $(shell find $(TEST_DIR) -name \*.cpp)
TEST_OBJ := $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(TEST_SRC)))
TESTED_MODULES := $(patsubst test_%.cpp,$(OBJDIR)/%.o,$(notdir $(TEST_SRC)))

DEBUG=-DDEBUG -g3 -w -pedantic -Wall
RELEASE=-DNDEBUG -O2
CXXFLAGS=-std=c++11

# libraries for program
INC=
LIB=
LDFLAGS=$(LIB)

# libraries for tests
TEST_INC=-I../googletest/googletest/include -I../googletest/googlemock/include
TEST_LIB=-L../googletest/build/googletest -L../googletest/build/googlemock
TEST_LDFLAGS=-lgtest -lgtest_main -lgmock -lpthread

all: debug

clean:
	-rm -r $(OBJDIR) $(BINDIR)

debug: CXXFLAGS := $(DEBUG) $(CXXFLAGS)
debug: $(EXEC)

release: CXXFLAGS := $(RELEASE) $(CXXFLAGS)
release: $(EXEC)

test: CXXFLAGS := $(DEBUG) $(CXXFLAGS)
test: INC := $(INC) $(TEST_INC)
test: LDFLAGS := $(LDFLAGS) $(TEST_LIB) $(TEST_LDFLAGS)
test: $(TEST_EXEC)

$(EXEC): $(OBJ) | $(BINDIR)
	g++ $(CXXFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

VPATH = $(shell find $(SRCDIR) $(LIBDIR) $(TEST_DIR) -type d | tr '\n' ':' | sed -e 's/:$$//')
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	g++ -c $(CXXFLAGS) $(INC) $< -o $@

$(TEST_EXEC): $(TESTED_MODULES) $(TEST_OBJ) | $(BINDIR)
	g++ $(CXXFLAGS) -o $(TEST_EXEC) $(TESTED_MODULES) $(TEST_OBJ) $(LDFLAGS)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: all clean debug release test
