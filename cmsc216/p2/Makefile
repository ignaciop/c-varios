# CMSC216 Project 2 Makefile
AN = p2
CLASS = 216
GS_COURSE_ID = 1098877
GS_ASSIGN_ID = 6937406

# -Wno-comment: disable warnings for multi-line comments, present in some tests
# CFLAGS = -Wall -Wno-comment -Werror -g  -Wno-format-security 
CFLAGS = -Wall -Werror -g -fstack-protector-all 
CC     = gcc $(CFLAGS)
SHELL  = /bin/bash
CWD    = $(shell pwd | sed 's/.*\///g')

PROGRAMS = \
	batt_main \
	test_batt_update \
	puzzlebox   \
	treeset_main \

#	test_treeset_verify \

export PARALLEL?=True		#enable parallel testing if not overridden

all : $(PROGRAMS) 

# cleaning target to remove compiled programs/objects
clean :
	rm -f $(PROGRAMS) *.o

help :
	@echo 'Typical usage is:'
	@echo '  > make                          # build all programs'
	@echo '  > make clean                    # remove all compiled items'
	@echo '  > make zip                      # create a zip file for submission'
	@echo '  > make prob1                    # built targets associated with problem 1'
	@echo '  > make test                     # run all tests'
	@echo '  > make test-prob2               # run test for problem 2'
	@echo '  > make test-prob2 testnum=5     # run problem 2 test #5 only'
	@echo '  > make update                   # download and install any updates to project files'
	@echo '  > make submit                   # upload submission to Gradescope'


############################################################
# 'make zip' to create complete.zip for submission
ZIPNAME = $(AN)-complete.zip
zip : clean clean-tests
	rm -f $(ZIPNAME)
	cd .. && zip "$(CWD)/$(ZIPNAME)" -r "$(CWD)"
	@echo Zip created in $(ZIPNAME)
	@if (( $$(stat -c '%s' $(ZIPNAME)) > 10*(2**20) )); then echo "WARNING: $(ZIPNAME) seems REALLY big, check there are no abnormally large test files"; du -h $(ZIPNAME); fi
	@if (( $$(unzip -t $(ZIPNAME) | wc -l) > 256 )); then echo "WARNING: $(ZIPNAME) has 256 or more files in it which may cause submission problems"; fi

############################################################
# `make update` to get project updates
update :
ifeq ($(findstring solution,$(CWD)),)
	curl -s https://www.cs.umd.edu/~profk/216/$(AN)-update.sh | /bin/bash 
else
	@echo "Cowardly refusal to update solution"
endif

################################################################################
# `make submit` to upload to gradescope
submit : zip
	@chmod u+x gradescope-submit
	@echo '=== SUBMITTING TO GRADESCOPE ==='
	./gradescope-submit $(GS_COURSE_ID) $(GS_ASSIGN_ID) $(ZIPNAME)

################################################################################
# battery problem
prob1 : batt_main

batt_main : batt_main.o batt_update.o batt_sim.o
	$(CC) -o $@ $^

batt_main.o : batt_main.c batt.h
	$(CC) -c $<

batt_sim.o : batt_sim.c batt.h
	$(CC) -c $<

batt_update.o : batt_update.c batt.h
	$(CC) -c $<

test_batt_update : test_batt_update.o batt_sim.o batt_update.o
	$(CC) -o $@ $^

test_batt_update.o : test_batt_update.c
	$(CC) -c $<

test-prob1 : prob1 test_batt_update test-setup
	./testy test_batt_update.org $(testnum)

################################################################################
# debugging problem

# used to automate checking the userid in puzzlebox via the check_userid() function
export EXPECT_USERID?=$(USER)

prob2 : puzzlebox

puzzlebox.o : puzzlebox.c
	$(CC) -c $<

puzzlebox : puzzlebox.o
	$(CC) -o $@ $^

test-prob2 : prob2 test-setup
	./puzzlebox input.txt

################################################################################
# treeset problem
prob3 : treeset_main

treeset_main : treeset_main.o treeset_funcs.o
	$(CC) -o $@ $^

treeset_main.o : treeset_main.c treeset.h
	$(CC) -c $<

treeset_funcs.o : treeset_funcs.c treeset.h
	$(CC) -c $<

test-prob3 : treeset_main
	./testy -o md test_treeset.org $(testnum)

# test-prob3 : treeset_main test_treeset_verify
# 	./testy -o md test_treeset.org $(testnum)

################################################################################
# Testing Targets
test : test-prob1 test-prob2 test-prob3

test-setup:
	@chmod u+x testy

clean-tests :
	rm -rf test-results


