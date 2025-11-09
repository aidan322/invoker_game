# Invoker Game — Lab OOP Game (minimal)

**Author:** Монгуш Айдан Тимурович, группа 24.Б82-мм  
**Email:** st133061@student.spbu.ru  

## Description
Minimal terminal implementation of "Invoker" training game with three modes:
- **Rank Mode** — invoke shuffled spells as fast as you can (time → rank)
- **Classic Mode** — free practice mode (type spell names or combinations)
- **AI Timing Mode** — practice timing for Tornado → Sun Strike combo

Project is written in **C++17** and built with **CMake**.  
Main executable: `lab_oop_game`.

## Build
```bash
mkdir -p build
cd build
cmake ..
make -j$(sysctl -n hw.ncpu)   # on Linux: make -j$(nproc)
```
## Run
```bash
./lab_oop_game
```
## Tests
```bash
cd tests
make
./runTests
```