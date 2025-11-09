# System Requirements

## 1. Functional Requirements

### 1.1 Core Functionality
The system must implement a simple console-based game framework with multiple modes:
- **Rank Mode** – simplified match for training and evaluation.
- **Classic Mode** – free play without evaluation.
- **AI Timing Mode** – training against a simple AI assistant that checks spell timing.

### 1.2 Object Interaction
- Each mode operates through a shared interface for launching and updating the game state.
- The game must support interaction between objects (Invoker, abilities, AI logic, user input).
- The system must handle basic game loops and input/output operations in the console.

### 1.3 AI Functionality
- The AI must provide simple evaluation logic:
  - Measure player's response time between two spells (Tornado → Sun Strike).
  - Compare actual delay with the ideal 0.5 seconds and output feedback.
- The AI logic should be encapsulated in a separate class derived from a base mode or behavior class.

### 1.4 Menu System
- Display available modes when the program starts.
- Wait for user selection and launch the corresponding game mode.
- Option to exit cleanly.

---

## 2. Non-Functional Requirements

### 2.1 Performance
- The game should respond instantly to user input (no noticeable delays in console).
- Build time should not exceed 10 seconds on a modern system.

### 2.2 Portability
- The program must compile and run on Linux, macOS, and Windows using g++ and CMake.

### 2.3 Code Quality
- Code should follow OOP principles:
  - Encapsulation
  - Inheritance (minimum 20 classes across modes and entities)
  - Polymorphism for different game modes
- Code must be well-commented and readable.

### 2.4 Documentation
- The architecture documentation must include:
  - Overview
  - Requirements
  - Component Diagram
  - Class Diagram (UML)
  - Test Plan
- Doxygen comments must be used in the code.

### 2.5 Testing
- The project should include at least several basic tests (unit or integration) for core components.
- A separate report (`docs/architecture/test_plan.md`) must describe the testing process.

---

## 3. Constraints
- Implementation language: **C++17**
- No graphical libraries or frameworks are required.
- Only standard C++ and STL are allowed.
- Console-only I/O.

---

## 4. Use Case Summary
| Actor | Action | System Response |
|--------|---------|----------------|
| Player | Launches the program | The main menu appears |
| Player | Selects Rank Mode | Rank Mode starts |
| Player | Selects Classic Mode | Classic Mode starts |
| Player | Selects AI Mode | AI Timing Mode starts |
| Player | Plays and exits | System shows summary or exits |

---

