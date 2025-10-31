# User Manual

## Overview
The **Invoker Training Simulator** is a console-based mini-game that helps players practice spell casting and timing combinations inspired by the Dota 2 hero Invoker.

## Starting the Game
1. Open the terminal in the project directory.  
2. Build the project:
   ```bash
   cd build
   cmake ..
   make
Run the executable:

./lab_oop_game

Game Modes

When the program starts, select one of the following modes:

Rank Mode – Competitive scoring system with multiple spell sequences.

Classic Mode – Standard Invoker training; cast combos without time limits.

AI Mode – Timing practice mode that measures your accuracy vs. ideal cast delay.

To exit, choose 0.

How to Play

Follow the on-screen instructions.

Type the spell combo (for example:

Tornado → QWWR

Sun Strike → EEER)

Press Enter after each combo.

In AI Mode, the system measures the time between spells and evaluates your timing accuracy.

Example Output
Select mode:
1. Rank Mode
2. Classic Mode
3. AI Mode
0. Exit
> 3

--- AI Timing Mode (Tornado -> Sun Strike) ---
Goal: Cast Sun Strike 0.5s after Tornado.

Cast Tornado (type combo then Enter): wwqr
Tornado cast recorded.
Now cast Sun Strike (type combo then Enter): eeer

You waited: 0.48 s
Result: Perfect timing!

Notes

Timing precision under 0.1s is considered perfect.

The AI mode simulates real Invoker combo timing (Tornado lift ~2.2s, Sun Strike delay ~1.7s).

The game is written in C++17 using object-oriented programming principles.

Credits

Developed by Айдан Монгуш.
Educational project for OOP Laboratory Work, Saint Petersburg State University.
