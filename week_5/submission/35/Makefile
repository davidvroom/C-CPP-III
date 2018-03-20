#!/usr/bin/make

# 
# Handmade Makefile, for easy insertion into a little C++ project,
# heavily commented, for educational use. Requires GNU g++.
# Intended for use as a single Makefile.
# (see http://aegis.sourceforge.net/auug97.pdf)
#
# Author: Jurjen Bokma <j.bokma@rug.nl>
#
# FEATURE: if you update a header file, all sources that include it
# will be rebuilt. This results in many fewer runs of 'make clean'.
# In two cases, 'make clean' is still required though:
# - when you *remove* a header file from the tree, and
# - when you turn off precompiled headers after having used them.
#

# Extensions are IMPORTANT:
# use .cc for sources, .hh for headers, .ih for internal headers.

# Usage:
# The source must be arranged like this:
#   .
#   ├── someclass
#   │   ├── someclass.hh
#   │   ├── someclass.ih
#   │   ├── ctor.cc
#   │   ├── etc.
#   ├── otherclass
#   │   └── etc.
#   ├── main.cc
#   ├── otherprog.cc
#   ├── Makefile
#   └── test
#       ├── sometest.cc
#       ├── anothertest.cc
#       └── etc.
#
# The Makefile can be used as-is, without editing.
# Source files having a 'main' function are assumed to be program sources.
# The sources in the 'test' directory are assumed to be such program sources.
# The most important program is supposed to be called 'main.cc'.
# All other source files are compiled into a static convenience library.
# The program objects are linked against the convenience library to
# create executables.

#################################
# Edit to taste in this section #
#################################

# By default, the project is named after the current directory
# This allows us to use the Makefile without even editing it.
BASEDIR := $(shell basename $$(pwd))
# Using ':=' means that BASEDIR is assigned to *once*.
# A variable assigned to with '=' is expanded every time it is used.

# To rename the project, change PROJECT, not BASEDIR
PROJECT := $(BASEDIR)

# No Git integration, just specify your version right here
MAJOR := 0
MINOR := 0
BUGFIX := 0
VERSION := $(MAJOR).$(MINOR).$(BUGFIX)
# MAJOR, MINOR and BUGFIX are available in the sources as if they were
# specified there with a preprocessor #define

# The executable and the static convenience library are both
# named after the project.
EXECUTABLE := $(PROJECT)
LIBNAME := $(PROJECT)
# If you don't name your most important program 'main.cc',
# it will still be built.

# Any environment variables are extended, not replaced
# So either edit here, or set in the environment
CXXFLAGS += -Wall -std=c++17 -pthread -Werror
LDFLAGS += -L.
LDLIBS += -l$(LIBNAME)

# If calling 'make' should not build all tests programs,
# remove 'tests' from the following line
ALL = $(EXECUTABLE) progs tests

# For small projects, the gain of a shorter compile time usually does not
# compensate for the loss of precompiling the headers in the first place.
# Nevertheless, if headers must be precompiled, uncomment the next line.
#USE_PRECOMPILED_HEADERS = nonempty
# NB: when switching away from using precompiled headers,
# a 'make clean' IS REQUIRED!
# (Lest the precompiled headers stay around, and the compiler reads
#  those instead of the actual headers, which you may have updated.)

####################################################################
# NO EDITING below this line, please.                              #
# If you do, back up your filesystems before you run 'make' again. #
####################################################################

# Recursive function. We use it to search for sources in the entire tree.
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
$(filter $(subst *,%,$2),$d))

DEFINES := -DMAJOR -DMINOR -DVERSION

# Find source files by extension
FOUNDSOURCES = $(call rwildcard,,*.cc)

# Unit tests should be kept in TESTDIR
TESTDIR = test
TESTSOURCES = $(filter $(TESTDIR)/%,$(FOUNDSOURCES))
TESTS = $(patsubst %.cc,%,$(TESTSOURCES))
TESTOBJS = $(patsubst %.cc,%.o,$(TESTSOURCES))

