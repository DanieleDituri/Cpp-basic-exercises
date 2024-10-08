/**
  @file dbuffer.h

  @brief File header della classe dbuffer

  File di dichiarazioni della classe dbuffer 
*/

#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream> // std::ostream

/**
  @brief Classe dbuffer

  Classe che rappresenta un array dinamico di interi.
*/
class dbuffer {
public:
  typedef unsigned int size_type; ///< Tipo di dato per la dimensione dell'array

private:
  size_type _size; ///< Dimensione dell'array
  int * _buffer;      ///< Puntatore all'array di interi

public:

  /**
    @brief Costruttore di default

    1° METODO FONDAMENTALE DELLE CLASSI
    Construttore di default che inizializza il 
    dbuffer ad un array dinamico vuoto.

    @post _size == 0
    @post _buffer == nullptr
  */
  dbuffer();

  /**
    @brief Costruttore secondario

    Costruttore secondario che permette di creare un array
    dinamico di interi della dimensione data.

    @param size dimensione dell'array da istanziare

    @post _size == size
    @post _buffer != nullptr 
  */
  explicit dbuffer(size_type size);

  operator unsigned int() const; // int a = dbuffer;

  /**
    @brief Costruttore secondario

    Costruttore secondario che permette di creare un array
    dinamico di interi della dimensione data e contenenti
    il valore passato.

    @param size dimensione dell'array da istanziare
    @param value valore da assegnare a tutte le celle dell'array

    @post _size == size
    @post _buffer != nullptr 
    @post _buffer[i] == value
  */
  dbuffer(size_type size, int value);

  /**
    @brief Distruttore

    2° METODO FONDAMENTALE DELLE CLASSI
    IL distruttore della classe rimuove le eventuali risorse
    richieste dall'oggetto.

    @post _size == 0
    @post _buffer == nullptr
  */
  ~dbuffer();

  /**
    @brief Getter della dimensione dell'array

    Metodo che ritorna la dimensione dell'array di interi

    @return la dimensione dell'array di interi
  */
  size_type size(void) const;

  /*
  int get_value(unsigned int index);
  void set_value(unsigned int index, int value);
  */

  /**
    @brief Metodo getter/setter di una cella dell'array

    @param index della cella da leggere/scrivere
    @return reference all'intero da leggere/scrivere
    
    @pre index<_size
  */
  int& value(size_type index);

  /**
    @brief Metodo getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
  const int& value(size_type index) const;

  /**
    Operatore getter/setter di una cella dell'array

    @param index della cella da leggere/scrivere
    @return reference al'intero da leggere/scrivere
    
    @pre index<_size
  */
  int& operator[](size_type index);

  /**
    @brief Operatore getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
   const int& operator[](size_type index) const;

  /**
    @brief Stampa il contenuto dell'array dinamico su cout

    Stampa il contenuto dell'array dinamico su cout
  */
  void print(void) const; 

  /**
    @brief Metodo di riempimento dell'array

    Metodo che assegna ad ogni cella dell'array il valore 
    passato. value == 0 di default.

    @param value valore da assegnare alle celle dell'array

    @post _buffer[i] == value
  */
  void fill(int value=0);

  /**
    @brief Costruttore di copia (Copy constructor)

    3° METODO FONDAMENTALE DELLE CLASSI
    Crea un dbuffer a partire da un altro dbuffer

    @param other dbuffer sorgente

    @post _size == other._size
    @post _buffer[i] == other._buffer[i]
  */
  dbuffer(const dbuffer &other);

  /**
    @brief Operatore di assegnamento

    4° METODO FONDAMENTALE DELLE CLASSI
    Operatore che compia il contenuto di un dbuffer
    nel dbuffer corrente.

    @param other dbuffer sorgente

    @return reference a this

    @post _size == other._size
    @post _buffer[i] == other._buffer[i]
  */
  dbuffer& operator=(const dbuffer &other); // "*this" = other

  /**
    @brief Metodo swap

    Metodo che scambia lo stato di other con quello di this.

    @param other dbuffer con cui scambiare lo stato

    @post this->_size == other._size
    @post this->_buffer == other._buffer
    @post other._size == this->_size
    @post other._buffer == this->other._buffer
  */  
  void swap(dbuffer &other);

  // Permette alla funzione globale di accedere ai dati privati
  friend std::ostream& operator<<(std::ostream &os, const dbuffer &db);



  /**
    @brief ridefinizione operatore +: dbuffer + int

    Ridefinizione dell'operatore binario + come 
    funzione membro. L'operatore somma ad ogni cella
    del dbuffer this il valore dato. L'operando di 
    sinistra è implicitamente *this

    @param dx valore da aggiungere (operando di destra)

    @return un nuovo dbuffer

    @post result[i] = (*this)[i] + dx
  */
  dbuffer operator+(int rhs) const;

