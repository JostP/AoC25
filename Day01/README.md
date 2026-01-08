## Build in zagon
Vsako vrtenje številčnice predstavlja premik kazalca po krožni številčnici od 0 do 99. Za rešitev problema smo uporabili pristop, kjer sistematično obdelamo vsako vrtenje in posodabljamo trenutno pozicijo kazalca.

V Part 1 po vsakem vrtenju preverimo, ali kazalec konča na številki 0. Če je tako, povečamo števec, ki na koncu predstavlja geslo za prvi del naloge.

V Part 2 dodatno upoštevamo, kolikokrat kazalec med samim vrtenjem prečka številko 0, ne glede na to, kje konča. To izvedemo tako, da za vsako vrtenje izračunamo razdaljo do 0 glede na smer vrtenja in ugotovimo, kolikokrat med premikom prečkamo 0. Nato posodobimo končno pozicijo kazalca.

Na koncu vsak del vrne število prehodov ali končnih položajev na 0, kar predstavlja geslo za ustrezni del naloge.


CMakeLists.txt ne zajema gtesta. Vse skupaj najlažje buildamo in izvedemo z ukazi v terminalu (linux):

```bash
cmake -B build
make -C build
g++ tests/test_main.cpp functions.cpp -lgtest -lpthread -o tests/tests
./tests/tests
./main
