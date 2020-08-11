#include "colors.inc"         //cores
#include "stones.inc"         //textura de pedra

#include "textures.inc"        //textura
#include "shapes.inc"         //formas
#include "glass.inc"          //vidro
#include "metals.inc"         //metal
#include "woods.inc"          //madeira

background { color Blue }     //cor de fundo

camera{                      //adiciona camera
    location<1,4,-7>          //eixos x, y, e Z
    look_at<0,1,0>
}    

/*sphere{                      //eixos de inicializa��o, raio da esfera
    <-4,1,2>, 0.75               //textura
    texture{                 //pigmento
        pigment{             //cor amarelo
            color Yellow
        }
    }
}*/

  sphere {
    <-4,3,2>, 0.75
    texture {
      pigment { color rgbf <1,0,0,1>} //Yellow is pre-defined in COLORS.INC
      finish { phong 1 }
    }
  } 

box { 
	<-1, 0.5, -3>, // canto inferior esquedo 
	< 1, 1, -1> // canto superior direito 
	texture { 
		T_Stone25 // Pre-defined from stones.inc 
		scale 7 // Scale by the same amount in all directions 
	} 
	rotate y*50 // Equivalent to "rotate <0,60,0>" 
} 

cone { 
	<2, 1, 0>, 0 // Center and radius of one end 
	<3, 2, 3>, 1.0 // Center and radius of other end 
	open // Removes end caps 
	texture { T_Stone20 	scale 1 	} 
} 

cylinder { 
	<-1, 2, -1>, // Center of one end 
	<0, 3, 2>, // Center of other end 
	0.4 // Radius 
	open // Remove end caps 
	texture { T_Stone24 scale 0 } 
} 

plane { <0, 1, 0>, -1
	pigment {
		checker color Black, color White
	}
}

torus { 
	0.4, 0.2 // major and minor radius 
	rotate -90*x // so we can see it from the top  
	translate <1.8, 0, -1.5>
	pigment { Magenta }
}     

light_source {<2,4, -2> color White}    //fonte de luz
