
#########################
# DO NOT EDIT THIS FILE #
#########################

# But please, feel free to inspect the targets and design for your own learning.

#
CC := g++
CFLAGS := -Wall -Werror -pedantic -g -c -std=c++17
LINKFLAGS := -Wall -Werror -pedantic -g -std=c++17


#
BIN_NAME := main
BIN := ./$(BIN_NAME)
#
BIN_SANDBOX_NAME := main-sandbox
BIN_SANDBOX := ./$(BIN_SANDBOX_NAME)
#
BIN_TESTS_NAME := main-tests
BIN_TESTS := ./$(BIN_TESTS_NAME)
#
BIN_LEAK_CHECKER_NAME := leak-checker
BIN_LEAK_CHECKER = ./$(BIN_LEAK_CHECKER_NAME)


#
DEPS_PUHP := $(wildcard puhp-tests/*)


#
default:	help


#
help:
	@echo "***** Makefile Menu *****"
	@echo
	@echo "make build         ==> Build source files"
	@echo
	@echo "make run           ==> Run the hash table tui"
	@echo "make debug         ==> Debug the hash table tui with gdb"
	@echo
	@echo "make sandbox       ==> Run the extra sandbox program"
	@echo "make debug-sandbox ==> Debug the extra sandbox program with gdb"
	@echo
	@echo "make test          ==> Run tests against your hash table"
	@echo "make debug-test    ==> Debug the tests run against your hash table"
	@echo
	@echo "make clean         ==> Clean temporary build files"


#
build:	$(BIN) $(BIN_SANDBOX) $(BIN_TESTS)
.PHONY: build


#
run:	$(BIN)
	$(BIN)
.PHONY: run


#
sandbox:	$(BIN_SANDBOX)
	$(BIN_SANDBOX)
.PHONY: sandbox


#
debug-sandbox:	$(BIN_SANDBOX)
	gdb $(BIN_SANDBOX) -ex run
.PHONY: debug-sandbox


#
debug:	$(BIN)
	gdb $(BIN) -ex run
.PHONY: debug


#
gradescope:	clean
gradescope:	test
tests:		test
test:		$(BIN_TESTS)
	$(BIN_TESTS)
.PHONY: gradescope tests test


#
debug-tests:		debug-test
debug-test:	$(BIN_TESTS)
	gdb $(BIN_TESTS) -ex run
.PHONY: debug-tests debug-test


#
$(BIN):	main.o MyRolodex.o
	$(CC) $(LINKFLAGS) $^ -o $@


#
$(BIN_SANDBOX):	sandbox.o MyRolodex.o
	$(CC) $(LINKFLAGS) $^ -o $@


#
$(BIN_TESTS):	CPP_Tests.o MyRolodex.o
	$(CC) $(LINKFLAGS) $^ -o $@


# Link the leak checker binary
$(BIN_LEAK_CHECKER):	leak_checker.o MyHashTable.hpp MyRolodex.o
	$(CC) $(LINKFLAGS) leak_checker.o MyRolodex.o -o "$@"


#
main.o:	main.cpp Address.hpp MyHashTable.hpp MyRolodex.hpp
	$(CC) $(CFLAGS) $< -o $@


#
sandbox.o:	sandbox.cpp Address.hpp MyHashTable.hpp MyRolodex.hpp
	$(CC) $(CFLAGS) $< -o $@


#
MyRolodex.o:	MyRolodex.cpp MyRolodex.hpp Address.hpp MyHashTable.hpp
	$(CC) $(CFLAGS) $< -o $@


#
CPP_Tests.o:	CPP_Tests.cpp MyRolodex.hpp MyHashTable.hpp Address.hpp $(DEPS_PUHP)
	$(CC) $(CFLAGS) $< -o $@


#
leak_checker.o:	leak_checker.cpp MyRolodex.hpp MyHashTable.hpp Address.hpp
	$(CC) $(CFLAGS) "$<" -o "$@"


#
clean:
	-rm *.o
	-rm $(BIN)
	-rm $(BIN_TESTS)
	-rm $(BIN_SANDBOX)
	-rm $(BIN_LEAK_CHECKER_NAME)
	-rm results.json
.PHONY: clean