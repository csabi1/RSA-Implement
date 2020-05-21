    #include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>

    #include "myMillerRabin.h" // benne van a modularisGyors.h is.
    #include <stdlib.h>     /* srand, rand */
	#include <time.h>       /* time */
	
    namespace mp = boost::multiprecision;
    
    /* Random prímek generál, MR-al tesztelve.
     * FONTOS: a meghívásához szükséges a 
     * #include <time.h> importálása és
     *  a srand (time(NULL)); inicializálása.
     * */
   mp::cpp_int primGenerator()
   {
	     
		mp::cpp_int myRandomPrime;
		

		/* Random szám generálás jelenleg, 10000 és 1000 között.: */
  
		while (!valosPrimTeszt(myRandomPrime,4)){
		myRandomPrime = rand() % 10000 + 1000;
		} 
		return myRandomPrime;

   }
  
