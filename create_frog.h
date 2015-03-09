//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/15
// 
//  Filename: create_frog.h
//
//  Description:
//
//     This is the header file for create_frog.h
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#ifndef CREATE_FROG_H
#define CREATE_FROG_H

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include "semaphore.h"

using namespace std;

void *create_frog(void *ptr);

#endif