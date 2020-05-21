    #include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
    #include "myEEA.h"
    using namespace std;
    namespace mp = boost::multiprecision;
   
   // Megnézi, hogy egy adott a és b szám relatív prímek.
 
   bool relativPrim (mp::cpp_int a, mp::cpp_int b) { 
   return (a<b) ? relativPrim(b,a) : !(a%b) ? (b==1) : relativPrim (b, a%b);
   }
   
   
   
   // Létrehozza a FI értékét.
   mp::cpp_int findFI(mp::cpp_int p, mp::cpp_int q)
   { return (p-1)*(q-1); }
  
   // d érték keresése, ha negatív akkor hozzáadogatja, a kapott paraméterhez.
   mp::cpp_int findD(mp::cpp_int p,mp::cpp_int q, mp::cpp_int e)
   {
	   mp::cpp_int x,y,fi;
	   mp::cpp_int n = p*q;
	   fi = findFI(p,q);
	   extendedEA(e,fi,&x,&y);
	   while ( x  <  0 )
	   {
		   x = x + fi;
	   } 
	   if (x < n ) {
		   return x;
		   }
	   else return -1;
	   
   }
   
   // Olyan e értéket ad vissza, ami háromnál nagyobb és relativ prím a kapott paraméterrel.
   // Ha nincs ilyen szám, akkor -1 el tér vissza.
   mp::cpp_int findE(mp::cpp_int fin)
   {
	   mp::cpp_int e = 3 ;
	   while ( e < fin )
	   {
		   mp::cpp_int tx, ty,test;
		  
		  // test = extendedEA(e,fin,&tx, &ty); 
		  // if ( test == 1 ) {return e;}
		     if (relativPrim(e,fin) && (e%2)) { return e; }
		  
		   ++e;
	   }  return -1;
   }
   
   
