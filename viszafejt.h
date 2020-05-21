    #include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
    
    #include "titkositas.h" //Itt aztán végképp minden megvan.
    
    namespace mp = boost::multiprecision;
    using namespace std;
     /* Viszafejtés.
      * c^d mod n formula alapján.
      * Kulcsot, és titkos üzenetet vár.
      * */
    mp::cpp_int viszafejt(kulcsok aktKulcs, mp::cpp_int titkos)
    {
		
				
		mp::cpp_int viszafejtettUzenet;
		
		viszafejtettUzenet = gyorsHatvany(titkos,aktKulcs.SKd,aktKulcs.PKn);
		
		return viszafejtettUzenet;
		
		
	}
	
    
