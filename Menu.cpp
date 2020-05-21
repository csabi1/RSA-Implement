  #include <iostream>
  #include <boost/multiprecision/cpp_int.hpp>
  
  #include "functioncalls.h"
  
  using namespace std;
  namespace mp = boost::multiprecision;
  
  /* Egyetlen main függvényből áll.
   * Célja, hogy a functioncalls.h -ban felépíttett hívásokat
   * elvégezze.
   * 
   * */
  int main()
  {
	  
	  int v1;
	  
	  cout<<"========================================"<<endl;
	  cout<<"==================MENU=================="<<endl;
	  cout<<"========================================"<<"\n \n ";
	  
	  
	  cout<<"Válaszd ki mit szeretnél csinálni:";
	  cout<<"\n 1 - RSA \n 2 - Prim Tesztelés \n 3 - Euklédeszi algoritmus \n 4 - Moduláris gyorshatványozás \n\n 8 - RSA auto test \n";
	  cin>>v1;
	  
	  switch (v1){
		  
		  case 1:
			RSA();
			break;
		  
		  case 2:
			PrimTeszteles();
			break;
			
		  case 3:
			EukledesziAlg();
			break;
		  
		  case 4:
			ModularisHatvanyozas();
			break;
		 
		  case 8:
			rsaAutoTest();
			break;
			
		  default: 
			cout<< "ERROR --- Hibás értéket adtál meg!";
		}
			
		  
	  }
	  
  