# The grep expression below finds sources that contain a main() function.
# Only the following forms (mostly whitespace-insensitive) are supported:
# int main()
# int main(int argc, char *argv[])
# int main(int argc, char **argv)
# Any comment inside the function header will spoil detection
PROGSOURCESFOUND = $(subst ./,,$(shell find -type f -iname \*.cc -exec grep -qE '^\s*int\s+main\s*\(\s*(int\s*argc\s*,\s*char\s*(\*\s*argv\s*\[\s*\]|\*\s*\*\s*argv)\s*)?\)(s*\{)?\s*' {} \; -print))
PROGSOURCES = $(filter-out $(TESTSOURCES),$(PROGSOURCESFOUND))
PROGS = $(patsubst %.cc,%,$(PROGSOURCES))

# The rest of the sources go in the convenience library
LIBSOURCES = $(filter-out main.cc,$(filter-out $(PROGSOURCES),$(filter-out $(TESTSOURCES),$(FOUNDSOURCES))))
LIBOBJECTS = $(patsubst %.cc,%.o,$(LIBSOURCES))
# ALLOBJFILES is just for cleaning up
ALLOBJFILES = $(call rwildcard,,*.o)

# NB: with pch's *all* headers are always precompiled, regardless of whether
# any goals have them as targets.
ifdef USE_PRECOMPILED_HEADERS
    # Find headers and internal headers as well
    FOUNDHEADERS = $(call rwildcard,,*.hh)
    FOUNDINTERNALHEADERS = $(call rwildcard,,*.ih)
    PRECOMPILEDHEADERS = $(patsubst %,%.gch,$(FOUNDINTERNALHEADERS) $(FOUNDHEADERS))
    PCHEXTRADEPS = $(patsubst %.ih,$(DEPDIR)/%.d,$(FOUNDINTERNALHEADERS)) $(patsubst %.hh,$(DEPDIR)/%.d,$(FOUNDHEADERS))
else
    # Just for cleaning up
    PRECOMPILEDHEADERS = $(call rwildcard,,*.gch)
endif

# GNU gcc can generate dependencies. We use those to determine
# which source file needs which headers, and consequently to
# update dependent source files when the header has changed.
# This saves on manual `make clean' commands, and hence on rebuilding
# whatever was cleaned.
# NB: dependencies lag behind one round of Make. This is hardly ever a problem.
DEPDIR := .d
DEPFILES = $(patsubst %.cc,$(DEPDIR)/%.d,$(FOUNDSOURCES)) $(PCHEXTRADEPS)
DEPDIRS = $(sort $(dir $(DEPFILES)))
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
# Make the dependency tree right now, except the leaves.
$(shell mkdir --parent $(DEPDIRS) > /dev/null 2>&1)
# If compilation fails, we don't want to be left with a broken dependency file,
# so we put the dependency in a temporary, and after compilation move it to the
# actual included file.
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d
HEADERPOSTCOMPILE = $(POSTCOMPILE)
SRCPOSTCOMPILE = $(POSTCOMPILE)
ifdef USE_PRECOMPILED_HEADERS
    # This sed command changes '.ih' and '.hh' into '.gch' in the prerequisites
    # of any rule with a target *.o, conveniently using the fact that the
    # generated dependencies are seperated by empty lines.
    SRCPOSTCOMPILE += && sed -i '/^[^:]*.o:/,/^$$/ s/.[ih]h/&.gch/g' $(DEPDIR)/$*.d
endif

# When just linking and not compiling, the DEPFLAGS will be ignored.
CXXFLAGS += $(DEPFLAGS) $(DEFINES)

# This serves to 'make foo/bar.hh' and saves some typing
define HEADER_SKELETON
#ifndef def_h_include_$(notdir $*)_hh
#define def_h_include_$(notdir $*)_hh
#endif //def_h_include_$(notdir $*)_hh
endef
# Export to the environment for easy retrieval in a shell command.
export HEADER_SKELETON

# By convention, 'all' is the first and default target,
# made if one runs 'make' without arguments.
all: $(ALL)

# The executable is merely a copy of main
#  This is a normal, explicit rule. It tells Make
#  - $(EXECUTABLE) can be made from main,
#  - if $(EXECUTABLE) is desired, it must be remade if main is newer, and
#  - a recipe for doing just that.
$(EXECUTABLE): main
	cp $^ $@

