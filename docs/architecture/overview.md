# Overview

## Purpose

This project is a console-based training application inspired by the Invoker training concept.
The system demonstrates a simple game core implemented with object-oriented design and includes multiple game modes: Rank Mode, Classic Mode and an AI timing trainer. The main goal is to show clear separation of responsibilities, simple AI logic and modes of interaction between components.

## High-level structure

The system is organized into the following modules:

* **main.cpp** — program entry point, reads user choice and launches selected game mode.
* **include/** — public headers for game modules (game modes, invoker, player, spells).
* **src/** — implementation files.
* **docs/architecture/** — architecture documentation (overview, requirements, test plan, UML and component diagrams).
* **CMakeLists.txt / Makefile** — build configuration.

## Main responsibilities

* Menu and mode selection.
* Mode-specific game flow (Rank Mode, Classic Mode, AI Timing Mode).
* Simple AI assistant that evaluates timing for a predefined combo (Tornado → Sun Strike).
* Cross-platform, terminal-based interaction.

## Technologies and tools

* Language: C++17
* Build: CMake (or Make)
* Unit tests: Google Test (optional)
* Documentation: Markdown (architecture docs) and Doxygen comments in source

## Directory layout (example)

```
project_root/
├── src/
│   ├── main.cpp
│   ├── ai_mode.cpp
│   └── ... 
├── include/
│   ├── ai_mode.hpp
│   └── ...
├── docs/
│   └── architecture/
│       ├── overview.md
│       ├── requirements.md
│       └── test_plan.md
├── CMakeLists.txt
└── README.md
```

## Notes

* The implementation aims to meet the lab minimal requirements: a working environment with multiple modes, an inheritance-based class hierarchy, a simple AI, and documentation.
* All interactions are terminal-based to maximize portability and avoid platform-specific raw input handling.

