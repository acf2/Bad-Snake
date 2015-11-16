BINDIR=bin
OBJDIR=obj
SRCDIR=src
EXEC=$(BINDIR)/bsnake

SRC := $(shell find $(SRCDIR) -name \*.cpp)
OBJ := $(patsubst */%.cpp,$(OBJDIR)/%.o,$(SRC))

DEBUG=-DDEBUG -g3 -w -pedantic -Wall
RELEASE=-DNDEBUG -O2
CXXFLAGS=-std=c++11

INC=
LIB=
LDFLAGS=$(LIB)

all: debug

clean:
	-rm -r $(OBJDIR) $(BINDIR)

debug: CXXFLAGS := $(DEBUG) $(CXXFLAGS)
debug: $(EXEC)

release: CXXFLAGS := $(RELEASE) $(CXXFLAGS)
release: $(EXEC)

$(EXEC): $(OBJ) | $(BINDIR)
	g++ $(CXXFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

VPATH = $(SRCDIR):$(LIBDIR)
$(OBJDIR)/%.o: %.cpp
	g++ -c $(CXXFLAGS) $(INC) $< -o $@

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: all clean debug release
