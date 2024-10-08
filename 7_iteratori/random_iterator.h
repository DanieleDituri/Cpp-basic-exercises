/**
 * Classi iterator e const_iterator generiche per un iteratore random.
 * iterator e' un iteratore in lettura e scrittura.
 * const_iterator e' un iteratore in sola lettura.
 * Le classi sono da definire dentro una classe container generica.
 * Viene data solo l'interfaccia. Le definizioni dei vari metodi 
 * cosi' come quali variabili membro deve avere ciascuna classe non 
 * sono dati. Dipendono dalla classe container padre su cui lavorano 
 * gli iteratori.
 * 
 * NOTA: Se definire iterator e/o const_iterator dipende dalla classe container.

 * NOTA: Sostituire T (generico) con il tipo concreto o generico su cui
 *       l'iteratore deve iterare (di solito dipende dal tipo generico
 *       della classe container).
 *
 * NOTA: i punti da modificare/adattare sono contrassegnati con !!!
 */

#include <iterator> // std::random_iterator_tag
#include <cstddef>  // std::ptrdiff_t


//template <typename....>
//class CLASSE_CONTAINER_PADRE {
//	...

	// Solo se serve anche const_iterator aggiungere la seguente riga
	class const_iterator; // forward declaration

	class iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef T*                       pointer;
		typedef T&                       reference;

	
		iterator() {
			//!!!
		}
		
		iterator(const iterator &other) {
			//!!!
		}

		iterator& operator=(const iterator &other) {
			//!!!
			return *this;
		}

		~iterator() {
			//!!!
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			//!!!
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			//!!!
		}

		// Operatore di accesso random
		reference operator[](int index) {
			//!!!
		}
		
		// Operatore di iterazione post-incremento
		iterator operator++(int) {
			//!!!
		}

		// Operatore di iterazione pre-incremento
		iterator &operator++() {
			//!!!
		}

		// Operatore di iterazione post-decremento
		iterator operator--(int) {
			//!!!
		}

		// Operatore di iterazione pre-decremento
		iterator &operator--() {
			//!!!
		}

		// Spostamentio in avanti della posizione
		iterator operator+(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		iterator operator-(int offset) {
			//!!!
		}
		
		// Spostamentio in avanti della posizione
		iterator& operator+=(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		iterator& operator-=(int offset) {
			//!!!
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const iterator &other) {
			//!!!
		}
	
		// Uguaglianza
		bool operator==(const iterator &other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator>(const iterator &other) const {
			/!!!!
		}
		

		bool operator>=(const iterator &other) const {
			/!!!!
		}

		// Confronto
		bool operator<(const iterator &other) const {
			/!!!!
		}
		
		
		// Confronto
		bool operator<=(const iterator &other) const {
			//!!!
		}
		
		
		// Solo se serve anche const_iterator aggiungere le seguenti definizioni
		
		friend class const_iterator;

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator>(const const_iterator &other) const {
			//!!!
		}
		

		bool operator>=(const const_iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator<(const const_iterator &other) const {
			//!!!
		}
		
		
		// Confronto
		bool operator<=(const const_iterator &other) const {
			//!!!
		}

		// Solo se serve anche const_iterator aggiungere le precedenti definizioni
	
	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class CLASSE_CONTAINER_PADRE; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		iterator(/*!!!*/) { 
			//!!! 
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	iterator begin() {
		return iterator(/*!!!*/);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	iterator end() {
		return iterator(/*!!!*/);
	}
	
	
	
	class const_iterator {
		//	
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T                        value_type;
		typedef ptrdiff_t                difference_type;
		typedef const T*                 pointer;
		typedef const T&                 reference;

	
		const_iterator() {
			//!!!
		}
		
		const_iterator(const const_iterator &other) {
			//!!!
		}

		const_iterator& operator=(const const_iterator &other) {
			//!!!
			return *this;
		}

		~const_iterator() {
			//!!!
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			//!!!
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			//!!!
		}

		// Operatore di accesso random
		reference operator[](int index) {
			//!!!
		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			//!!!
		}

		// Operatore di iterazione pre-incremento
		const_iterator &operator++() {
			//!!!
		}

		// Operatore di iterazione post-decremento
		const_iterator operator--(int) {
			//!!!
		}

		// Operatore di iterazione pre-decremento
		const_iterator &operator--() {
			//!!!
		}

		// Spostamentio in avanti della posizione
		const_iterator operator+(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		const_iterator operator-(int offset) {
			//!!!
		}
		
		// Spostamentio in avanti della posizione
		const_iterator& operator+=(int offset) {
			//!!!
		}

		// Spostamentio all'indietro della posizione
		const_iterator& operator-=(int offset) {
			//!!!
		}

		// Numero di elementi tra due iteratori
		difference_type operator-(const const_iterator &other) {
			//!!!
		}
	
		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator>(const const_iterator &other) const {
			//!!!
		}
		

		bool operator>=(const const_iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator<(const const_iterator &other) const {
			//!!!
		}
		
		
		// Confronto
		bool operator<=(const const_iterator &other) const {
			//!!!
		}
		
		
		// Solo se serve anche iterator aggiungere le seguenti definizioni
		
		friend class iterator;

		// Uguaglianza
		bool operator==(const iterator &other) const {
			//!!!
		}

		// Diversita'
		bool operator!=(const iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator>(const iterator &other) const {
			//!!!
		}
		

		bool operator>=(const iterator &other) const {
			//!!!
		}

		// Confronto
		bool operator<(const iterator &other) const {
			//!!!
		}
		
		
		// Confronto
		bool operator<=(const iterator &other) const {
			//!!!
		}

		// Costruttore di conversione iterator -> const_iterator
		const_iterator(const iterator &other) {
			//!!!
		}

		// Assegnamento di un iterator ad un const_iterator
		const_iterator &operator=(const iterator &other) {
			//!!!
			return *this;
		}

		// Solo se serve anche iterator aggiungere le precedenti definizioni
	
	private:
		//Dati membro

		// La classe container deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class CLASSE_CONTAINER_PADRE; // !!! Da cambiare il nome!

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(/*!!!*/) { 
			//!!! 
		}
		
		// !!! Eventuali altri metodi privati
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(/*!!!*/);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(/*!!!*/);
	}
	
	
	
	
//}; // CLASSE_CONTAINER_PADRE