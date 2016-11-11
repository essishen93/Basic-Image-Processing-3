This README file is the Introduction of "EE569_hw3_4946850713_Shen.zip" and 
                    the Guidance of compiling and running the projects.

#################################################

All the projects were built on Xcode(7.0.1), OS X (10.10.5)

#################################################

The Steps of running a projects: (Xcode)
1) open Xcode
2) open a project in the "EE569_hw3_4946850713_Shen.zip"
3) click “command+B” to build 
4) click “command+R” to run

#################################################
  
Problem 1 (a):   implement the swirl effect of the image

Project:         Swirl_Effect->Swirl_Effect(.xcodeproj)

Source File:     main.cpp 

Input Image:     kate.raw

Output Image:    kate_swirl.raw


#################################################
  
Problem 1 (b):   capture a scene in the 3D world 

Project:         Perspect_Trans->Perspect_Trans(.xcodeproj)

Source File:     main.cpp 

Input Image:     baby_dog.raw
                 baby_cat.raw
                 baby_panda.raw

Output Image:    2D_image.raw

#################################################

  
Problem 2 (a):   implement digital halftoning by dithering 

Project:         Dithering->Dithering(.xcodeproj)

Source File:     main.cpp 

Input Image:     mandrill.raw

Output Image:    mandrill_4.raw    (4X4 Bayer’s matrix)
                 mandrill_8.raw    (8X8 Bayer’s matrix)
                 mandrill_mul.raw  (4-gray-level image)

#################################################
  
Problem 2 (b):   implement digital halftoning by error diffussion 

Project:         Error_Diffusion->Error_Diffusion(.xcodeproj)

Source File:     main.cpp 

Input Image:     mandrill.raw

Output Image:    mandrill_F.raw    (Floyd-Steinberg's)
                 mandrill_J.raw    (JJN)
                 mandrill_S.raw    (Stucki's)

#################################################
  
Problem 2 (c):   implement scalar color halftoning 

Project:         Scalar_Color->Scalar_Color(.xcodeproj)

Source File:     main.cpp 

Input Image:     Sailboat.raw

Output Image:    Sailboat_scl.raw

#################################################
  
Problem 2 (d):   implement vector color halftoning 

Project:         Vector_Color->Vector_Color(.xcodeproj)

Source File:     main.cpp
                 Get_Error.cpp 
                 function.h

Input Image:     Sailboat.raw

Output Image:    Sailboat_vec.raw

#################################################
  
Problem 3 (a):   shrinking the binary image 

Project:         Shrink->Shrink(.xcodeproj)

Source File:     main.cpp
                 getM.cpp
                 getG.cpp 
                 function.h

Input Image:     Horseshoe.raw

Output Image:    Horseshoe_S.raw        (the result of shrinking)
                 Horseshoe_object.raw   (counting objects)

#################################################
  
Problem 3 (b):   thinning the binary image 

Project:         Thin->Thin(.xcodeproj)

Source File:     main.cpp
                 getM.cpp
                 getG.cpp 
                 function.h

Input Image:     Horse1.raw

Output Image:    Horse1_T_un.raw   (without pre-processing)
                 Horse1_T.raw      (with    pre-processing)

#################################################
  
Problem 3 (b):   skeletoning the binary image 

Project:         Skeleton->Skeleton(.xcodeproj)

Source File:     main.cpp
                 getM.cpp
                 getG.cpp 
                 function.h

Input Image:     Horse1.raw

Output Image:    Horse1_K_un.raw   (without pre-processing)
                 Horse1_K.raw      (with    pre-processing)

#################################################