  /**
    @brief ridefinizione operatore %: dbuffer % dbuffer

    Ridefinizione dell'operatore binario % come 
    funzione membro. L'operatore calcola il prodotto scalare
    tra *this e un altro dbuffer.
    L'operando di sinistra è implicitamente *this.

    @param dx operando di destra

    @return il valore del prodotto scalare

    @pre this->size() == dx.size()
    @post result = sum_i( (*this)[i] * dx[i] )
  */
  long int operator%(const dbuffer &rhs) const;

  /**
    @brief ridefinizione operatore unario *: *dbuffer

    Ridefinizione dell'operatore unario * come 
    funzione membro. L'operatore calcola la somma dei valori
    dell'array. L'operando è implicitamente *this.

    @return la somma dei valori dell'array

    @post result = sum_i( (*this)[i] )
  */
  long int operator*(void) const;

  /**
    @brief operatore prefisso ++ : ++dbuffer

    Ridefinizione dell'operatore unario prefisso ++  
    come funzione membro della classe. L'operatore 
    somma 1 ad ogni cella del dbuffer e ritorna
    un reference al dbuffer modificato.
    L'operando è implicitamente *this.

    @return reference al dbuffer modificato

    @post (*this)[i] = (*this)[i] + 1
  */
  dbuffer &operator++(void); // ++(++i)

  /**
    @brief operatore postfisso ++ : dbuffer++

    Ridefinizione dell'operatore unario postfisso ++  
    come funzione membro della classe. L'operatore 
    somma 1 ad ogni cella del dbuffer ma ritorna una
    copia del vecchio dbuffer.
    L'operando è implicitamente *this.
    int è un parametro fittizio che serve a distinguere
    gli operatori postfissi da quelli prefissi.

    @return copia del dbuffer prima della modifica

    @post (*this)[i] = (*this)[i] + 1
  */
  dbuffer operator++(int);

};

/**
  @brief Operatore di stream

  Ridefinizione dell'operatore di stream per inviare su
  ostream il contenuto di un dbuffer

  @param os stream di output (operando di sinistra)
  @param db dbuffer da spedire (operando di destra)

  @return reference allo stream di output (operando di sinistra)
*/
std::ostream& operator<<(std::ostream &os, const dbuffer &db);

/**
  @brief ridefinizione operatore +: dbuffer + dbuffer

  Ridefinizione dell'operatore binario + come 
  funzione globale. L'operatore somma tra loro i valori 
  di due dbuffer.

  @param sx dbuffer sorgente (operando di sinistra)
  @param dx dbuffer sorgente (operando di destra)

  @return un nuovo dbuffer

  @pre sx.size() == dx.size()
  @post result[i] = sx[i] + dx[i]
*/dbuffer operator+(const dbuffer &lhs, const dbuffer &rhs);

/**
  @brief ridefinizione operatore +: int + dbuffer

  Ridefinizione dell'operatore binario + come 
  funzione globale. L'operatore somma ad ogni cella
  del dbuffer il valore dato.

  @param sx valore da aggiungere (operando di sinistra)
  @param dx dbuffer sorgente (operando di destra)

  @return un nuovo dbuffer

  @post result[i] = sx + dx[i]
*/dbuffer operator+(int lhs, const dbuffer &rhs);

/**
  @brief ridefinizione operatore +=: dbuffer + dbuffer

  Ridefinizione dell'operatore binario += come 
  funzione globale. L'operatore somma tra loro le celle
  dei due dbuffer e il valore finale è copiato nell'operando
  di sinistra.

  @param sx dbuffer sorgente (operando di sinistra)
  @param dx dbuffer sorgente (operando di destra)

  @return reference al dbuffer sx

  @pre sx.size() == dx.size()
  @post sx[i] = sx[i] + dx[i]
*/
dbuffer &operator+=(dbuffer &lhs, const dbuffer &rhs);

/**
  @brief ridefinizione operatore unario -: -dbuffer

  Ridefinizione dell'operatore unario - come 
  funzione globale. L'operatore ritorna un nuovo array con 
  i valori del dbuffer sorgente cambiati di segno.

  @param dx dbuffer sorgente (unico operando)

  @return un nuovo dbuffer

  @post result[i] = -dx[i]
*/
dbuffer operator-(const dbuffer &lhs);


/*
//Come sarebbero dichiarati come funzioni globali gli 
//operatori unari ++ prefisso e postfisso .

// op++ prefisso ++x
//dbuffer operator++(const dbuffer &dx);

// op++ postfisso x++
//dbuffer operator++(const dbuffer &dx,int);
*/

/*
// Come sarebbe dichiarato come funzione globale 
// l'operatore binario +: dbuffer + int 
dbuffer operator+(const dbuffer &sx, int dx);
*/

#endif