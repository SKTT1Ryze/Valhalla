# Makefile for runtime-cc

B = build
S = src
L = ../leetcode-cc

CC = clang++
CFLAGS = -std=c++20
CFLAGS += -Wall -O2 -D_GNU_SOURCE

FORMAT = clang-format
FFLAGS = --style=google -i

RUNTIME	= $B/runtime
RUNTIME_SRC = $(shell echo $S/*.cc)

$(RUNTIME): $(RUNTIME_SRC)
	@if [ ! -d $B ]; then mkdir $B; fi
	$(CC) $(CFLAGS) $(RUNTIME_SRC) -o $(RUNTIME)

format:
	@$(FORMAT) $(FFLAGS) $S/*
	@$(FORMAT) $(FFLAGS) $L/*
