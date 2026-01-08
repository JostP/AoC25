## Build in zagon
Vsaka številka v podanih intervalih predstavlja možen produkt ID. Za rešitev problema smo uporabili pristop, kjer sistematično preverimo vse ID-je znotraj danih intervalov.

V Part 1 za vsak ID preverimo, ali je sestavljen iz nekega zaporedja številk, ki se ponovi natanko dvakrat. Če je, ga štejemo kot neveljavnega in ga dodamo na seznam. Na koncu seštejemo vse neveljavne ID-je, kar predstavlja rezultat prvega dela naloge.

V Part 2 dodatno preverimo, ali se katera podvrstica številk ponovi vsaj dvakrat, ne glede na dolžino podvrstice. Če je pogoj izpolnjen, ID šteje kot neveljaven. Nato seštejemo vse te neveljavne ID-je, kar predstavlja rezultat drugega dela naloge.


CMakeLists.txt ne zajema gtesta. Vse skupaj najlažje buildamo in izvedemo z ukazi v terminalu (linux):

```bash
cmake -B build
make -C build
g++ tests/test_main.cpp functions.cpp -lgtest -lpthread -o tests/tests
./tests/tests
./main
