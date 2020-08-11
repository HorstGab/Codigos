#include "colors.inc"         //cores
#include "stones.inc"         //textura de pedra

#include "textures.inc"        //textura
#include "shapes.inc"         //formas
#include "glass.inc"          //vidro
#include "metals.inc"         //metal
#include "woods.inc"          //madeira
          
          
background { color rgb<0, 1, 2> }     //cor de fundo
          
camera{                      //adiciona camera
    location<0,2,-4>          //eixos x, y, e Z
    look_at<0,1,0>      
    angle 48
}  

plane { <0, 1, 0>, -1
	pigment {
		checker color Black, color White
	}
} 

union{
  sphere{<0,1,0>,0.35}
  cone{<0,0,0>,0.45,<0,1.2,0>,0}
  texture{T_Glass3} interior{I_Glass}
  translate <-0.5, 0, 0>
     }
merge{ 
  sphere{<0,1,0>,0.35}
  cone{<0,0,0>,0.45,<0,1.2,0>,0}
  texture{T_Glass3} interior{I_Glass}
  translate < 0.5, 0, 0>
     }                  

light_source {<2,4, -2> color White}