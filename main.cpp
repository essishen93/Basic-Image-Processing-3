//Name: Maoru Shen
//USC ID Number: 4946-8507-13
//USC Email: maorushe@usc.edu
//Submission Date: 11/01/2015
////////////////////////////////////////////////////////////////////
//Problem 3 : (b)
//This code is to skeletoning the binary image
/////////////////////////////////////////////////////////////////////
//main.cpp
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "function.h"
using namespace std;

const int Size_H=275;    //the size of input image
const int Size_W=360;    //the size of input image

int get_M(int bone, int value); //get M Array after the first stage
int get_G(int value);           //get G Array after the sencond stage

//the function for hole filling
void hole_fill(unsigned char * fIn_Image, int pI,int qI)
{
    if (fIn_Image[(pI-1)*Size_W+qI]==0)
    {
        fIn_Image[(pI-1)*Size_W+qI]=1;
        hole_fill(fIn_Image,pI-1, qI);
    }
    if (fIn_Image[(pI+1)*Size_W+qI]==0)
    {
        fIn_Image[(pI+1)*Size_W+qI]=1;
        hole_fill(fIn_Image,pI+1, qI);
        
    }
    if (fIn_Image[pI*Size_W+qI-1]==0)
    {
        fIn_Image[pI*Size_W+qI-1]=1;
        hole_fill(fIn_Image,pI, qI-1);
    }
    
    if (fIn_Image[pI*Size_W+qI+1]==0)
    {
        fIn_Image[pI*Size_W+qI+1]=1;
        hole_fill(fIn_Image,pI, qI+1);
    }
}

