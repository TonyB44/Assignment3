//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/2015
// 
//  Filename: main.cpp
//
//  Description:
//
//     This is main method for the program.
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <pthread.h>

#include "create_escargot.h"
#include "create_frog.h"
#include "lucy_and_ethel.h"

using namespace std;

int main (int argc, char **argv) {

    int escargot_delay = 0, frog_delay = 0;
    int lucy_delay = 0, ethel_delay = 0;

    int option = 0;
  
    // Checking command line arguments
    // Temporary check to figure out getopt
    while ((option = getopt(argc, argv,"E:L:f:e:")) != -1) {
        switch (option) {  
	    case 'e': escargot_delay = atoi(optarg); break;
	    case 'f': frog_delay = atoi(optarg); break;
	    case 'L': lucy_delay = atoi(optarg); break;
	    case 'E': ethel_delay = atoi(optarg); break;
	}
    }
    
    // testing delays
    cout << "esc: "  << escargot_delay
	 << " frog: " << frog_delay
	 << " lucy: " << lucy_delay
	 << " ethel: "<< ethel_delay << "\n\n";


    // initializing conveyor belt data structure
    CONVEYOR_STATUS * conv_stats = new CONVEYOR_STATUS();

    conv_stats->candies_total = 0;
    conv_stats->candies_belt  = 0;
    

    // Naming the threads
    pthread_t frog_thread, escargot_thread, lucy_thread, ethel_thread;
    int status;

    
    while (conv_stats->candies_total < 100) {


	status = pthread_create( &frog_thread, NULL, create_frog, conv_stats); 

	if(status){
	    fprintf(stderr,"Error - pthread_create() return code: %d\n",status);
	    exit(EXIT_FAILURE);
	}

	//can't use pthread_join for this assignment
	//it works, but need to use semaphores
	pthread_join(frog_thread, NULL);

    }
    
    // need a conveyor belt data structure (que? list?)
    // lucy/ethel still need to pick up candies

    
    // Here is the production report for the number of each type of candy produced
    // and how many of each candy were consumed by Lucy and Ethel. The total number
    // of candies produced/consumed should add up to 100.

    cout << "\n\nPRODUCTION REPORT\n" << "-----------------------------------\n"
         << "Crunchy frog bite producer generated " << conv_stats->frogs_total  
      						    << " candies.\n" 
	 << "Escargot sucker producer generated "   << conv_stats->escargots_total 
						    << " candies.\n"
	 
	 << "Lucy consumed " << conv_stats->frogs_lucy     << " crunchy frog bites + "
			     << conv_stats->escargots_lucy << " escargot suckers = "
			     << (conv_stats->escargots_lucy + conv_stats->frogs_lucy)

	 << "\nEthel consumed " << conv_stats->frogs_ethel     << " crunchy frog bites + "
				<< conv_stats->escargots_ethel << " escargot suckers = "
				<< (conv_stats->escargots_ethel + conv_stats->frogs_ethel)
				<<"\n\n";
			

    
    
    return 0;
}