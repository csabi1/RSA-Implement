#include <iostream>
#include <stdlib.h>
#include <boost/multiprecision/cpp_int.hpp>
 #include "modularisGyors.h"
namespace mp = boost::multiprecision;
using namespace std;

/* Tényleges Miller-Rabin teszt.
 * A függvény megkapja a már számból lebontott d-t és az aktuális számot.
 * false értékkel tér vissza, ha n összetett, és true értékkel, ha n prím
 * vagy összetett.
 * */
bool miillerRabinTest(mp::cpp_int d, mp::cpp_int bemenet) 
{ 
    mp::cpp_int bazis = 2 + rand() % (bemenet - 4); 
  
    // Egy x változóban eltároljuk a moduláris, gyorhatványozás eredményét. 
    mp::cpp_int x = gyorsHatvany(bazis, d, bemenet); 
     
     
    //Amennyiben 1 -el vagy moduláris aritmetika szerinti -1 el tér vissza,
    //akkor az adott szám biztos prím.
    if (x == 1  || x == bemenet-1) 
       return true; 
  
 
    //Addig emeli négyzetre, az x-et amíg, el nem éri a határt (bemenet-1)
    //vagy az x négyzet mod bemenet == 1
    //vagy az x négyzet mod bemenet == bemenet - 1 
    while (d != bemenet-1) 
    { 
        x = (x * x) % bemenet; 
        d = d * 2; 
  
        if (x == 1)      
        { return false ;
			}
        
        //Aritmetikai, -1 tehát ez egy prím vagy összetett.
        if (x == bemenet-1)  
        {  return true ;
			}
    } 
  
    // Összetettként tér vissza. 
    return false; 
} 
  
/* A valóságos prím tesztelés, itt történik.
 * A függvény kiszamolja az adott számra a d-t, a Miller-Rabin számára átadásra.
 * Majd a kapott paraméterszer meghívja a tesztet.
 * True-t ad vissza ha prím false-t egyébként.
 * */
bool valosPrimTeszt(mp::cpp_int bemenet, mp::cpp_int tesztSzorzo) 
{ 
    if (bemenet <= 1 || bemenet == 4)  return false; 
    
    //Ha a bemenet kettö akkor biztos prím.
    if (bemenet <= 3) return true; 
    mp::cpp_int d = bemenet - 1; 
    while (d % 2 == 0) { d = d/2;}
    for (mp::cpp_int i = 0; i < tesztSzorzo; i++) 
         if (!miillerRabinTest(d, bemenet)) 
              return false; 
  
    return true; 
} 
  
