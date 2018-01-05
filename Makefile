CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu11 -g -DDEBUG -O0

bit_length ?= 32
start ?= 67100000
end ?= 67116384

ifeq ($(strip $(PROFILE)),1)
CFLAGS_common += -Dcorrect
endif
ifeq ($(strip $(MP)),1)
CFLAGS_common += -fopenmp -DMP
endif
CFLAGS_common += -Duint$(bit_length)


EXEC = \
	iteration \
	binary \
	byte \
	recursive \
	# harley

# EXEC = \
	recursive \
	iteration \
	binary \
	byte \
	# harley	

deps := $(EXEC:%=.%.o.d)

GIT_HOOKS := .git/hooks/pre-commit
.PHONY: all
all: $(GIT_HOOKS) $(EXEC)

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

SRCS_common = main.c

%: $(SRCS_common) %.c clz.h
	$(CC) $(CFLAGS_common) -o $@ \
		-MMD -MF .$@.d \
		-D$(shell echo $(subst .o,,$@)) $(SRCS_common) $@.c

run: $(EXEC)
	for method in $(EXEC); do\
		taskset -c 1 ./$$method $(start) $(end); \
	done		

plot: iteration.txt iteration.txt binary.txt byte.txt #harley.txt
	gnuplot scripts/runtime.gp

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o $(deps) *.txt *.png

-include $(deps)
