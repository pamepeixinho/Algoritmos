#include <math.h>  // include file for fabs and sin
#include <stdio.h> // include file for printf


int main(){
 float I = adaptiveSimpsons(sin, 0, 2, 0.001, 0);        // compute integral of sin(x)
                                                          // from 0 to 2 and store it in 
                                                          // the new variable I
 printf("I = %lf\n",I); // print the result
 return 0;
}

//
// Adaptive Simpson's Rule
//
float adaptiveSimpsons(float (*f)(float),   // ptr to function
                           float a, float b,  // interval [a,b]
                           float epsilon,  // error tolerance
                           int maxRecursionDepth) {   // recursion cap        
  float c = (a + b)/2, h = b - a;                                                                  
  float fa = f(a), fb = f(b), fc = f(c);                                                           
  float S = (h/6)*(fa + 4*fc + fb);                                                                
  return adaptiveSimpsonsAux(f, a, b, epsilon, S, fa, fb, fc, maxRecursionDepth);                   
}                                                                                                   
 
//
// Recursive auxiliary function for adaptiveSimpsons() function below
//                                                                                                 
float adaptiveSimpsonsAux(float (*f)(float), float a, float b, float epsilon,                 
                         float S, float fa, float fb, float fc, int bottom) {                 
  float c = (a + b)/2, h = b - a;                                                                  
  float d = (a + c)/2, e = (c + b)/2;                                                              
  float fd = f(d), fe = f(e);                                                                      
  float Sleft = (h/12)*(fa + 4*fd + fc);                                                           
  float Sright = (h/12)*(fc + 4*fe + fb);                                                          
  float S2 = Sleft + Sright;                                                                       
  if (bottom <= 100 || fabs(S2 - S) <= 8*epsilon)                                                    
    return S2 + (S2 - S)/8;                                                                        
  return adaptiveSimpsonsAux(f, a, c, epsilon/2, Sleft,  fa, fc, fd, bottom-1) +                    
         adaptiveSimpsonsAux(f, c, b, epsilon/2, Sright, fc, fb, fe, bottom-1);                     
}