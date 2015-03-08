#  Author: Alex Sanchez, Anthony Balocco
#
#  Class:  CS 570 - Operating Systems
#  Prof:   Marie Roch  
#  Date:   3/10/15
# 
#  Filename: makefile
#
#  Description:
#
#     This is the makefile which simply compiles all of the .cpp and .h files into
#   .o files and links them. There is also a "clean" included if desired. 
#
#  Citations: Prof. Roch Lecture Notes and UNIX man pages
#
#  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

CC = g++
CFLAGS = -g -Wall


default: mizzo


mizzo: main.o create_escargot.o create_frog.o lucy_and_ethel.o
	$(CC) $(CFLAGS) -o mizzo main.o create_escargot.o create_frog.o lucy_and_ethel.o


main.o: main.cpp create_escargot.h create_frog.h lucy_and_ethel.h
	$(CC) $(CFLAGS) -c main.cpp


create_escargot.o: create_escargot.cpp create_escargot.h lucy_and_ethel.h
	$(CC) $(CFLAGS) -c create_escargot.cpp


create_frog.o: create_frog.cpp create_frog.h lucy_and_ethel.h
	$(CC) $(CFLAGS) -c create_frog.cpp


lucy_and_ethel.o: lucy_and_ethel.cpp lucy_and_ethel.h
	$(CC) $(CFLAGS) -c lucy_and_ethel.cpp


clean:
	#(RM) mizzo *.o *~