int  main()
{
    
    int pO=0,qO=0;    //the Image coordinate of output
    int pI=0,qI=0;    //the Image coordinate of input
    
    unsigned char CIn_Image  [Size_H][Size_W];         //the image data of input image
    unsigned char In_Image   [Size_H][Size_W];         //the image data of input image (0-1)
    unsigned char fIn_Image  [Size_H*Size_W];          //the image data of input image (1 dimension)
    unsigned char tIn_Image  [Size_H][Size_W]={0};     //the image data of image after dilation
    unsigned char M_Array    [Size_H][Size_W]={0};     //M Array
    unsigned char G_Array    [Size_H][Size_W]={0};     //G Array
    unsigned char Out_Image  [Size_H][Size_W]={0};     //the image data of thinning image with    pre-processing
    unsigned char uOut_Image [Size_H][Size_W]={0};     //the image data of thinning image without pre-processing
    
    
    ///////////////Read image///////////////
    ifstream ifile("Horse1.raw",ios_base::in | ios_base::binary);
    if (!ifile)
    {
        cout<<"File CANNOT open!"<<endl;
        exit(1);
    }
    for (pI=0;pI<Size_H;pI++)
        for (qI=0;qI<Size_W;qI++)
        {
            ifile.read((char*)&CIn_Image[pI][qI],sizeof(CIn_Image[pI][qI]));
            if (CIn_Image[pI][qI]==255)
                In_Image[pI][qI]=1;
            else
                In_Image[pI][qI]=0;
            
            if (CIn_Image[pI][qI]==255)
                fIn_Image[pI*Size_W+qI]=1;
            else
                fIn_Image[pI*Size_W+qI]=0;
        }
    ifile.close();
    
    
    
    
    int bone=0;
    int side_conn=0;
    int corn_conn=0;
    int value=0;
    int times=1;int i=0; //the times of iteration
    
    ////////////////Skeletoning//////////////////////
    ////////Without pre-processing////////////////
    while (times)
        //for(i=0;i<70;i++)
    {
        i++;
        //initial M array and G array
        for (pI=0;pI<Size_H;pI++)
            for (qI=0;qI<Size_W;qI++)
            {
                M_Array[pI][qI]=0;
                G_Array[pI][qI]=0;
            }
        for (pI=1;pI<Size_H-1;pI++)
            for (qI=1;qI<Size_W-1;qI++)
            {
                if (In_Image[pI][qI]==1)
                {
                    //coding every 3x3 window to binary number (0-255)
                    value=In_Image[pI][qI+1]+
                    (int)pow(2,1)*In_Image[pI-1][qI+1]+
                    (int)pow(2,2)*In_Image[pI-1][qI]+
                    (int)pow(2,3)*In_Image[pI-1][qI-1]+
                    (int)pow(2,4)*In_Image[pI][qI-1]+
                    (int)pow(2,5)*In_Image[pI+1][qI-1]+
                    (int)pow(2,6)*In_Image[pI+1][qI]+
                    (int)pow(2,7)*In_Image[pI+1][qI+1];
                    
                    //compute the bone
                    side_conn=In_Image[pI][qI-1]+In_Image[pI][qI+1]+In_Image[pI-1][qI]+In_Image[pI+1][qI];
                    corn_conn=In_Image[pI-1][qI-1]+In_Image[pI-1][qI+1]+In_Image[pI+1][qI-1]+In_Image[pI+1][qI+1];
                    bone=2*side_conn+corn_conn;
                    
                    //obtain the M_array, find the candidate for removal
                    M_Array[pI][qI]=get_M(bone,value);
                    
                }
            }
        
        for (pI=1;pI<Size_H-1;pI++)
            for (qI=1;qI<Size_W-1;qI++)
            {
                if (M_Array[pI][qI]==1)
                {
                    //coding every 3x3 window to binary number (0-255)
                    value=M_Array[pI][qI+1]+
                    (int)pow(2,1)*M_Array[pI-1][qI+1]+
                    (int)pow(2,2)*M_Array[pI-1][qI]+
                    (int)pow(2,3)*M_Array[pI-1][qI-1]+
                    (int)pow(2,4)*M_Array[pI][qI-1]+
                    (int)pow(2,5)*M_Array[pI+1][qI-1]+
                    (int)pow(2,6)*M_Array[pI+1][qI]+
                    (int)pow(2,7)*M_Array[pI+1][qI+1];
                    
                    //obtain the G_array, find the candidate for not removal
                    G_Array[pI][qI]=get_G(value);
                    
                    
                }
            }
        
        //get the final points for removal
        for (pO=0;pO<Size_H;pO++)
            for (qO=0;qO<Size_W;qO++)
            {
                if (G_Array[pO][qO]==1)
                    M_Array[pO][qO]=0;
                else
                    M_Array[pO][qO]=M_Array[pO][qO];
            }
        times=0;
        for (pO=0;pO<Size_H;pO++)
            for (qO=0;qO<Size_W;qO++)
            {
                if (M_Array[pO][qO]==1)
                {
                    In_Image[pO][qO]=0;
                    times=1;
                }
                else
                    In_Image[pO][qO]=In_Image[pO][qO];
            }
        if (times==0)
            cout<<"The times of iteration is (without pre-processing) "<<i<<endl;
    }
    
    
    ///////////////////Write image/////////////////////
    ofstream ufile("Horse1_K_un.raw",ios_base::out | ios_base::binary);
    if (!ufile)
    {
        cout<<"open failed"<<endl;
        exit(1);
    }
    for (pO=0;pO<Size_H;pO++)
        for (qO=0;qO<Size_W;qO++)
        {
            
            if (In_Image[pO][qO]==1)
                uOut_Image[pO][qO]=255;
            else
                uOut_Image[pO][qO]=0;
            
            
            uOut_Image[pO][qO]=uOut_Image[pO][qO]+0x00;    //Convert to hex or bin
            ufile.write((char*)&uOut_Image[pO][qO],sizeof(uOut_Image[pO][qO]));
        }
    ufile.close();
    
    
    for (pI=0;pI<Size_H;pI++)
        for (qI=0;qI<Size_W;qI++)
        {
            if (CIn_Image[pI][qI]==255)
                In_Image[pI][qI]=1;
            else
                In_Image[pI][qI]=0;
        }
    
    //////////////Pre-processing///////////////
    //hole-filling
    int hole_value=0;
    for (pI=10;pI<31;pI++)
        for (qI=15;qI<56;qI++)
        {
            if (fIn_Image[pI*Size_W+qI]==0)
            {
                hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                fIn_Image[(pI+1)*Size_W+qI]+
                fIn_Image[pI*Size_W+qI-1]+
                fIn_Image[pI*Size_W+qI+1];
                
                if (hole_value==4)
                    fIn_Image[pI*Size_W+qI]=1;
                else
                {
                    if (pI>=2)
                    {
                        pI=pI-2;qI=qI;
                        hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                        fIn_Image[(pI+1)*Size_W+qI]+
                        fIn_Image[pI*Size_W+qI-1]+
                        fIn_Image[pI*Size_W+qI+1];
                        if (hole_value==4)
                        {
                            pI=pI+2;qI=qI;
                            fIn_Image[pI*Size_W+qI]=1;
                            hole_fill(fIn_Image,pI,qI);
                        }
                        else
                            pI=pI+2;qI=qI;
                    }
                    
                    
                }
            }
            
        }
    
    for (pI=35;pI<171;pI++)
        for (qI=86;qI<133;qI++)
        {
            if (fIn_Image[pI*Size_W+qI]==0)
            {
                hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                fIn_Image[(pI+1)*Size_W+qI]+
                fIn_Image[pI*Size_W+qI-1]+
                fIn_Image[pI*Size_W+qI+1];
                
                if (hole_value==4)
                    fIn_Image[pI*Size_W+qI]=1;
                else
                {
                    if (pI>=2)
                    {
                        pI=pI-2;qI=qI;
                        hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                        fIn_Image[(pI+1)*Size_W+qI]+
                        fIn_Image[pI*Size_W+qI-1]+
                        fIn_Image[pI*Size_W+qI+1];
                        if (hole_value==4)
                        {
                            pI=pI+2;qI=qI;
                            fIn_Image[pI*Size_W+qI]=1;
                            hole_fill(fIn_Image,pI,qI);
                        }
                        else
                            pI=pI+2;qI=qI;
                    }
                    
                    
                }
            }
            
        }
    
    for (pI=92;pI<163;pI++)
        for (qI=134;qI<286;qI++)
        {
            if (fIn_Image[pI*Size_W+qI]==0)
            {
                hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                fIn_Image[(pI+1)*Size_W+qI]+
                fIn_Image[pI*Size_W+qI-1]+
                fIn_Image[pI*Size_W+qI+1];
                
                if (hole_value==4)
                    fIn_Image[pI*Size_W+qI]=1;
                else
                {
                    if (pI>=2)
                    {
                        pI=pI-2;qI=qI;
                        hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                        fIn_Image[(pI+1)*Size_W+qI]+
                        fIn_Image[pI*Size_W+qI-1]+
                        fIn_Image[pI*Size_W+qI+1];
                        if (hole_value==4)
                        {
                            pI=pI+2;qI=qI;
                            fIn_Image[pI*Size_W+qI]=1;
                            hole_fill(fIn_Image,pI,qI);
                        }
                        else
                            pI=pI+2;qI=qI;
                    }
                    
                    
                }
            }
            
        }
    
    for (pI=0;pI<Size_H;pI++)
        for (qI=0;qI<Size_W;qI++)
        {
            if (fIn_Image[pI*Size_W+qI]==0)
            {
                hole_value=fIn_Image[(pI-1)*Size_W+qI]+
                fIn_Image[(pI+1)*Size_W+qI]+
                fIn_Image[pI*Size_W+qI-1]+
                fIn_Image[pI*Size_W+qI+1];
                
                if (hole_value==4)
                    fIn_Image[pI*Size_W+qI]=1;
            }
            
        }
    
    pI=174;qI=124;
    fIn_Image[pI*Size_W+qI]=1;
    hole_fill(fIn_Image,pI,qI);
    
    pI=96;qI=290;
    fIn_Image[pI*Size_W+qI]=1;
    hole_fill(fIn_Image,pI,qI);
    
    pI=169;qI=295;
    fIn_Image[pI*Size_W+qI]=1;
    hole_fill(fIn_Image,pI,qI);
    
    pI=208;qI=292;
    fIn_Image[pI*Size_W+qI]=1;
    hole_fill(fIn_Image,pI,qI);
    
    pI=217;qI=335;
    fIn_Image[pI*Size_W+qI]=1;
    hole_fill(fIn_Image,pI,qI);
    
    
    for (pI=0;pI<Size_H;pI++)
        for (qI=0;qI<Size_W;qI++)
        {
            
            if (fIn_Image[pI*Size_W+qI]==1)
                In_Image[pI][qI]=1;
            else
                In_Image[pI][qI]=0;
        }
    
    //smoothing the boundary: erosion after dilation
    //dilation
    
    int j=0,k=0;
    int R=1;        //the radius of erosion and dilation
    for (pI=R;pI<Size_H-R;pI++)
        for (qI=R;qI<Size_W-R;qI++)
        {
            
            if (In_Image[pI][qI]==1)
            {
                for (j=-R;j<R+1;j++)
                    for (k=-R;k<R+1;k++)
                        tIn_Image[pI+j][qI+k]=1;
                
            }
        }
    
    
    for (pI=0;pI<Size_H;pI++)
        for (qI=0;qI<Size_W;qI++)
            In_Image[pI][qI]=0;
    
    //erosion
    int t_value=0;
    for (pI=R;pI<Size_H-R;pI++)
        for (qI=R;qI<Size_W-R;qI++)
        {
            
            if (tIn_Image[pI][qI]==1)
            {
                t_value=0;
                //for (j=-R;j<R+1;j++)
                    //for (k=-R;k<R+1;k++)
                        //t_value+=tIn_Image[pI+j][qI+k];
                t_value=tIn_Image[pI-1][qI]+tIn_Image[pI+1][qI]+tIn_Image[pI][qI-1]+tIn_Image[pI][qI+1];
                
                //if (t_value==((2*R+1)*(2*R+1)))
                if (t_value==4)
                {
                    In_Image[pI][qI]=1;
                }
                else
                    In_Image[pI][qI]=0;
            }
            else
                In_Image[pI][qI]=0;
            
        }
    
    ////////////////Skeletoning//////////////////////
    ////////With pre-processing////////////////
    times=1;
    i=0;
    while (times)
        //for(i=0;i<70;i++)
    {
        i++;
        //initial M array and G array
        for (pI=0;pI<Size_H;pI++)
            for (qI=0;qI<Size_W;qI++)
            {
                M_Array[pI][qI]=0;
                G_Array[pI][qI]=0;
            }
        for (pI=1;pI<Size_H-1;pI++)
            for (qI=1;qI<Size_W-1;qI++)
            {
                if (In_Image[pI][qI]==1)
                {
                    //coding every 3x3 window to binary number (0-255)
                    value=In_Image[pI][qI+1]+
                    (int)pow(2,1)*In_Image[pI-1][qI+1]+
                    (int)pow(2,2)*In_Image[pI-1][qI]+
                    (int)pow(2,3)*In_Image[pI-1][qI-1]+
                    (int)pow(2,4)*In_Image[pI][qI-1]+
                    (int)pow(2,5)*In_Image[pI+1][qI-1]+
                    (int)pow(2,6)*In_Image[pI+1][qI]+
                    (int)pow(2,7)*In_Image[pI+1][qI+1];
                    
                    //compute the bone
                    side_conn=In_Image[pI][qI-1]+In_Image[pI][qI+1]+In_Image[pI-1][qI]+In_Image[pI+1][qI];
                    corn_conn=In_Image[pI-1][qI-1]+In_Image[pI-1][qI+1]+In_Image[pI+1][qI-1]+In_Image[pI+1][qI+1];
                    bone=2*side_conn+corn_conn;
                    
                    //obtain the M_array, find the candidate for removal
                    M_Array[pI][qI]=get_M(bone,value);
                    
                }
            }
        
        for (pI=1;pI<Size_H-1;pI++)
            for (qI=1;qI<Size_W-1;qI++)
            {
                if (M_Array[pI][qI]==1)
                {
                    //coding every 3x3 window to binary number (0-255)
                    value=M_Array[pI][qI+1]+
                    (int)pow(2,1)*M_Array[pI-1][qI+1]+
                    (int)pow(2,2)*M_Array[pI-1][qI]+
                    (int)pow(2,3)*M_Array[pI-1][qI-1]+
                    (int)pow(2,4)*M_Array[pI][qI-1]+
                    (int)pow(2,5)*M_Array[pI+1][qI-1]+
                    (int)pow(2,6)*M_Array[pI+1][qI]+
                    (int)pow(2,7)*M_Array[pI+1][qI+1];
                    
                    //obtain the G_array, find the candidate for not removal
                    G_Array[pI][qI]=get_G(value);
                    
                    
                }
            }
        
        //get the final points for removal
        for (pO=0;pO<Size_H;pO++)
            for (qO=0;qO<Size_W;qO++)
            {
                if (G_Array[pO][qO]==1)
                    M_Array[pO][qO]=0;
                else
                    M_Array[pO][qO]=M_Array[pO][qO];
            }
        times=0;
        for (pO=0;pO<Size_H;pO++)
            for (qO=0;qO<Size_W;qO++)
            {
                if (M_Array[pO][qO]==1)
                {
                    In_Image[pO][qO]=0;
                    times=1;
                }
                else
                    In_Image[pO][qO]=In_Image[pO][qO];
            }
        if (times==0)
            cout<<"The times of iteration is (with pre-processing) "<<i<<endl;
    }
    
    
    ///////////////////Write image/////////////////////
    ofstream ofile("Horse1_K.raw",ios_base::out | ios_base::binary);
    if (!ofile)
    {
        cout<<"open failed"<<endl;
        exit(1);
    }
    for (pO=0;pO<Size_H;pO++)
        for (qO=0;qO<Size_W;qO++)
        {
            
            if (In_Image[pO][qO]==1)
                Out_Image[pO][qO]=255;
            else
                Out_Image[pO][qO]=0;
            
            
            Out_Image[pO][qO]=Out_Image[pO][qO]+0x00;    //Convert to hex or bin
            ofile.write((char*)&Out_Image[pO][qO],sizeof(Out_Image[pO][qO]));
        }
    
    ofile.close();
    
    cout<<"The end!"<<endl;
    getchar();
    return 0;
}
