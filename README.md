# Invoker Game — Lab OOP Game (minimal)

**Author:** Монгуш Айдан Тимурович, группа 24.Б82-мм  
**Email:** st133061@student.spbu.ru

## Description
Minimal terminal implementation of "Invoker" training game (three modes):
- **Rank Mode** — invoke shuffled spells as fast as you can, time → rank.
- **Classic Mode** — free practice, type spell names/combinations.
- **AI Timing Mode** — timing practice for Tornado → Sun Strike combo.

Project is C++17, built with CMake. Executable: `lab_oop_game`.

## Build
# from project root
mkdir -p build
cd build
cmake ..
make -j$(sysctl -n hw.ncpu)   # on Linux: make -j$(nproc)
##Run
./lab_oop_game



## Tests
cd tests
make
./runTests
