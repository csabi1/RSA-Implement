  #include <iostream>
  #include <boost/multiprecision/cpp_int.hpp>
  
  #include "viszafejt.h"
  
  using namespace std;
  namespace mp = boost::multiprecision;
  
  /*A functioncalls header file, felépíti a felhasználó által, a menün
   * keresztül elérhető funkciókat.
   * */
  
  
  
  //Az RSA hívása, a felhasználó által megadott tasítások szerint.
  int RSA()
  {
	  int valasztas;
	  kulcsok kulcs;
	  mp::cpp_int uzenet;
	  mp::cpp_int temp;
	  
	  cout<<"========================================"<<endl;
	  cout<<"===================RSA=================="<<endl;
	  cout<<"========================================"<<"\n \n ";
	  
	  
	  cout<<"Kulcsgenerálás következik, nyomj: ";
	  cout<<"\n 1 - normál generáláshoz \n 2 - debug generáláshoz \n";
	  cin>>valasztas;
	  
	  
	  if (valasztas == 1 ) { kulcs = kulcsGen(false);
	  } else if (valasztas == 2 ) {
		  kulcs = kulcsGen(true);
	  } else { cout<<endl<<"ERROR ---- rosz értéket adtál meg"; 
		  return -1;}
		  
		  
	 cout << " -------------------------------- "<<endl;
	 
	 cout << " Add meg az üzenet : "; cin>>uzenet; cout<<endl;
	 
	 
	  cout<<"Mit szeretnél, nyomj: ";
	  cout<<"\n 1 - titkosítani \n 2 - viszafejteni \n";
	  cin>>valasztas;
	 
	  if (valasztas == 1 ) { 
		  temp  = titkosit(kulcs,uzenet);
		  cout<<endl<<" A titkosított üzeneted : "<<temp<<endl;
	  } else if (valasztas == 2 ) {
		   temp  = viszafejt(kulcs,uzenet);
		  cout<<endl<<" A titkosított üzeneted : "<<temp<<endl;
	  } else { cout<<endl<<"ERROR ---- rosz értéket adtál meg"; 
		  return -1;}
	  
	  return 0;     
  }
  
 //A valosPrimTeszt hívása, egy bekért számra. 
  int PrimTeszteles()
  {
	  cout<<"========================================"<<endl;
	  cout<<"================PRÍMTESZT==============="<<endl;
	  cout<<"========================================"<<"\n \n ";
	  
	   mp::cpp_int uzenet;
	   
	   cout << "Add meg a tesztelni kivánt számot : "; cin>>uzenet; cout<<endl;
	   
	   if (valosPrimTeszt(uzenet,5)){
		   cout<<"Prím ! \n";
	   } else { cout<<"Összetett ! \n"; }
	   
	  
  }
  
  
  // Az extendedEA hívása bekért adatokra (a,b)
  int EukledesziAlg()
  {
	  cout<<"========================================"<<endl;
	  cout<<"===================EEA=================="<<endl;
	  cout<<"========================================"<<"\n \n ";
	  
	  mp::cpp_int a,b,x,y;
	  
	  cout<< " Add meg a következőket: \n";
	  cout<< "A = "; cin>>a; cout<<endl;
	  cout<< "B = "; cin>>b; cout<<endl;
	  
	  cout<<"--------------------------------\n";
	  
	  cout<<"LNKO(A,B) = " << extendedEA(a,b,&x,&y) << endl;
	  cout<<"x = "<<x<<endl;
	  cout<<"y = "<<y<<endl;
	  
	  return 0;
  }
  
  
  //Moduláris hatványozás (gyorsHatvany) hívása bekért adatokra.
  int ModularisHatvanyozas()
  {
	  cout<<"========================================"<<endl;
	  cout<<"==============MODULARIS GY=============="<<endl;
	  cout<<"========================================"<<"\n \n ";
	  
	  mp::cpp_int a,b,c;
	  
	  cout<<" A formula:   A^B mod C \n";
	  cout<< "A = "; cin>>a; cout<<endl;
	  cout<< "B = "; cin>>b; cout<<endl;
	  cout<< "C = "; cin>>c; cout<<endl;
	  
	  cout<<"--------------------------------\n";
	  
	  cout<<"Erdemény : "<<gyorsHatvany(a,b,c);
	  
	  return 0;
	  
  }
  
  
  // Arra szolgál, hogy egy üzenetet titkosítson és dekodoljon egyszerre,
  // Ezzel bizonyítva az RSA tényleges müködését.
  void rsaAutoTest()
  { 
	  kulcsok kulcs;
	  kulcs = kulcsGen(false);
	  mp::cpp_int titkos;
	  mp::cpp_int megfejtes;
	  mp::cpp_int m;
	  
	  
	  cout << " Add meg az üzenet : ";
	  cin>>m;
	  
	  titkos = titkosit(kulcs,m);
	  cout<<" \n Titkosított! \n:"<<titkos;
	  megfejtes = viszafejt(kulcs,titkos);
	  cout<<" \n Megfejtés! \n:"<<megfejtes;
  }
  
  
  

