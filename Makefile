SHELL = bash

MODULES := main functions

EXE := prog

# look for include files in each of the modules
CFLAGS += $(patsubst %,-I%,\
	$(MODULES))

# extra libs if required
LIBS :=

# each module will add to this
SRC :=

# include the description for each module
include $(patsubst %,\
	%/module.mk,$(MODULES))

# determine the object files
OBJ := \
	$(patsubst %.c,%.o, \
	$(filter %.c,$(SRC))) \
	$(patsubst %.y,%.o, \
	$(filter %.y,$(SRC)))

# link the program
$(EXE): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

# include the C include dependecies
DEPEND = $(OBJ:%.o=%.d)
include $(DEPEND)

# calculate the C include dependencies
%.d: %.c
	./depend.sh $(shell dirname $*.c) $(CFLAGS) $*.c > $@


#	./depend.sh `dirname $*.c` $(CFLAGS) $*.c > $@


clean:
	rm -rf $(OBJ) $(EXE) */*.d
