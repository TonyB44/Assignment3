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
	    case 'E': escargot_delay = atoi(optarg); break;
	    case 'L': frog_delay = atoi(optarg); break;
	    case 'f': lucy_delay = atoi(optarg); break;
	    case 'e': ethel_delay = atoi(optarg); break;
	}
    }
    
    cout << "esc: "  << escargot_delay
	 << " frog: " << frog_delay
	 << " lucy: " << lucy_delay
	 << " ethel: "<< ethel_delay << "\n";

    // start producing candies (conveyor belt starts)
    // lucy/ethel pick up candies
    // Loop until 100 candies produced

    return 0;
}