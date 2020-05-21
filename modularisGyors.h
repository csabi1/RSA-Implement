#include <iostream> 
#include <boost/multiprecision/cpp_int.hpp>
using namespace std; 
namespace mp = boost::multiprecision; 
/* Moduláris gyorshatványozás, ahol addig kerülnek
 * szorzásra az elemek, amíg páros számot nem talál, tehát amikor felülröl, 
 * legnagyobb számot el nem éri.*/
mp::cpp_int gyorsHatvany(mp::cpp_int alap, mp::cpp_int kitevo, mp::cpp_int mod)  
{  
    mp::cpp_int res = 1;     
  
  
    // Az alap frisítése, amennyiben nagyob lenne mint a modulus
    alap = alap % mod;  
 
    if (alap == 0) return 0; 
  
    while (kitevo > 0)  
    {   
        // Amennyiben, a kitevő páratlan, az eredménybe beszorozzuk az aktuális alapot

        if (kitevo % 2)  
            res = (res*alap) % mod;  
  
        // A kitevőt megfelezzük, az alapot négyzetreemeljük.
        kitevo = kitevo / 2;  
        alap = (alap*alap) % mod;  
    }  
    return res;  
}  
  
 
