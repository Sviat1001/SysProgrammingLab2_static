CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lsqlite3

SRCDIR = .
INCDIR = .
BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/stalab2
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))
DEPS = $(OBJECTS:.o=.d)

LIBDIR = lib
LIBNAME = librenovation.a
STATICLIB = $(LIBDIR)/$(LIBNAME)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(STATICLIB) $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBS) -L$(LIBDIR) -lrenovation

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -MMD -MP -c $< -o $@

$(STATICLIB): $(BUILDDIR)/Renovation.o
	@mkdir -p $(LIBDIR)
	ar rcs $@ $<

clean:
	rm -rf $(BUILDDIR) $(BINDIR) $(LIBDIR)

-include $(DEPS)