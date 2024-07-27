# Przejście C -> C++ na przykładzie przeciążania funkcji
W zadaniu chodzi o to, aby płynnie przejść z C -> C++,
dlatego dzisiejsze zadania sprowadzają się do użycia w C++ tego,
co w C było znacznie trudniejsze i bardziej podatne na błędy.
C++ umożliwia tworzenie wielu funkcji o tej samej nazwie, różniących się argumentami.

Osoby zaawansowane mogą użyć zaawansowanych mechanizmów - szablonów, fold expressions itp
Nie muszą też do każdego z podpunktów tworzyć oddzielnej funkcji.

### Utrudnienie - makra preprocesora
Zadanie zawiera testy automatyczne, które testują czy dana metoda jest zaimplementowana poprawnie. Jeśli metody nie ma a byłaby testowana to byłby błąd kompilacji. Tym samym zadanie można by oddać wyłącznie jako wszystko lub jako nic. Dlatego też korzystam z makr preprocesora, które zależnie od tego czy dana funkcjonalność jest zaimplementowana czy nie aktywują (w trakcie kompilacji) odpowiednie części kodu. Czyli Państwo po zaimpelemtowaniu danej metody będą musieli zmazać odpowiednią linijkę `UNIMPLEMENTED_abcFunction`.


Treść do wykonania:
-----
1. Zdefiniuj funkcję `print`, która przyjmie liczbę całkowitą, wyświetli ją oraz pustą linię.
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithSingleInteger`
2. Zdefiniuj funkcję `print`, która przyjmie liczbę rzeczywistą, wyświetli ją oraz pustą linię.
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithSingleDouble`
3. Zdefiniuj funkcję `print`, która przyjmie poniższą strukturę Fraction, wyświetli ją (format licznik/mianownik) oraz pustą linię.
   - Osoby zaawansowane mogą przeciążyć operator strumienia
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithSingleFraction`
4. Zdefiniuj funkcję `print`, która przyjmie wskaźnik do tekstu, wyświetli go oraz pustą linię.
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithSingleCString`
5. Zdefiniuj funkcję `print`, która przyjmie obiekt niekopiowalnego typu `NotCopyableType`, oraz wyświetli go (tylko jego liczbę) oraz pustą linię.
   - Osoby zaawansowane mogą przeciążyć operator strumienia
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithSingleNotCopyableObject`
6. Zdefiniuj funkcję `print`, która przyjmie tablicę liczb (jeden argument to tablica, drugi to rozmiar tablicy).
   najlepiej aby liczby byly oddzielone przecinkami i spacjami (", "), ale aby na końcu linii nie było ", "
   - osoby zaawansowane mogą spróbować nie używać pętli jawnie
   - osoby zaawansowane mogą spróbować nie podawać rozmiaru (zakładamy, że argumentem jest tablica o rozmiarze znanym w trakcie kompilacji)
   - Po zdefiniowaniu jej usuń/zakomentuj jedno z makr (zależnie od wyboru): `UNIMPLEMENTED_printWithArrayOfNumbersAndSize` lub `UNIMPLEMENTED_printWithArrayOfNumbersWithoutSize`
7. Zdefiniuj funkcję `print`, która nie przyjmuje żadnych argumentów, a wyświetla jedynie nową linię.
   - Po zdefiniowaniu jej usuń makro/zakomentuj: `UNIMPLEMENTED_printWithoutArguments`
8. [dla zaawansowanych] Zdefiniuj funckje `print`, która przyjmie dowolną ilość dowolnych argumentów dowolnego typu i je wyświetli oddzielając spacją.
   Funkcja powinna być zrobiona na jeden z dwóch sposobów (to obsługują testy):
   - korzystając z makr języka C (wtedy nazwijmy ja `print2`), dla uproszczenia niech to bedzie dowolna ilosc intow
   - korzystając z fold expressions
   Zależnie od wyboru usuń jedno z makr: `UNIMPLEMENTED_printWithAnyArgumentsCStyle` i/lub `UNIMPLEMENTED_printWithAnyArgumentsTemplates`


Informacje jak czytać testy znajdują się w materiale [wideo](https://banbye.com/watch/v_Uo2SOGN3yCsX).
____________________________________________________________________________________
Po implementowaniu powyższych poleceń i zmiany wartości poniższych makr powinno przechodzić
coraz więcej testów dostępnych w pliku `printingTests.cpp`.

## Uwaga:
Sugeruję pisać porządnie, czyli deklaracje funkcji w pliku nagłówkowym, definicje w źródłowym
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Mozna tworzyc dowolna ilosc metod pomocniczych, najlepiej w pliku źródłowym.

[Bardziej szczegółowe informacje jak pisać programy w ładnym stylu](https://programowaniec.wordpress.com/2017/11/09/czego-sie-czepiam/) dla zaawansowanych.
____________________________________________________________________________________
## Ocenianie:
1. Ocenia [Bobot](https://gitlab.com/agh-courses/bobot), na ten moment w następujący sposób:
   1. Kompilacja nadesłanego rozwiązania - bez tego zero punktów. Bobot pracuje na Linuxie, używa kompilatora `g++`.
   2. Uruchamianie testów - za każdy test, który przejdzie są punkty, ale mogą być odjęte w kolejnych krokach.
   3. Jeśli program się wywala na którymś z testów (to się pojawia często u osób pracujących na Windowsie - ten system pozwala pisać po nie-swojej pamięci, Linux nie pozwala) lub jest timeout - wtedy będzie przyznane tyle punktów ile przechodzi testów **minus karne punkty**.
   4. Jest odpalane narzędzie [valgrind](https://valgrind.org/), które sprawdza czy umiemy obsługiwać pamięć w praktyce - jeśli nie to **minus punkt**.
   5. Odpalane są też inne narzędzia takie jak [cppcheck](http://cppcheck.net/), czy [fawfinde](https://dwheeler.com/flawfinder/) i inne. One nie odejmują punktów, no ale mają pomóc w pisaniu porządnych programów. Nie olewajmy tego.
   6. Antyplagiat - za wykrycie plagiatu (jest specjalne narzędzie) otrzymuje się 0 punktów. Wysyłajmy więc swoje!
____________________________________________________________________________________
## Najczestrze pytania/błędy/problemy:
1. Są rozbieżności między treścią `README.md`, a treściami w plikach nagłówkowych!
   - W tym roku przechodzimy na `README.md`, więc ta treść jest wiążąca.
2. Zrobiłem wg treści i się nie kompiluje.
   - Poza samym robieniem wg instrukcji należy pamiętać, że piszemy w C++, nie podaje dokładnych typów zwracanych funkcji,
   a trzeba pamiętać o nich definiując sygnaturę funkcji.

____________________________________________________________________________________
# Pytania po implementacji ćwiczenia:
1. Jakie wady/zalety ma możliwość przeładowywania nazwy funkcji?

____________________________________________________________________________________
# Zadania, które warto zrobić (uwaga: nie będzie za to punktów, tylko coś cenniejszego - umiejętności)
1. Swego czasu przygotowałem [więcej zadań pomagających przejść C->C++](https://github.com/baziorek/cpp/blob/main/1przeskokC_doCpp.ipynb), zachęcam aby spróbować je zrobić u siebie lokalnie nie przez Jupyter Notebook (ten do C++ wcale nie jest do C++).
   1. Zadanie 1 - jest to w ramach tej paczki
   2. Zadanie 2 - kopiowanie tablic dynamicznych
   3. Zadanie 3 - typ `std::string` i zakresowa pętla for.

____________________________________________________________________________________
# Jak skonfigurować sobie pracę nad paczką:
W formie [wideo](https://banbye.com/watch/v_i79PoGIWrjRC) - jest to instrukcja dla innej paczki (z innego kierunku), ale kroki są analogiczne.

**Alternatywnie poniżej jest to spisane w kolejnej sekcji**
____________________________________________________________________________________
## Grading (section copied from Mateusz Ślażyński, of course he agreed):

* [ ] Make sure, you have a **private** group
  * [how to create a group](https://docs.gitlab.com/ee/user/group/#create-a-group)
* [ ] Fork this project into your private group
  * [how to create a fork](https://docs.gitlab.com/ee/user/project/repository/forking_workflow.html#creating-a-fork)
* [ ] Add @bobot-is-a-bot as the new project's member (role: **maintainer**)
  * [how to add an user](https://docs.gitlab.com/ee/user/project/members/index.html#add-a-user)

## How To Submit Solutions

1. [ ] Clone repository: `git clone` (clone only once the same repository):

    ```bash
    git clone <repository url>
    ```
2. [ ] Solve the exercises
3. [ ] Commit your changes

    ```bash
    git add <path to the changed files>
    git commit -m <commit message>
    ```
4. [ ] Push changes to the gitlab main branch

    ```bash
    git push -u origin main
    ```

The rest will be taken care of automatically. You can check the `GRADE.md` file for your grade / test results. Be aware that it may take some time (up to one hour) till this file. Details can be found in `./logs/` directory where You can check compilation results, tests logs etc.

## Project Structure

    .
    ├── lab1Functions               # directory containing exercises
    |   ├── CMakeLists.txt          # CMake configuration file - the file is to open out project in our IDE
    |   ├── main.cpp                # main file - here we can test out solution manually, but it is not required
    |   ├── printing.h              # file to create class declaration and methods' declaration
    |   ├── printing.cpp            # file to implement methods
    |   ├── tests                   # here are tests for exercise, inner CMakeLists.txt, GTest library used by tests
    │   │   ├── CMakeLists.txt      # iner CMake for tests - it is included by outter CMake
    │   │   ├── printingTests.cpp   # files with tests for exercise
    │   │   └── lib                 # directory containing GTest library
    |   └── README.md               # this file
