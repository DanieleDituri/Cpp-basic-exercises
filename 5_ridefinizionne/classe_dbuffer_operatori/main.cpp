/**
  @file main.cpp

  @brief File principale di progetto

  File di test della classe dbuffer 
*/

#include <iostream> // std::cout
#include <cassert> // assert
#include "dbuffer.h"

/**
  test dei metodi fondamentali
*/
void test_metodi_fondamentali() {

  std::cout << std::endl << "*** TEST METODI FONDAMENTALI ***" << std::endl;

  std::cout << "test ctor default" << std::endl;
  dbuffer db1;
  assert(db1.size() == 0); // verifichiamo lo stato dell'oggetto

  std::cout << "test ctor secondario 1" << std::endl;
  dbuffer db2(100);
  assert(db2.size() == 100);

  std::cout << "test ctor secondario 2" << std::endl;
  dbuffer db3(50,-1);
  assert(db3.size() == 50);
  for(dbuffer::size_type i =0; i < 50; i++)
    assert(db3[i] == -1);

  std::cout << "test copy constructor" << std::endl;
  dbuffer db4(db3); 
  // ATTENZIONE: una sintassi del tipo
  //             dbuffer db4 = db3;
  //             EQUIVALE ALLA CHIAMATA AL COPY CONSTRUCTOR!
  assert(db4.size() == db3.size());
  for(dbuffer::size_type i =0 ; i < db4.size(); i++)
    assert(db3[i] == db4[i]);

  std::cout << "test operatore assegnamento =" << std::endl;
  db1 = db3;
  assert(db1.size() == db3.size());
  for(dbuffer::size_type i =0 ; i < db1.size(); i++)
    assert(db3[i] == db1[i]);

  std::cout << "*** USCITA DALLA FUNZIONE test_metodi_fondamentali ***" << std::endl;
} // 4 chiamate a distruttore per db1, db2, db3 e db4

void passaggio_per_valore(dbuffer d) {
  std::cout << "*** USCITA DALLA FUNZIONE passaggio_per_valore ***" << std::endl;
}

void passaggio_per_reference(dbuffer &d) {
  std::cout << "*** USCITA DALLA FUNZIONE passaggio_per_reference ***" << std::endl;
}

void passaggio_per_puntatore(dbuffer *d) {
  std::cout << "*** USCITA DALLA FUNZIONE passaggio_per_reference ***" << std::endl;
}

void test_dbuffer() {
  std::cout << std::endl << "*** TEST DBUFFER ***" << std::endl;

  std::cout << "creazione di dbuffer di dimensione 10" << std::endl;
  dbuffer db(10); // ctor secondario

  std::cout << "creazione di un array di 5 dbuffer" << std::endl;
  dbuffer da[5]; // 5 chiamate al ctor di default, una per cella


  std::cout << "passaggio per valore di un dbuffer a una funzione" << std::endl;
  passaggio_per_valore(db); // Quando si passa un dato per valore, viene
                            // usato il copy constructor per inizializzare
                            // il parametro della funzione.

  std::cout << "passaggio per reference di un dbuffer a una funzione" << std::endl;
  passaggio_per_reference(db); // non abbiamo una chiamata al copy ctor

  std::cout << "passaggio per puntatore di un dbuffer a una funzione" << std::endl;
  passaggio_per_puntatore(&db); // non abbiamo una chiamata al copy ctor

  std::cout << "*** USCITA DALLA FUNZIONE test_dbuffer ***" << std::endl;
} // 6 chiamate a distruttore: db + i 5 dbuffer dell'array da

/**
  test dei metodi d'uso per un dbuffer non const
*/
void test_metodi_dbuffer() {
  std::cout << std::endl << "*** TEST METODI DBUFFER ***" << std::endl;

  dbuffer db(5,0);

  std::cout << "test value" << std::endl;
  db.value(1) = 100;
  assert(db.value(1) == 100);

  std::cout << "test set_value" << std::endl;
  db.value(0) = 99;
  assert(db.value(0) == 99);

  std::cout << "test scrittura op[]" << std::endl;
  db[3] = 5;
  assert(db[3]==5);

  // Se compilazione in modalita' debug da' errore 
  //db[100] = 5;

  std::cout << "test lettura op[]" << std::endl;
  int a = db[3];
  assert(a==5);

  // Se compilazione in modalita' debug da' errore 
  //int tmp = db[8];

  std::cout << "test fill()" << std::endl;
  db.fill(0);
  for(dbuffer::size_type i=0;i<db.size();++i) {
    assert(db[i]==0);
  }
}

/**
  funzione helper per i test dei metodi d'uso per un dbuffer const
*/
void test_metodi_dbuffer_const_helper(const dbuffer &db) {

  // Tutti i metodi di scrittura devono dare errore in compilazione
  // db[1] = 10; // errore
  // db.value(1) = 10; // errore
  // db.value(1)=10; // errore
  // db.fill(0); // errore

  // I metodi di lettura devono funzionare
  int tmp1 = db[3];
  int tmp2 = db.value(3);
  int sz = db.size();
} 

/**
  test dei metodi d'uso per un dbuffer const
*/
void test_metodi_dbuffer_const() {
  std::cout << std::endl << "*** TEST METODI DBUFFER CONST ***" << std::endl;

  dbuffer db(5,0);

  test_metodi_dbuffer_const_helper(db);  

  std::cout << db << std::endl; 
}

void test_operatori_dbuffer() {
  std::cout << std::endl << "*** TEST DEGLI OPERATORI ***" << std::endl;

  dbuffer d1(10,9);
  dbuffer d2(10,100);

  std::cout << "Contenuto di d1: " << std::endl;
  std::cout << d1 << std::endl;

  std::cout << "Contenuto di d2: " << std::endl;
  std::cout << d2 << std::endl;

  std::cout << "Risultato di d1+d2: " << std::endl;
  std::cout << d1 + d2 << std::endl;

  std::cout << "Risultato di d1+17: " << std::endl;
  std::cout << d1 + 17 << std::endl;

  std::cout << "Risultato di 5+d1: " << std::endl;
  std::cout << 5 + d1 << std::endl;

  std::cout << "Risultato di d1\%d2: " << std::endl;
  std::cout << d1 % d2 << std::endl;

  std::cout << "Risultato di *d1: " << std::endl;
  std::cout << *d1 << std::endl;

  std::cout << "Risultato di ++d1: " << std::endl;
  std::cout << ++d1 << std::endl;

  std::cout << "Risultato di d1++: " << std::endl;
  std::cout << d1++ << std::endl;

  std::cout << "Contenuto di d1: " << std::endl;
  std::cout << d1 << std::endl;

  std::cout << "Risultato di d1+=d2: " << std::endl;
  std::cout << (d1+=d2) << std::endl;

  std::cout << "Risultato di -d1: " << std::endl;
  std::cout << -d1 << std::endl;

  std::cout << "*** USCITA DALLA FUNZIONE test_operatori_dbuffer ***" << std::endl;
}



int main(int argc, char*argv[]) {

  test_metodi_fondamentali();

  test_dbuffer();

  test_metodi_dbuffer();

  test_metodi_dbuffer_const();

  test_operatori_dbuffer();

  return 0;
}