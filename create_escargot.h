//  
//  Author: Alex Sanchez, Anthony Balocco
//
//  Class:  CS 570 - Operating Systems
//  Prof:   Marie Roch  
//  Date:   3/10/15
// 
//  Filename: create_escargot.h
//
//  Description:
//
//     This is the header file for create_escargot.h
//
//  Citations: Prof. Roch Lecture Notes and UNIX man pages
//
//  Copyright (c) 2015 Sanchez Balocco. All rights reserved.

#ifndef CREATE_ESCARGOT_H
#define CREATE_ESCARGOT_H

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include "semaphore.h"

using namespace std;

void *create_escargot(void *ptr);

#endif