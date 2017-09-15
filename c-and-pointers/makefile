CFLAGS := -g -Wall -std=c99 -DZSQ
CC := clang

SOURCES := $(shell ls *.c)
TARGETS := $(foreach source,${SOURCES},$(basename ${source}))

all: ${TARGETS}
