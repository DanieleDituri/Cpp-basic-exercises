
#ifndef STRINGHEC_H
#define STRINGHEC_H

/**
 * @brief Funzione per stampare una stringa C.
 * 
 * La funzione stampa la stringa passata come argomento.
 *
 * @param str Puntatore alla stringa da stampare.
 */
void stampa(const char *str);

/**
 * @brief Calcola la lunghezza di una stringa.
 * 
 * Questa funzione calcola la lunghezza di una stringa passata come parametro.
 * La lunghezza è determinata contando il numero di caratteri presenti nella stringa,
 * escludendo il carattere terminatore '\0'.
 * 
 * @param str Puntatore alla stringa di cui calcolare la lunghezza.
 * @return La lunghezza della stringa.
 */
int lunghezza(const char *str);

/**
 * @brief Inverte una stringa.
 * 
 * Questa funzione prende in input un puntatore a una stringa di caratteri e inverte l'ordine dei caratteri all'interno della stringa.
 * 
 * @param str Il puntatore alla stringa da invertire.
 */
void inverti(char *str);

/**
 * @brief Clona una stringa.
 * 
 * Questa funzione clona una stringa passata come parametro.
 * 
 * @param str La stringa da clonare.
 * @return Un puntatore alla stringa clonata.
 */
char *clona(const char *str);

char *concatena(const char *str1, const char *str2);

const char *cerca(const char *s1, const char *st);

#endif