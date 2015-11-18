BINDIR=bin
OBJDIR=obj
SRCDIR=src
TEST_DIR=test
EXEC=$(BINDIR)/bsnake
TEST_EXEC=$(BINDIR)/gtest_bsnake

SRC := $(shell find $(SRCDIR) -name \*.cpp)
OBJ := $(patsubst */%.cpp,$(OBJDIR)/%.o,$(SRC))
TEST_SRC := $(shell find $(TEST_DIR) -name \*.cpp)
TEST_OBJ := $(patsubst */%.cpp,$(OBJDIR)/%.o,$(SRC))

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
	g++ $(CXXFLAGS) $(INC) -o $(EXEC) $(OBJ) $(LDFLAGS)

VPATH = $(SRCDIR):$(LIBDIR)
$(OBJDIR)/%.o: %.cpp
	g++ -c $(CXXFLAGS) $< -o $@

$(TEST_EXEC): $(TEST_OBJ) | $(BINDIR)
	g++ $(CXXFLAGS) $(INC) -o $(TEST_EXEC) $(TEST_OBJ) $(LDFLAGS) 

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: all clean debug release test
