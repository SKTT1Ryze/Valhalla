# Makefile for runtime-cc

B = build
S = src
L = ../leetcode-cc
I = ./include

CC = clang++
CFLAGS = -std=c++20
CFLAGS += -Wall -O2 -D_GNU_SOURCE
CFLAGS += -I$L
CFLAGS += -I$I

FORMAT = clang-format
FFLAGS = --style=google -i

RUNTIME	= $B/runtime
RUNTIME_SRC = $(shell echo $S/*.cc)
LEETCODE_HEADER = $(shell echo $L/*.hpp)
LEETCODE_SRC = $(shell echo $L/*.cc)
SRC = $(RUNTIME_SRC) $(LEETCODE_SRC)

$(RUNTIME): $(SRC) $(LEETCODE_HEADER)
	@if [ ! -d $B ]; then mkdir $B; fi
	$(CC) $(CFLAGS) $(SRC) -o $(RUNTIME)

run: $(RUNTIME)
	./$(RUNTIME)

clean:
	rm -rf $B

format:
	@$(FORMAT) $(FFLAGS) $S/*
	@$(FORMAT) $(FFLAGS) $L/*
