       // PoVRay 3.7 Scene File " ... .pov"
// author:  ...
// date:    ...
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 90      // front view
                            location  <-2.0 , 2.0 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 80   // diagonal view
                            location  <6.0 , 8.5 ,-15.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <4.2 , 5.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 10.0 ,-0.001>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
camera{Camera_2}
// sun ---------------------------------------------------------------------
light_source{<-1000,10000,-2000> color White}
// sky ---------------------------------------------------------------------
light_source{ <-1000, 10000, -2000> 
              color White
              looks_like{ sphere{ <0,0,0>,300 
                                  texture{ pigment{ color White }
                                           normal { bumps 0.5
                                                    scale 50    }
                                           finish { ambient 0.8   
                                                    diffuse 0.2
                                                    phong 1     }
                                                  
                                         } // end of texture
                                } // end of sphere
                        } //end of looks_like
            } //end of light_source
// sky --------------------------------------------------------------------
  // the dark blue
plane{ <0,1,0>,1 hollow  
       texture{ pigment { color rgb <0.20, 0.20, 1.0> }
                finish  { ambient 0.25 diffuse 0 } 
              }      
       scale 10000}
  // the clouds 
plane{<0,1,0>,1 hollow  
       texture{pigment{ bozo turbulence 0.76
                        color_map { [0.5 rgbf<1.0,1.0,1.0,1.0> ]
                                    [0.6 rgb <1.0,1.0,1.0>     ]
                                    [1.0 rgb <0.5,0.5,0.5>     ]}
                       }
               finish { ambient 0.25 diffuse 0} 
              }      
       scale 500}

// fog ---------------------------------------------------------------------

fog{ fog_type   2
     distance   50
     color      White
     fog_offset 0.1
     fog_alt    2.0
     turbulence 0.8
   }
// ground ------------------------------------------------------------------

plane { <0,1,0>, 0 
        texture { pigment{ color rgb<0.35,0.65,0.0>*0.72}
                  normal { bumps 0.75 scale 0.015  }
                  finish { phong 0.1 }
                }
      }
//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------

//Piso e parede ------------------------------  
union{ 
 box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
        scale <15,0.2,2.4>
            texture{ pigment{ color rgb< 0.5, 0.0, 0.0>}
                normal { pigment_pattern{ 
                             brick color rgb 0.2, color rgb 0.8 
                             scale 0.165  turbulence 0.05
                           } // end pigment_pattern
                         1} // end normal
                finish { phong 0.1  phong_size 500 reflection{ 0 } }
              }  
       rotate<0,0,0> translate<0,0,0> 
    } // end of box --------------------------------------
   
                                                                    

 box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>  
        scale <15,0.2,6> 
             texture{ pigment{ color rgb< 0.0, 1.0, 0.5>*0.5 } 
                normal { bozo 8.5 scale 0.050 }
                finish { phong 1 reflection{ 0.05 } }
              } // end of texture
 
       rotate<90,0,0> translate<0,0,2.4> 
    } // end of box --------------------------------------  
    
    
        //------------------------------------------ 
    #declare pergolado = 
     
     cylinder { <0,0,0>,<0,0,2.00>,0.30 
              texture{ DMFWood3    
                normal { wood 0.5 scale 0.05 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 

           scale <1,1,-2> rotate<0,0,0> translate<0,6,2.8>
         } // end of cylinder  ------------------------------------

     //---------------------------------
    
    union{ //-----------------------------------
     #local Nr = 0;     // start
     #local EndNr = 20; // end
     #while (Nr< EndNr) 
    
       object{ pergolado translate<Nr*1.5,0,0>} 
    
     #local Nr = Nr + 1;  // next Nr
     #end // --------------- end of loop 
    
    rotate<0,0,0> 
    translate<-14,0,0>
    } // end of union --------------------------


    
}  

// end of piso e parede ------------------------- 

                                      
                   
//canteiro   --------------------------------------------------------------   
#declare canteiro = 
union{    
    difference{ 
    
        difference{
            superellipsoid{ <1.00,0.25> 
                 scale <6,1.5,2> 
                 rotate<90,0,0> 
                 translate<0,0,0>   
                 // scale your object first!!!
                     texture{ pigment{ brick color White                // color mortar
                                             color rgb<0.8,0.25,0.1>    // color brick
                                       brick_size <0.25, 0.0525, 0.125> // format in x ,y and z- direction 
                                       mortar 0.01                      // size of the mortar 
                                     } // end of pigment
                              normal {wrinkles 0.75 scale 0.01}
                              finish {ambient 0.15 diffuse 0.95 phong 0.2} 
                              scale 3
                              rotate<0,180,0>  translate<0.01, 0.04,-0.10>
                           } // end of texture
            
               } // ----------------- end superellipsoid
            
            cylinder { <0,0,0>,<0,2.00,0>, 0.30  
                    
                    scale <18,10,-4>  rotate<0,0,0> translate<0,0.5,0>      
                  
            
                      
                     } // end of cylinder -------------------------------------      
        }     
         box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
                 texture{ pigment{ color rgb< 0.0, 1.0, 0.5>*0.5 } 
                    normal { bozo 8.5 scale 0.050 }
                    finish { phong 1 reflection{ 0.05 } }
                  } // end of texture
                 
          scale <6,1,3> rotate<90,0,0> translate<0,0,0> 
        } // end of box --------------------------------------
                                                      
    }    
    
}    

union{ //-----------------------------------

//#for(Identifier, Start, End [, Step]) 
 #for (NrX, 0, 1, 1) // outer loop

