//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/15
// 
//  Filename: lucy_and-ethel.h
//
//  Description:
//
//     This is the header file for lucy_and_ethel.h
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#ifndef LUCY_AND_ETHEL_H
#define LUCY_AND_ETHEL_H

#include <iostream>
#include <stdio.h>
#include <pthread.h>

using namespace std;

// Defining the conveyor structure to pass into the threads
typedef struct {

    int candies_total, candies_belt;   
    
    int frogs_total, frogs_belt,
        frogs_ethel, frogs_lucy;
    
    int escargots_total, escargots_belt,
        escargots_ethel, escargots_lucy;

} CONVEYOR_STATUS;

void *lucy_and_ethel(void *ptr);

#endif