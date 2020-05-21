    #include <iostream>
    #include <boost/multiprecision/cpp_int.hpp>
    
    #include "kulcsGeneralas.h" //Ebben kb minden benne van.
    
    namespace mp = boost::multiprecision;
    using namespace std;
    
    
    /* Az aktualis, nevű változóba, kulcsokat generál a függvény.
     * A gyorsHatvany függvényel titkosít.
     * Viasszadja a titkosított üzenetet.
     * */
    mp::cpp_int titkosit(kulcsok aktualis,mp::cpp_int uzenet)
    {	
		mp::cpp_int titkosUzenet;	
		if (uzenet > aktualis.PKn)
		{
			cout<<"ERROR  --- Az üzeneted nem jó !";
			return -1;
		} else {
			
			titkosUzenet =  gyorsHatvany(uzenet,aktualis.PKe,aktualis.PKn);
		}
		
		return titkosUzenet;			
	}

    
