## Build in zagon

Trenutna konfiguracija `CMakeLists.txt` še ne vključuje knjižnice **Google Test (gtest)**.  
Zaradi tega se projekt najlažje zgradi in zažene neposredno prek ukazne vrstice.

```bash
cmake -B build
make -C build
g++ tests/test_main.cpp functions.cpp -lgtest -lpthread -o tests/tests
./tests/tests
./main
