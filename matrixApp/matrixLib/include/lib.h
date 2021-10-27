
int **utworz_macierz(int ilosc_wierszy, int ilosc_kolumn);
void wypelnianie_macierzy(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
void wyswietl(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
int **addMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
int **subtractMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy, int ilosc_kolumn);
int **multiplyMatrix(int **macierz_a, int **macierz_b, int ilosc_wierszy_a, int ilosc_kolumn_a, int ilosc_kolumn_b);
int **multiplyByScalar(int **macierz, int ilosc_wierszy,int ilosc_kolumn,int skalar);
int **transpozeMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn);
int **powerMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn, int potega);
int **submatrix(int **macierz, int index_wierszy, int index_kolumn, int rozmiar_macierzy);
int determinantMatrix(int **macierz, int ilosc_wierszy, int ilosc_kolumn);