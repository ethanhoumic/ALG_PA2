# Compiler and flags
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
DBGFLAGS = -g -D_DEBUG_ON_ -fsanitize=address
OPTFLAGS = -O2 -fsanitize=address

# Default target
all: bin/mps

# Optimized version
bin/mps: maximum_planar_subset_opt.o main_opt.o lib
	$(CC) $(OPTFLAGS) maximum_planar_subset_opt.o main_opt.o -ltm_usage -Llib -o bin/mps

main_opt.o: src/main.cpp lib/tm_usage.h src/Maximum_Planar_Subset.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $< -Ilib -Isrc -o $@

maximum_planar_subset_opt.o: src/Maximum_Planar_Subset.cpp src/Maximum_Planar_Subset.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $< -Isrc -o $@

lib: lib/libtm_usage.a

lib/libtm_usage.a: tm_usage.o
	$(AR) $(ARFLAGS) $@ $<

tm_usage.o: lib/tm_usage.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $< -Ilib -o $@

# Clean up
clean:
	rm -rf *.o lib/*.a lib/*.o bin/*