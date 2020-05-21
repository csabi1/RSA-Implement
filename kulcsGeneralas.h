    #include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
 // #include "modularisGyors.h"
    #include <time.h>  
    #include "randomGen.h"  // benne van a MR (és a modulárisGyors)
    #include "findEDFI.h"   // benne van a EEA
    
    namespace mp = boost::multiprecision;
    using namespace std;
    
    
    // Struktúra, hogy viszaadhassuk a legenerált kulcsokat.
    struct kulcsok {
		mp::cpp_int PKn;
		mp::cpp_int PKe;
		mp::cpp_int SKd;
	};
	
    /*Kulcsgenerálás
     * Generál két nagy prímszámot (p,q)
     * Meghatározza a hozzá tartozó n, fi, e és d értékeket.
     * Egy boolean típusú paraméterrel dolgozik, ami azt határozza meg,
     * hogy az összes változót kiírja vagy csak a generált kucsokat.
     * Visszatér a legenerált PK és SK val.
     * */
    kulcsok kulcsGen(bool visible)
    {
		srand (time(NULL));
		
		mp::cpp_int n,p,q,fi,d,e;
		
		p = primGenerator();
		q = primGenerator();
		
		n = p*q;		
		fi = findFI(p,q);
		e = findE(fi);
		d = findD(p,q,e);
		
		
		if (!visible)
		{
			cout<< " PK = (" << n << " ; "<< e << ")"<<endl;
			cout<< " SK = (" << d << ")"<<endl;
		}
		if (visible)
		{
			cout<<"--------------"<<endl;
			cout<<"n = "<<n<<endl;
			cout<<"p = "<<p<<endl;
			cout<<"q = "<<q<<endl;
			cout<<"e = "<<e<<endl;
			cout<<"d = "<<d<<endl;
			cout<<"FI = "<<fi<<endl;
			cout<<"--------------"<<endl;
			
			cout<< " PK = (" << n << " ; "<< e << ")"<<endl;
			cout<< " SK = (" << d << ")"<<endl;
		}
		
		kulcsok viszateresiErtek;
		viszateresiErtek.PKn = n;
		viszateresiErtek.PKe = e;
		viszateresiErtek.SKd = d;
		return viszateresiErtek;
		
	}
		
	
