# CMSC216 Project 1 Makefile

AN = p1
CLASS = 216
GS_COURSE_ID = 1098877
GS_ASSIGN_ID = 6582069

# -Wno-comment: disable warnings for multi-line comments, present in some tests
# -Wno-format-security -Wno-format-overflow: possibly applicable to Grace
CFLAGS = -Wall -g -Wno-unused-variable -fstack-protector-all
CC     = gcc $(CFLAGS)
SHELL  = /bin/bash
.SHELLFLAGS = -O nullglob -c
CWD    = $(shell pwd | sed 's/.*\///g')

PROGRAMS = \
	stock_main \
	stock_demo \
	test_stock_funcs \
	stock_multimain \

export PARALLEL?=True		#enable parallel testing if not overridden

all : $(PROGRAMS) 

# cleaning target to remove compiled programs/objects
clean :
	rm -f $(PROGRAMS) *.o vgcore.*

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
	@echo

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


############################################################
# stock plotting problem
stock_funcs.o : stock_funcs.c stock.h
	$(CC) -c $<

stock_main.o : stock_main.c stock.h
	$(CC) -c $<

stock_demo.o : stock_demo.c stock.h
	$(CC) -c $<

stock_demo : stock_demo.o stock_funcs.o
	$(CC) -o $@ $^

stock_main : stock_main.o stock_funcs.o
	$(CC) -o $@ $^

test_stock_funcs : test_stock_funcs.c stock_funcs.o 
	$(CC) -o $@ $^

stock_multimain.o : stock_multimain.c stock.h
	$(CC) -c $<

stock_multimain : stock_multimain.o stock_funcs.o
	$(CC) -o $@ $^

# problem targets
prob1 : stock_funcs.o test_stock_funcs

prob2 : stock_funcs.o test_stock_funcs

prob3 : stock_main

prob4 : stock_multimain

# Testing Targets
test : test-prob1 test-prob2 test-prob3 test-prob4

test-setup:
	@chmod u+x testy

test-prob1 : prob1 test-setup
	./testy -o md test_stock1.org $(testnum)

test-prob2 : prob2 stock_demo test-setup
	./testy -o md test_stock2.org $(testnum)

test-prob3 : prob3 test-setup
	./testy -o md test_stock3.org $(testnum)

test-prob4 : prob4 test-setup
	./testy -o md test_stock4.org $(testnum)

clean-tests :
	rm -rf test-results

