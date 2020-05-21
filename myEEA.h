	#include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
    namespace mp = boost::multiprecision;
	using namespace std; 

/*Kiterjesztett euklédeszi algoritmus.
 * Alap esetben ( mikor a rekurzió, leért, az utolsó szinthez)
 * feltölti, az x-et 0 val, az y-t 1 el és visszatér a b értékkel (lnko).
 * A függvény két segédváltozót használ x1, y2, hogy a rekurzió adatait tárolhassa.
 * Miután a rekurziv hívások visszatérnek, folyamatosan tölti fel az
 * *x és *y értéket.
 * */
mp::cpp_int extendedEA(mp::cpp_int a, mp::cpp_int b, mp::cpp_int *x, mp::cpp_int *y)  
{  
    if (0 == a){  
	    *x = 0;  *y = 1;  
        return b;  
    }  
    mp::cpp_int x1, y1;  mp::cpp_int EEA = extendedEA(b%a, a, &x1, &y1);   
    *x = y1 - (b/a) * x1;  
    *y = x1;    
    return EEA;  
}  
  

