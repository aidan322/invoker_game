# System Architecture

## Overview
The **Invoker Training Simulator** is built using an object-oriented design that separates gameplay logic, spell mechanics, AI control, and user interaction.  
This modular structure allows easy extension and testing.

## Main Components
1. **Game Engine**
   - Coordinates all gameplay processes.
   - Manages mode selection (Rank, Classic, AI).
   - Updates game state and handles user input.

2. **Player / AI Controller**
   - `Player` handles manual input from the user.
   - `AIController` simulates automated spell sequences and timing.

3. **Spell System**
   - Includes spell definitions (`Tornado`, `Sun Strike`, etc.).
   - Responsible for combo logic and cooldown tracking.

4. **Timing System**
   - Measures time intervals between casts.
   - Evaluates player accuracy and gives feedback.

5. **UI Layer**
   - Displays mode selection, combo prompts, and results.
   - Provides clear feedback (e.g., “Too early”, “Perfect”, “Too late”).

## Data Flow

