//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/15
// 
//  Filename: lucy_and-ethel.cpp
//
//  Description:
//
//     This is the header file for lucy_and_ethel.cpp
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#include "lucy_and_ethel.h"

void *lucy_and_ethel(void *ptr) {

    CONVEYOR_STATUS * conv_stats = (CONVEYOR_STATUS*) ptr;

    while (conv_stats->candies_total < 100) {

	//NEED TO CONSUME OFF CONVEYOR BELT INSTEAD OF FROG
	//THIS IS JUST FOR TESTING
	sem_wait(&conv_stats->produced);

	//accessing critical region
	sem_wait(&conv_stats->mutex);
	
	//NEED TO REMOVE FROG FROM BUFFER STRUCT
	conv_stats->candies_belt--;
	conv_stats->frogs_belt--;
	conv_stats->frogs_lucy++;

	cout << "Belt: " 
	<< conv_stats->frogs_belt     << " frogs + "
	<< conv_stats->escargots_belt << " escargots = "
	<< conv_stats->candies_belt   << ". produced: "
	<< conv_stats->candies_total  << "    Lucy consumed frog bite.\n";

	sem_post(&conv_stats->mutex);


	sem_post(&conv_stats->empty);


    }



};