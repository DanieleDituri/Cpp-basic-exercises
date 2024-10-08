/**
  @file dbuffer.hpp

  @brief File header della classe dbuffer templata

  File di dichiarazioni/definizioni della classe dbuffer templata
*/

#ifndef DBUFFER_HPP
#define DBUFFER_HPP

#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t
#include <ostream> // std::ostream
#include <cassert> // assert
/**
  @brief Classe dbuffer templata

  Classe generica che rappresenta un array dinamico di dati 
  di tipo T.
*/

template <typename T>
class dbuffer {
public:
  // Traits
  typedef unsigned int size_type; ///< Tipo di dato per la dimensione dell'array
  typedef T value_type;

private:
  size_type _size; ///< Dimensione dell'array
  value_type * _buffer;     ///< Puntatore all'array di dati di tipo T

public:

  /**
    @brief Costruttore di default

    1° METODO FONDAMENTALE DELLE CLASSI
    Construttore di default che inizializza il 
    dbuffer ad un array dinamico vuoto.

    @post _size == 0
    @post _buffer == nullptr
  */
  dbuffer() : _size(0), _buffer(nullptr) { // initialization list
    #ifndef NDEBUG 
    std::cout<<"dbuffer::dbuffer()"<<std::endl;
    #endif
  }

  /**
    @brief Costruttore secondario

    Costruttore secondario che permette di creare un array
    dinamico di interi della dimensione data.

    @param size dimensione dell'array da istanziare

    @post _size == size
    @post _buffer != nullptr 
  */
  explicit dbuffer(size_type size) : _size(0), _buffer(nullptr) {
    _buffer = new value_type[size];
    _size = size; 

    #ifndef NDEBUG 
    std::cout<<"dbuffer::dbuffer(size_type size)"<<std::endl;
    #endif   
  }

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
  dbuffer(size_type size, const value_type &value) : _size(0), _buffer(nullptr) {
    _buffer = new value_type[size];

    _size = size; 

    try {
      fill(value);
    }
    catch(...) {
      delete[] _buffer;
      _buffer = nullptr;
      _size = 0;
      throw;
    }

    #ifndef NDEBUG 
    std::cout<<"dbuffer::dbuffer(size_type  size, const T &value)"<<std::endl;
    #endif   
  }

  /**
    @brief Distruttore

    2° METODO FONDAMENTALE DELLE CLASSI
    IL distruttore della classe rimuove le eventuali risorse
    richieste dall'oggetto.

    @post _size == 0
    @post _buffer == nullptr
  */
  ~dbuffer() {
    delete[] _buffer;

    _buffer = nullptr;
    _size = 0;

    #ifndef NDEBUG 
    std::cout<<"dbuffer::~dbuffer()"<<std::endl;
    #endif   
  }

  /**
    @brief Getter della dimensione dell'array

    Metodo che ritorna la dimensione dell'array di interi

    @return la dimensione dell'array di interi
  */
  size_type size(void) const {
    return _size;
  }

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
  value_type& value(size_type index) {
    assert(index < _size);

    return _buffer[index];
  }

  /**
    @brief Metodo getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
  const value_type& value(size_type index) const {
    assert(index < _size);

    return _buffer[index];  
  }

  /**
    Operatore getter/setter di una cella dell'array

    @param index della cella da leggere/scrivere
    @return reference al'intero da leggere/scrivere
    
    @pre index<_size
  */
  value_type& operator[](size_type index) {
    assert(index < _size);

    return _buffer[index];
  }

  /**
    @brief Operatore getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
  const value_type& operator[](size_type index) const {
    assert(index < _size);

    return _buffer[index];
  }

  /**
    @brief Stampa il contenuto dell'array dinamico su cout

    Stampa il contenuto dell'array dinamico su cout
  */
  void print(void) const {
    std::cout << _size << " [ ";
    for(size_type  i = 0; i < _size; ++i)
      std::cout << _buffer[i] << " ";
    std::cout << "]" << std::endl;
  } 
 

  /**
    @brief Metodo di riempimento dell'array

    Metodo che assegna ad ogni cella dell'array il valore 
    passato. value == 0 di default.

    @param value valore da assegnare alle celle dell'array

    @post _buffer[i] == value
  */
  void fill(const value_type &value) {
    dbuffer tmp(_size);

    for(size_type i=0; i<_size; ++i)
      tmp[i] = value;  // Può fallire!!!

    tmp.swap(*this);
  }

