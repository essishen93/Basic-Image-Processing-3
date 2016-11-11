//Name: Maoru Shen
//USC ID Number: 4946-8507-13
//USC Email: maorushe@usc.edu
//Submission Date: 11/01/2015
////////////////////////////////////////////////////////////////////
//Problem 3 : (b)
//This code is to skeletoning the binary image
/////////////////////////////////////////////////////////////////////
//getG.cpp
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "function.h"
using namespace std;


//get G Array after the second stage
//go through all the hit-and-miss pattern, return the results "G_Array"
//hit:G_Array=1, miss:G_Array=0

int get_G(int value)
{
    int G_Array=0;
    
    //spur
    if (value==2)
        G_Array=1;
    if (value==8)
        G_Array=1;
    if (value==32)
        G_Array=1;
    if (value==128)
        G_Array=1;
    
    //sigle 4-connection
    if (value==1)
        G_Array=1;
    if (value==64)
        G_Array=1;
    if (value==4)
        G_Array=1;
    if (value==16)
        G_Array=1;
    
    //L corner
    if (value==5)
        G_Array=1;
    if (value==20)
        G_Array=1;
    if (value==65)
        G_Array=1;
    if (value==80)
        G_Array=1;
    
    
    
    //corner cluster
    int d1,d2,d3,d4,d5;
    int mask_value;
    if (G_Array==0)
    {for (d1=0;d1<2;d1++)
        for (d2=0;d2<2;d2++)
            for (d3=0;d3<2;d3++)
                for (d4=0;d4<2;d4++)
                    for (d5=0;d5<2;d5++)
                    {
                        mask_value=1*d1+
                        (int)pow(2,1)*d2+
                        (int)pow(2,2)+
                        (int)pow(2,3)+
                        (int)pow(2,4)+
                        (int)pow(2,5)*d3+
                        (int)pow(2,6)*d4+
                        (int)pow(2,7)*d5;
                        
                        
                        if (value==mask_value)
                            G_Array=1;
                    }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                    for (d4=0;d4<2;d4++)
                        for (d5=0;d5<2;d5++)
                        {
                            mask_value=1+
                            (int)pow(2,1)*d1+
                            (int)pow(2,2)*d2+
                            (int)pow(2,3)*d3+
                            (int)pow(2,4)*d4+
                            (int)pow(2,5)*d5+
                            (int)pow(2,6)+
                            (int)pow(2,7);
                            
                            
                            if (value==mask_value)
                                G_Array=1;
                        }
        
    }
    
    //tee branch
    
    if (G_Array==0)
    {
        //1
    for (d1=0;d1<2;d1++)
        for (d2=0;d2<2;d2++)
            for (d3=0;d3<2;d3++)
                for (d4=0;d4<2;d4++)
                    for (d5=0;d5<2;d5++)
                    {
                        mask_value=1+
                        (int)pow(2,1)*d1+
                        (int)pow(2,2)+
                        (int)pow(2,3)*d2+
                        (int)pow(2,4)+
                        (int)pow(2,5)*d3+
                        (int)pow(2,6)*d4+
                        (int)pow(2,7)*d5;
                        
                        
                        if (value==mask_value)
                            G_Array=1;
                    }
        //2
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                    for (d4=0;d4<2;d4++)
                        for (d5=0;d5<2;d5++)
                        {
                            mask_value=1*d1+
                            (int)pow(2,1)*d2+
                            (int)pow(2,2)+
                            (int)pow(2,3)*d3+
                            (int)pow(2,4)+
                            (int)pow(2,5)*d4+
                            (int)pow(2,6)+
                            (int)pow(2,7)*d5;
                            
                            
                            if (value==mask_value)
                                G_Array=1;
                        }
        //3
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                    for (d4=0;d4<2;d4++)
                        for (d5=0;d5<2;d5++)
                        {
                            mask_value=1+
                            (int)pow(2,1)*d1+
                            (int)pow(2,2)*d2+
                            (int)pow(2,3)*d3+
                            (int)pow(2,4)+
                            (int)pow(2,5)*d4+
                            (int)pow(2,6)+
                            (int)pow(2,7)*d5;
                            
                            
                            if (value==mask_value)
                                G_Array=1;
                        }
        //4
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                    for (d4=0;d4<2;d4++)
                        for (d5=0;d5<2;d5++)
                        {
                            mask_value=1+
                            (int)pow(2,1)*d1+
                            (int)pow(2,2)+
                            (int)pow(2,3)*d2+
                            (int)pow(2,4)*d3+
                            (int)pow(2,5)*d4+
                            (int)pow(2,6)+
                            (int)pow(2,7)*d5;
                            
                            
                            if (value==mask_value)
                                G_Array=1;
                        }
        
    }
    
    //ven branch
    //1
    if (G_Array==0)
    {for (d1=0;d1<2;d1++)
        for (d2=0;d2<2;d2++)
            for (d3=0;d3<2;d3++)
            {
                mask_value=42+
                1*d1+
                (int)pow(2,2)*d2+
                (int)pow(2,4)*d3;
                
                if (value==mask_value)
                    G_Array=1;
            }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=74+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=138+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=106+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=202+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=170+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=234+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,4)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        //2
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=42+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=41+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=168+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=43+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=170+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=169+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=171+
                    (int)pow(2,2)*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        //3
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=162+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=164+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=168+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=166+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=170+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=172+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=174+
                    1*d1+
                    (int)pow(2,4)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        //4
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=138+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=146+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=162+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=154+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=170+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=178+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
                for (d3=0;d3<2;d3++)
                {
                    mask_value=186+
                    1*d1+
                    (int)pow(2,2)*d2+
                    (int)pow(2,6)*d3;
                    
                    if (value==mask_value)
                        G_Array=1;
                }
    }
    
    //diagonal branch
    //1
    if (G_Array==0)
    {for (d1=0;d1<2;d1++)
        for (d2=0;d2<2;d2++)
        {
            mask_value=37+
            (int)pow(2,3)*d1+
            (int)pow(2,7)*d2;
            
            if (value==mask_value)
                G_Array=1;
        }
        //2
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
            {
                mask_value=82+
                (int)pow(2,3)*d1+
                (int)pow(2,7)*d2;
                
                if (value==mask_value)
                    G_Array=1;
            }
        //3
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
            {
                mask_value=148+
                (int)pow(2,1)*d1+
                (int)pow(2,5)*d2;
                
                if (value==mask_value)
                    G_Array=1;
            }
        //4
        for (d1=0;d1<2;d1++)
            for (d2=0;d2<2;d2++)
            {
                mask_value=73+
                (int)pow(2,1)*d1+
                (int)pow(2,5)*d2;
                
                if (value==mask_value)
                    G_Array=1;
            }
    }
    
    return G_Array;
}
