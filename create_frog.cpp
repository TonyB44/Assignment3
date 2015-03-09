//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/15
// 
//  Filename: create_frog.cpp
//
//  Description:
//
//     This is the header file for create_frog.cpp
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#include "create_frog.h"
#include "lucy_and_ethel.h"

void *create_frog(void *ptr) {
 
    CONVEYOR_STATUS * conv_stats = (CONVEYOR_STATUS*) ptr;

    while (conv_stats->candies_total < 100) {

	sem_wait(&conv_stats->empty);

	//accessing critical region
	sem_wait(&conv_stats->mutex);
		
	//NEED TO ADD FROG TO BUFFER STRUCT
	/*producing frog*/
	conv_stats->candies_total++;
	conv_stats->frogs_total++;	
	conv_stats->candies_belt++;
	conv_stats->frogs_belt++;
	
	cout << "Belt: " 
	<< conv_stats->frogs_belt     << " frogs + "
	<< conv_stats->escargots_belt << " escargots = "
	<< conv_stats->candies_belt   << ". produced: "
	<< conv_stats->candies_total  << "    Added crunchy frog bite.\n"
	;

	//exiting critical region
	sem_post(&conv_stats->mutex);

	sem_post(&conv_stats->produced);

	

    }
}