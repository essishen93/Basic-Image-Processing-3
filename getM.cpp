//Name: Maoru Shen
//USC ID Number: 4946-8507-13
//USC Email: maorushe@usc.edu
//Submission Date: 11/01/2015
////////////////////////////////////////////////////////////////////
//Problem 3 : (b)
//This code is to skeletoning the binary image
/////////////////////////////////////////////////////////////////////
//getM.cpp
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "function.h"
using namespace std;


//get M Array after the first stage
//go through all the hit-and-miss pattern, return the results "M_Array"
//hit:M_Array=1, miss:M_Array=0


int get_M(int bone, int value)
{
    int M_Array=0;
    
    
    if (bone==4)
    {
        if (value==131)
            M_Array=1;
        if (value==14)
            M_Array=1;
        if (value==56)
            M_Array=1;
        if (value==224)
            M_Array=1;
        
        if (value==5)
            M_Array=1;
        if (value==20)
            M_Array=1;
        if (value==80)
            M_Array=1;
        if (value==65)
            M_Array=1;
    }
    
    
    else if (bone==6)
    {
        
        if (value==15)
            M_Array=1;
        if (value==135)
            M_Array=1;
        if (value==30)
            M_Array=1;
        if (value==60)
            M_Array=1;
        if (value==120)
            M_Array=1;
        if (value==240)
            M_Array=1;
        if (value==225)
            M_Array=1;
        if (value==195)
            M_Array=1;
    }
    
    else if (bone==7)
    {
        if (value==143)
            M_Array=1;
        if (value==62)
            M_Array=1;
        if (value==248)
            M_Array=1;
        if (value==227)
            M_Array=1;
    }
    
    else if (bone==8)
    {
        if (value==199)
            M_Array=1;
        if (value==31)
            M_Array=1;
        if (value==124)
            M_Array=1;
        if (value==241)
            M_Array=1;
    }
    
    else if (bone==9)
    {
        if (value==207)
            M_Array=1;
        if (value==231)
            M_Array=1;
        if (value==63)
            M_Array=1;
        if (value==159)
            M_Array=1;
        if (value==126)
            M_Array=1;
        if (value==252)
            M_Array=1;
        if (value==249)
            M_Array=1;
        if (value==243)
            M_Array=1;
    }
    
    else if (bone==10)
    {
        if (value==239)
            M_Array=1;
        if (value==191)
            M_Array=1;
        if (value==254)
            M_Array=1;
        if (value==251)
            M_Array=1;
    }
    
    else if (bone==11)
    {
        if (value==223)
            M_Array=1;
        if (value==127)
            M_Array=1;
        if (value==253)
            M_Array=1;
        if (value==247)
            M_Array=1;
    }
    
    else
        M_Array=0;
    
    return M_Array;
    
    
}