  /**
    @brief Costruttore di copia (Copy constructor)

    3° METODO FONDAMENTALE DELLE CLASSI
    Crea un dbuffer a partire da un altro dbuffer

    @param other dbuffer sorgente

    @post _size == other._size
    @post _buffer[i] == other._buffer[i]
  */
  dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr) {
    _buffer = new value_type[other._size];
    
    try {
      for(size_type  i=0; i<other._size; ++i)
        _buffer[i] = other._buffer[i]; // Può fallire!! 
    }
    catch(...) {
      delete[] _buffer;
      _buffer = nullptr;
      throw;
    }

    _size = other._size;

    #ifndef NDEBUG 
    std::cout<<"dbuffer::dbuffer(const dbuffer &other)"<<std::endl;
    #endif   
  }

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
  dbuffer& operator=(const dbuffer &other) {
    if (this != &other) { // controllo auto-assegnamento
      dbuffer tmp(other); // creo una copia dei dati
      this->swap(tmp);    // scambio gli stati/dati 
    } // tmp, con i vecchi dati , viene rimosso automaticamente dalla memoria

    #ifndef NDEBUG 
    std::cout<<"dbuffer::operator=(const dbuffer &other)"<<std::endl;
    #endif   

    return *this; // ritorno me stesso // a=b=c;
  }

  /**
    @brief Metodo swap

    Metodo che scambia lo stato di other con quello di this.

    @param other dbuffer con cui scambiare lo stato

    @post this->_size == other._size
    @post this->_buffer == other._buffer
    @post other._size == this->_size
    @post other._buffer == this->other._buffer
  */  
  void swap(dbuffer &other){
    std::swap(this->_size, other._size);
    std::swap(this->_buffer, other._buffer); 
  }


  /**
    Costruttore secondario che costruisce un dbuffer su dati T a 
    partire da un array primitivo di dati di tipo Q generici. 
    Lasciate al compilatore la gestione della conversione di tipo
    tra Q e T. 
  */
  template <typename Q>
  dbuffer(const Q *array, size_type size) : _buffer(nullptr), _size(0) {
    assert(array!=nullptr);

    _buffer = new value_type[size];
    try {
      for(size_type i = 0; i<size; ++i)
        _buffer[i] = static_cast<value_type>(array[i]);
    }
    catch(...) {
      delete[] _buffer;
      _buffer = nullptr;
      _size = 0;
      throw;
    }
    _size = size;
  }

  /* // Conflitto con dbuffer(unsigned int, int)
  template <typename Iter>
  dbuffer(Iter &b, Iter e) : _buffer(nullptr), _size(0) {
    Iter c;
    unsigned int i,count = 0;

    // Conto numero di dati
    for(c=b; c!=e ; ++c, ++count) {}

    // Alloco lo spazio
    _buffer = new T[count];

    try {
    // Copio i dati dalla sequenza
      for(i=0, c=b; c!=e ; ++c, ++i) 
      _buffer[i] = static_cast<T>(*c);
    }
    catch(...) {
      delete[] _buffer;
      _buffer = nullptr;
      throw;
    }

    _size = count;
  } 
  */

  // Solo se serve anche const_iterator aggiungere la seguente riga
  class const_iterator; // forward declaration

  class iterator {
    //  
  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T                         value_type;
    typedef ptrdiff_t                 difference_type;
    typedef T*                        pointer;
    typedef T&                        reference;

  
    iterator()  : ptr(nullptr) {
      //!!!
    }
    
    iterator(const iterator &other) {
      ptr = other.ptr;
    }

    iterator& operator=(const iterator &other) {
      ptr = other.ptr;
      return *this;
    }

    ~iterator() {}

    // Ritorna il dato riferito dall'iteratore (dereferenziamento)
    reference operator*() const {
      return *ptr;
    }

    // Ritorna il puntatore al dato riferito dall'iteratore
    pointer operator->() const {
      return ptr;
    }

    // Operatore di iterazione post-incremento
    iterator operator++(int) {
      iterator tmp(*this);
      ptr++;
      return tmp;
    }

    // Operatore di iterazione pre-incremento
    iterator& operator++() {
      ++ptr;
      return *this;
    }

    // Uguaglianza
    bool operator==(const iterator &other) const {
      return (ptr==other.ptr);
    }

    // Diversita'
    bool operator!=(const iterator &other) const {
      return (ptr!=other.ptr);
    }
    
    // Solo se serve anche const_iterator aggiungere le seguenti definizioni
    friend class const_iterator;

    // Uguaglianza
    bool operator==(const const_iterator &other) const {
      return (ptr==other.ptr);
    }

    // Diversita'
    bool operator!=(const const_iterator &other) const {
      return (ptr!=other.ptr);
    }

    // Solo se serve anche const_iterator aggiungere le precedenti definizioni

  private:
    T *ptr;

    // La classe container deve essere messa friend dell'iteratore per poter
    // usare il costruttore di inizializzazione.
    friend class dbuffer; // !!! Da cambiare il nome!

    // Costruttore privato di inizializzazione usato dalla classe container
    // tipicamente nei metodi begin e end
    iterator(T*p) { 
      ptr = p;
    }
    
    // !!! Eventuali altri metodi privati
    
  }; // classe iterator
  
  // Ritorna l'iteratore all'inizio della sequenza dati
  iterator begin() {
    return iterator(_buffer);
  }
  
  // Ritorna l'iteratore alla fine della sequenza dati
  iterator end() {
    return iterator(_buffer + _size);
  }
  
    
  class const_iterator {
    //  
  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T                         value_type;
    typedef ptrdiff_t                 difference_type;
    typedef const T*                  pointer;
    typedef const T&                  reference;

  
    const_iterator() : ptr(nullptr) {
    }
    
    const_iterator(const const_iterator &other) : ptr(other.ptr) {
    }

    const_iterator& operator=(const const_iterator &other) {
      ptr = other.ptr;
      return *this;
    }

    ~const_iterator() { }

    // Ritorna il dato riferito dall'iteratore (dereferenziamento)
    reference operator*() const {
      return *ptr;
    }

    // Ritorna il puntatore al dato riferito dall'iteratore
    pointer operator->() const {
      return ptr;
    }
    
    // Operatore di iterazione post-incremento
    const_iterator operator++(int) {
      const_iterator tmp(*this);
      ++ptr;
      return tmp;
    }

    // Operatore di iterazione pre-incremento
    const_iterator& operator++() {
      ++ptr;
      return *this;
    }

    // Uguaglianza
    bool operator==(const const_iterator &other) const {
      return ptr==other.ptr;
    }
    
    // Diversita'
    bool operator!=(const const_iterator &other) const {
      return ptr!=other.ptr;
    }

    // Solo se serve anche iterator aggiungere le seguenti definizioni
    
    friend class iterator;

    // Uguaglianza
    bool operator==(const iterator &other) const {
      return ptr == other.ptr;
    }

    // Diversita'
    bool operator!=(const iterator &other) const {
      return ptr != other.ptr;
    }

    // Costruttore di conversione iterator -> const_iterator
    const_iterator(const iterator &other) : ptr(other.ptr) {  }

    // Assegnamento di un iterator ad un const_iterator
    const_iterator &operator=(const iterator &other) {
      ptr = other.ptr;
      return *this;
    }

    // Solo se serve anche iterator aggiungere le precedenti definizioni

  private:
    //Dati membro

    const T *ptr;

    // La classe container deve essere messa friend dell'iteratore per poter
    // usare il costruttore di inizializzazione.
    friend class dbuffer; // !!! Da cambiare il nome!

    // Costruttore privato di inizializzazione usato dalla classe container
    // tipicamente nei metodi begin e end
    const_iterator(const T*p) : ptr(p) {}
    
    // !!! Eventuali altri metodi privati
    
  }; // classe const_iterator
  
  // Ritorna l'iteratore all'inizio della sequenza dati
  const_iterator begin() const {
    return const_iterator(_buffer);
  }
  
  // Ritorna l'iteratore alla fine della sequenza dati
  const_iterator end() const {
    return const_iterator(_buffer + _size);
  }


};

/**
  @brief Operatore di stream

  Ridefinizione dell'operatore di stream per inviare su
  ostream il contenuto di un dbuffer

  @param os stream di output (operando di sinistra)
  @param db dbuffer da spedire (operando di destra)

  @return reference allo stream di output (operando di sinistra)
*/
template <typename T>
std::ostream& operator<<(std::ostream &os, const dbuffer<T> &db) {
  os << db.size() << " [ ";
  for(typename dbuffer<T>::size_type  i = 0; i < db.size(); ++i)
    os << db[i] << " ";
  os << "]";
  
  return os;  
}

#endif