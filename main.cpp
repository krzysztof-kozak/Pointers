#include <iostream>
using namespace std;

void print_my_num(int num) {
  cout << "Zmienna num z funkcji: " << num << endl;
  num = 150;
  cout << "Zmienna num z funkcji po modyfikacji: " << num << endl;
}

void increment_all_elements_by_one(int arr[], int size) {
  cout << "Adres tablicy z funkcji: " << arr << endl;

  // Co ciekawe, nie można odczytać rozmaru tablicy wewnątrz funkcji w ten sposób:
  // Takie coś zadziała tylko jak będziemy to robić wewnątrz main.
  cout << "Rozmiar tablicy z funkcji (nieprawidłowy): " << sizeof(arr) / sizeof(arr[0]) << endl;
  
  // Właśnie dlatego ustawiamy drugi paramentr funkcji, który przyjmuje rozmiar tablicy.
  cout << "Rozmiar tablicy z funkcji (prawidłowy, z wykorzystaniem parametru): " << size << endl << endl;

  // No dobra, zwiększmy teraz każdy element tablicy (oryginalnej, nie kopii) o 1
  for (int i = 0; i < size; i++) {
    arr[i]++;
  }

  // Sprawdźmy czy działa:
  cout << "(Wywołane z funkcji) -  Element 1: " << arr[0] << endl;
  cout << "(Wywołane z funkcji) -  Element 2: " << arr[1] << endl;
  cout << "(Wywołane z funkcji) -  Element 3: " << arr[2] << endl;
  cout << "(Wywołane z funkcji) -  Element 4: " << arr[3] << endl;
  cout << "(Wywołane z funkcji) -  Element 5: " << arr[4] << endl;
}

// Jak zrobić by przekazując coś do funkcji działać na oryginale?
// Sposób 1:
// Jako parametr, ustawiamy wskaźnik z adresem.
void increment_my_num(int *a) {

  //Zmieniamy wartość pod danym adresem
  *a = 999;

  cout << "Adres zmiennej a z funkcji: " << a << endl;
  cout << "Wartość zmiennej a z funkcji: " << *a << endl;
}


// Jak zrobić by przekazując coś do funkcji działać na oryginale?
// Sposób 2:
// Skrócony sposób używania wskaźników z wykorzystaniem znaku &.
void increment_my_num2(int &b) {

  // Dzięki zastosowaniu & przy parametrze, dajemy znać c++, że chcemy pracować na oryginalnej wartości.
  b = 999;

  cout << "[Sposób 2, skrócony] Adres zmiennej b z funkcji: " << &b << endl;
  cout << "[Sposób 2, skrócony] Wartość zmiennej b z funkcji: " << b << endl;
}