# 'make tests' makes only the test programs
#   This is a prerequisite-only rule. The recipe for making a test program
#   is supplied further down.
tests: $(TESTS)

progs: $(PROGS)

# All executables need the convenience library
main $(TESTS) $(PROGS): lib$(LIBNAME).a

# The convenience library is built from all the objects
lib$(LIBNAME).a: $(LIBOBJECTS)
	ar rcs $@ $^

# Cancel the built-in rules that don't use post-compile
%: %.cc
%.o: %.cc

# Building an object from source needs the postcompile, because it also
# generates a dependency file.
#  This is a pattern rule, so it provides a recipe, but doesn't generate
#  dependencies. It tells Make how *.o can be made from *.cc, but
#  doesn't tell it that if someclass/someclass.cc is newer,
#  someclass/someclass.o must be remade.
#  That must be told by the generated dependency file.
%.o: %.cc $(PRECOMPILEDHEADERS)
	@echo "   [Compiling] $<"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
	@$(SRCPOSTCOMPILE)

%: %.cc $(PRECOMPILEDHEADERS)
	@echo "   [Compiling] $<"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)
	@$(SRCPOSTCOMPILE)
%: %.cc $(DEPDIR)/%.d

# Building executables requires the convenience library.
# The LDFLAGS and LDLIBS are therefore added, *at*the*end* of the g++ invocation!
# The prefix '@' tells Make not to echo the command.
# Just linking here, so no postcompile
%: %.o lib$(LIBNAME).a
	@echo "   [Linking] $<"
	@$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

ifdef USE_PRECOMPILED_HEADERS
# A precompiled header *.hh.gch can be made from *.hh. Or from *.ih.
# Or actually from *. Better not call the rule on non-headers, though.
%.gch: %
	@echo "   [Precompiling header] $< into $@"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -x c++-header -c -o $@ $<
	@$(HEADERPOSTCOMPILE)
## If the rules that generate *.d below are uncommented, *all* .d files will be
## generated before Make starts making other targets
## If dependency files are needed, they can be made from headers ...
#$(DEPDIR)/%.d: %.hh
#	@echo "   [Precompiling header] $< (side effect of making dependency file)"
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -x c++-header -o $*.hh.gch $<
#	@$(HEADERPOSTCOMPILE)
## ... from internal headers...
#$(DEPDIR)/%.d: %.ih
#	@echo "   [Precompiling internal header] $< (side effect of making dependency file)"
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -x c++-header -o $*.ih.gch $<
#	@$(HEADERPOSTCOMPILE)
## ... and from sources, in which case the object file is also generated.
#$(DEPDIR)/%.d: %.cc
#	@echo "   [Compiling] $< (side effect of making dependency file)"
#	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $(subst .cc,.o,$<) $<
#	@$(SRCPOSTCOMPILE)

# Keep those precompiled header files around.
.PRECIOUS: %.gch
endif

# Empty rule, so that a missing .d generates no error.
# This causes the dependency lag (see above), but saves a lot of
# needless recompiling.
$(DEPDIR)/%.d: ;

# Phony targets are considered for remaking, even if their targets already exist,
# and if they don't actually make their targets, that's ok as well.
.PHONY: all clean depclean tests progs tar

# Remove all generated files
clean:
	@rm -f $(EXECUTABLE) main $(TESTS) $(PROGS) lib$(LIBNAME).a $(ALLOBJFILES) $(PRECOMPILEDHEADERS)
	@rm -rf $(DEPDIR)

tar: clean
	tar cvzf ../$(PROJECT)-$(VERSION).tgz \
	--transform='s%^./%$(PROJECT)-$(VERSION)/%' \
	--exclude=*~ \
	--exclude=.git \
	--exclude=$(DEPDIR) \
	--exclude=$(PROJECT)*.tgz\
	 ./

# This is a dangerous rule: Make can use it to generate a header file if it
# thinks it needs one, and clutter the source tree with empty headers.
# But it's convenient to be able to say: make someclass/someclass.hh
%.hh:
	echo "$$HEADER_SKELETON" > $@

# Include generated dependencies, but don't bother when cleaning up.
# Conveniently, Make re-executes itself when the depency file is updated.
ifneq ($(MAKECMDGOALS),clean)
    -include $(DEPFILES)
endif
