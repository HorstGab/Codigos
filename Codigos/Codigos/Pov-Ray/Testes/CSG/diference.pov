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


#declare D = 0.001; // just a little bit!
difference{
box{ <-0.5,0.0,-0.1>,< 0.5,1.0,0.1>
     texture{ pigment{ color rgb<1,0.65,0>}
              finish { phong 1.0 }}
   }
box{ <-0.3,0.2,-0.1-D>,< 0.3,0.8,0.1+D>
     texture{ pigment{ color Magenta }
              finish { phong 1.0 }}
   }
rotate<0,-30,0> translate<0,0,0>}

light_source {<2,4, -2> color White}