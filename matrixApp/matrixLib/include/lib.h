#include<string>

void help()
int **utworz_macierz_int(int ilosc_wierszy, int ilosc_kolumn);
double **utworz_macierz_double(int ilosc_wierszy, int ilosc_kolumn);
bool wypelnianie_macierzy(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
bool wypelnianie_macierzy(double **macierz, int ilosc_wierszy, int ilosc_kolumn);
void wyswietl(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
void wyswietl(double **macierz, int ilosc_wierszy, int ilosc_kolumn);
int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
double **addMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
double **subtractMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
int **multiplyMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b);
double **multiplyMatrix(double **macierz_a, double **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b);
int **multiplyByScalar(int **macierz, int ilosc_wierszy,int ilosc_kolumn,int skalar);
double **multiplyByScalar(double **macierz, int ilosc_wierszy,int ilosc_kolumn,double skalar);
int **transpozeMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
double **transpozeMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn);
int **powerMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn, int potega);
double **powerMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn, double potega);
int **submatrix(int **macierz, int index_wierszy, int index_kolumn, int rozmiar_macierzy);
int determinantMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
double **submatrix(double **macierz, int index_wierszy, int index_kolumn, int rozmiar_macierzy);
double determinantMatrix(double **macierz, int ilosc_wierszy, int ilosc_kolumn);
bool matrixIsDiagonal(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
bool matrixIsDiagonal(double **macierz, int ilosc_wierszy, int ilosc_kolumn);
void swap(int *a, int *b);
void swap(double *a, double *b);
void sortRow (int *tablica, int liczba_kolumn);
void sortRow (double *tablica, int liczba_kolumn);
void sortRowsInMatrix(int **macierz, int liczba_wierszy,int liczba_kolumn);
void sortRowsInMatrix(double **macierz, int liczba_wierszy,int liczba_kolumn);
bool sprawdzanie(std:: string komendy);
