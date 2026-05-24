/*
Core Files:

This is Global Header File in Bank System Project

This file contains global variables and constants that are used throughout 
the application. It serves as a central location for defining global 
settings, suchas the current logged-in user, and any other global 
configurations that may be needed across different modules of the project.


*/

#pragma once

#include <iostream>

#include "clsUser.h"

clsUser CurrentUser=clsUser::Find("","");