#include <iostream>
#include <cassert>

/**
 * @brief Scambia il valore di due interi.
 *
 * @param a Il primo intero da scambiare.
 * @param b Il secondo intero da scambiare.
 */
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Scambia il valore di due double.
 *
 * @param a Il primo double da scambiare.
 * @param b Il secondo double da scambiare.
 */
void swap(double &a, double &b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Scambia il valore di due generici.
 *
 * @tparam T Il tipo generico.
 * @param a Il primo generico da scambiare.
 * @param b Il secondo generico da scambiare.
 */
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Assegna un valore a tutti gli elementi di un array.
 *
 * @tparam T Il tipo generico.
 * @tparam Q Il tipo generico.
 * @param array L'array da modificare.
 * @param size La dimensione dell'array.
 * @param value Il valore da assegnare.
 */
template <typename T, typename Q>
void assegna(T *array, unsigned int size, const Q &value)
{
    assert(array != nullptr);
    for (unsigned int i = 0; i < size; ++i)
    {
        array[i] = static_cast<T>(value);
    }
}

/**
 * @brief Ordina un array.
 *
 * @tparam T Il tipo generico.
 * @param array L'array da ordinare.
 * @param size La dimensione dell'array.
 */
template <typename T>
void sort_array(T *array, unsigned int size)
{
    unsigned int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}

template <typename T, typename P>
void sort_array_2(T *array, unsigned int size, P compare)
{
    unsigned int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (compare(array[j], array[i]))
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}

struct compare_int_cresc
{
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

struct compare_int_decresc
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

/**
 * @brief Stampa un array.
 *
 * @tparam T Il tipo generico.
 * @param array L'array da stampare.
 * @param size La dimensione dell'array.
 */
template <typename T>
void print_array(T *array, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a = 5, b = 10;
    std::cout << "Prima dello swap: a = " << a << ", b = " << b << std::endl;
    swap<int>(a, b);
    std::cout << "Dopo lo swap: a = " << a << ", b = " << b << std::endl;

    double c = 5.5, d = 10.5;
    std::cout << "Prima dello swap: c = " << c << ", d = " << d << std::endl;
    swap<double>(c, d);
    std::cout << "Dopo lo swap: c = " << c << ", d = " << d << std::endl;

    int e[5] = {0, 0, 0, 0, 0};

    print_array(e, 5);

    assegna(e, 5, 100);

    print_array(e, 5);

    assegna(e, 5, 2.7); // Funziona solo con due typename nel template

    print_array(e, 5);

    char f[3] = {'0', '0', '0'};

    print_array(f, 3);

    assegna(f, 3, 'Z');

    print_array(f, 3);

    int g[5] = {5, 3, 1, 4, 2};

    print_array(g, 5);

    sort_array(g, 5);

    print_array(g, 5);

    int h[5] = {77, 12, 1, 43, 22};

    compare_int_cresc comp;

    sort_array_2(h, 5, comp);

    print_array(h, 5);

    compare_int_decresc comp2;

    sort_array_2(h, 5, comp2);

    print_array(h, 5);

    return 0;
}