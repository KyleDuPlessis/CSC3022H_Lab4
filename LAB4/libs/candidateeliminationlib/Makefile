# DPLKYL002
# Makefile in /libs/candidateeliminationlib folder to compile a shared library

CPP=g++
CPPFLAGS=-fPIC -shared -std=c++11
LIBNAME=libcandidateelimination.so

# first compile - create binary object files
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

# then link - link binary object files together to create the shared library
$(LIBNAME): CandidateElimination.o CandidateElimination.h
	$(CPP) -o $(LIBNAME) CandidateElimination.o $(CPPFLAGS)

# other rules
# never submit binary object / shared object files
clean:
	@rm *.o *.so