int main() {
  int myNumber = 10;
  bool myBoolean = false;

  int *pointer_1{nullptr};
  bool *pointer_2{nullptr};

  pointer_1=&myNumber;
  pointer_2=&myBoolean;

  // Odnieśmy się do wartości przechowywanej pod danym adresem. Następnie zmieńmy tę wartość.
  *pointer_1 = 20;
  *pointer_2 = true;

  cout << "Adres pod wskaźnikiem 1: " << pointer_1 << "; " << " Adres pod wskaźnikiem 2: " << pointer_2 << endl << endl;

  cout << "Zmienna myNumber przechowuje wartość - " << myNumber << " oraz mieszka pod adresem: " << &myNumber << endl;
  cout << "Zmienna myBoolean przechowuje wartość - " << myBoolean << " oraz mieszka pod adresem: " << &myBoolean << endl << endl;

  cout << "Wartość pod adresem 0x7ffc61bea7dc to " << *pointer_1 << endl;
  cout << "Wartość pod adresem 0x7ffc61bea7db to " << *pointer_2 << endl;


  cout << "--------" << endl << endl << endl;


  int myArray[5]{1, 3, 6, 9, 12};

  // W ten sposób otrzymamy adres, pod którym mieszka pierwszy element mojej tablicy. Możemy też sprawdzić jaką ma wartość:

  // Adres:
  cout << "Adress w pamięci na jaki wskazuje myArray: " << myArray << endl;

  // Wartość:
  cout << "Wartość jaka znajduje się pod tym adresem: " << *myArray << endl;

  // W c++ tablica jest zapisywana w jednym miejscu w pamięci. Sprawdźmy teraz rozmar tej tablicy.
  cout << "Rozmar tablicy: " << sizeof(myArray) << endl;

  // Dlaczego wychodzi 20? Ponieważ każdy element tablicy zajmuje 4 bajty, a mamy w sumie 5 elementów.
  // Typ int zajmuje 4 bajty pamięci:
  cout << "sizeOf(Int) = " << sizeof(int) << endl;

  // Jeżeli chcemy uzyskać ilość elementów w tablicy, możemy podzielić jej całkowity rozmar przez rozmar jednego elementu:
  cout << "Ilość elementów = rozmar tablicy / rozmar jednego elementu." << endl
  << "sizeof(myArray) / sizeof(myArray[0]) = " << sizeof(myArray) / sizeof(myArray[0]) << endl;

  cout << "--------" << endl << endl << endl;

  // Wskaźniki można przesuwać!

  // Wypiszmy adresy każdego z elementów tablicy:
  // Końcówka adresu będzie rosnąć o 4, bo tyle zajmuje każdy element.
  cout << "&myArray[0] (lub myArray) - " << myArray << endl;
  cout << "&myArray[1] - " << &myArray[1] << endl;
  cout << "&myArray[2] - " << &myArray[2] << endl;
  cout << "&myArray[3] - " << &myArray[3] << endl;
  cout << "&myArray[4] - " << &myArray[4] << endl;


  cout << endl << endl;


  // Przesuńmy teraz wskaźnik z pierwszego elementu tablicy na ostatni i odczytajmy ich wartości:

  // Adres pierwszego elementu oraz jego wartość:
  cout << "Adres pod którym mieszka 1 element: " << myArray << "; wartość: " << *myArray << endl;

  // Przesuwamy o 4 "w prawo":
  cout << "Adres pod którym mieszka 5 element: " << &myArray + 4 << "; wartość: " << *(myArray +4) << endl;
  

  cout << endl << endl;


  // Przekazując coś do funkcji (np. zmienną int) fukncja pracuje na kopii, a oryginał pozostawia bez zmian.

  // Zobaczmy to w praktyce:
  int num{50};

  cout << "Zmienna num z main: " << num << endl;
  print_my_num(num);
  cout << "Zmienna num z main (pozostaje nienaruszona): " << num << endl << endl;

  // A co jeśli nie chcemy operować na kopii, tylko zamiast tego chcemy zmieniać oryginał?
  // Możemy wykorzystać wskaźnik/adres!

  // Wydrukujmy oryginalną tablicę, jeszcze przed modyfikacją:
  cout << "Tablica w main przed modyfikacją: " << endl;

  cout << "(Wywołane z main) -  Element 1: " << myArray[0] << endl;
  cout << "(Wywołane z main) -  Element 2: " << myArray[1] << endl;
  cout << "(Wywołane z main) -  Element 3: " << myArray[2] << endl;
  cout << "(Wywołane z main) -  Element 4: " << myArray[3] << endl;
  cout << "(Wywołane z main) -  Element 5: " << myArray[4] << endl;

  cout << endl;

  // Teraz przekażmy do funkcji adres naszej tablicy, następnie zmodyfikujmy każdy jej element dodając do niego 1.
  increment_all_elements_by_one(myArray, 5);

  cout << endl;

  // Żeby sprawdzić, czy rzeczywiście zmodyfikowaliśmy oryginał, wydrukujmy znowu tablicę w main:
  cout << "Tablica w main po modyfikacji: " << endl;

  cout << "(Wywołane z main) -  Element 1: " << myArray[0] << endl;
  cout << "(Wywołane z main) -  Element 2: " << myArray[1] << endl;
  cout << "(Wywołane z main) -  Element 3: " << myArray[2] << endl;
  cout << "(Wywołane z main) -  Element 4: " << myArray[3] << endl;
  cout << "(Wywołane z main) -  Element 5: " << myArray[4] << endl;

  cout << endl << endl;


  // Powtórzmy sobie znowu - jak zrobić by przekazując coś do funkcji działać na oryginale?
  // Sposób 1: w wykorzystaniem zmiennej pomocniczej *pointer_a.
  int a = 1;
  int *pointer_a = &a;

  cout << "Adres zmiennej a z main: " << pointer_a << endl;
  cout << "Wartość zmiennej a z main: " << a << endl;

  cout << endl;

  //Przekazujemy wskaźnik
  increment_my_num(pointer_a);

  cout << endl;

  cout << "Adres zmiennej a z main: " << pointer_a << endl;
  cout << "Wartość zmiennej a z main: " << a << endl;

  cout << endl << endl;

  // Sposób 2: skrócony zapis za pomocą & (przy parametrze funkcji)
  // W tym sposobie, nie musimy wykonywać wielu modyfikacji wewnątrz funkcji za pomocą & oraz *.
  int b = 1;

  cout << "[Sposób 2, skrócony] Adres zmiennej b z main: " << &b << endl;
  cout << "[Sposób 2, skrócony] Wartość zmiennej b z main: " << b << endl;

  cout << endl;

  // Dzięki skróconemu sposobowi, nie musimy podawać wskaźnika jako argument, wystarczy samo b :)
  increment_my_num2(b);

  cout << endl;

  cout << "[Sposób 2, skrócony] Adres zmiennej b z main: " << &b << endl;
  cout << "[Sposób 2, skrócony] Wartość zmiennej b z main: " << b << endl;
}