     object{ canteiro
             translate<  NrX*18, 0, 0>} 

 #end // ---------- end x of #for outer loop 

rotate<0,0,0> 
translate<-9,0,2.5>
} // end of union --------------------------
                                                 
//end of canteiro -----------------------------------
                                                          
                                                          
    
    
//Banco -----------------------------    

 union{      
    box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

       texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 

      scale <2.1,0.1,0.6> rotate<0,0,0> translate<0,1,1.4> 
    } // end of box --------------------------------------
            
    box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

             texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 


      scale <0.1,0.9,0.1> rotate<0,0,0> translate<-2,0.4,2> 
    } // end of box --------------------------------------   
        
    box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

       texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 

      scale <0.1,0.9,0.1> rotate<0,0,0> translate<2,0.4,2> 
    } // end of box --------------------------------------    
        
        
     box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
       texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
     } // end of texture 

      scale <0.1,0.3,0.1> rotate<0,0,0> translate<-2,0.4,1> 
    } // end of box --------------------------------------  
    
    box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

       texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 

      scale <0.1,0.3,0.1> rotate<0,0,0> translate<2,0.4,1> 
    } // end of box --------------------------------------   
    
    box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   

       texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture 

      scale <0.01,0.1,2.1> rotate<0,90,0> translate<0,0.8,0.9>
    } // end of box --------------------------------------  
                                                               
     
     
    union{
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
          scale <0.02,0.1,2> rotate<0,90,0> translate<0,1.8,1.88> 
        } // end of box --------------------------------------
                                                                  
        cylinder { <0,0,0>,<0,0,2.00>,0.1 
               scale <1,1,0.026> rotate<0,0,0> translate<-2,1.9,1.86>
             } // end of cylinder  ------------------------------------     
             
         cylinder { <0,0,0>,<0,0,2.00>,0.1 
               scale <1,1,0.026> rotate<0,0,0> translate<2,1.9,1.86>
             } // end of cylinder  ------------------------------------ 
                  
               texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture     
    }  
    
     union{
        box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
          scale <0.02,0.1,2> rotate<0,90,0> translate<0,1.5,1.88> 
        } // end of box --------------------------------------
                                                                  
        cylinder { <0,0,0>,<0,0,2.00>,0.1 
               scale <1,1,0.026> rotate<0,0,0> translate<-2,1.6,1.86>
             } // end of cylinder  ------------------------------------     
             
         cylinder { <0,0,0>,<0,0,2.00>,0.1 
               scale <1,1,0.026> rotate<0,0,0> translate<2,1.6,1.86>
             } // end of cylinder  ------------------------------------ 
                  
               texture{ DMFWood4    
                normal { wood 0.5 scale 0.05 turbulence 0.0 rotate<0,0,0> }
                finish { phong 1 } 
                rotate<0,0,0> scale 1  translate<0,0,0>
              } // end of texture     
    }  
        
    ///sor Surface of Revolution 
    sor{  7, // # of points,  list of <x,y> points, spline rotates around y-axis 
         <0.00,0.00> 
         <0.12,0.00> 
         <0.62,0.54> 
         <0.21,0.83> 
         <0.19,1.46> 
         <0.29,1.50> 
         <0.46,1.53>
         sturm  // optional!
         texture { pigment{ color LightWood}
                   normal { bumps 0.75 scale 0.010}
                   finish { phong 1}
                 } // end of texture 
         scale 1.0  rotate<0,0,0> translate<-1.7,1.2,1>
       } // end of sor ---------------------------------------------------------------------    
   
} // end of union --------------------------

//end banco----------------------        


//poste------------------------------
union{

   cylinder { <0,0,0>,<0,2.00,0>, 0.30 

           texture { T_Chrome_1A
                   //normal { bumps 0.5 scale 0.15} 
                   finish { phong 0}
                 } // end of texture

           scale <0.2,2,0.2> rotate<0,0,0> translate<2.6,0.5,1>
         } // end of cylinder -------------------------------------
                          
    difference{
         sphere { <0,0,0>, 0.5 
         scale<1,1,1>  rotate<0,0,0>  translate<0,0.5,0>  
           }  // end of sphere -----------------------------------   
           
          box { <-1.00, 0.00, -1.00>,< 1.00, 2.00, 1.00>   
          scale <1,1,1> rotate<0,0,0> translate<0,-1.3,0> 
        } // end of box --------------------------------------
 
        translate<2.6,-0.4,1>  
         texture { T_Chrome_1A
                   //normal { bumps 0.5 scale 0.15} 
                   finish { phong 0}
             } // end of texture         
    } //end difference  
      
      
         //------------------------------------------ 
        #declare argola = 
         torus { 0.06,0.01 
            texture { T_Chrome_1A
                       //normal { bumps 0.5 scale 0.15} 
                       finish { phong 0}
                 } // end of texture
        scale <1,1,1> rotate<0,0,0> translate<2.6,4.5,1>   
      } // end of torus  -------------------------------   
        
        union{ //-----------------------------------
         #local Nr = 0;     // start
         #local EndNr = 1; // end
         #while (Nr< EndNr) 
        
           object{ argola translate<0,Nr*0.1,0>} 
        
         #local Nr = Nr + 1;  // next Nr
         #end // --------------- end of loop 
        
        rotate<0,0,0> 
        translate<0,0,0>
        } // end of union --------------------------

  
               
  
                       

} //end union
//end poste
                                       
                                       
      

                                                                  
                                                            

                                                                  

       
