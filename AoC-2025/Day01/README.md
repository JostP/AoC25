## Build in zagon

CMakeLists.txt še ne zajema gtesta. Vse skupaj najlažje buildamo in izvedemo z ukazi v terminalu:

```bash
cmake -B build
make -C build
g++ tests/test_main.cpp functions.cpp -lgtest -lpthread -o tests/tests
./tests/tests
./main
