# Test Plan

## Purpose
This document defines the testing strategy for the Invoker Training Simulator project.  
The goal of testing is to verify the correct functioning of spell combinations, timing accuracy, and AI-assisted interactions.

## Objectives
- Ensure all combos execute in the correct sequence.
- Validate input recognition and spell casting precision.
- Confirm correct AI behavior and response times.
- Detect and fix gameplay or timing bugs.

## Test Levels
1. **Unit Testing**
   - Focuses on testing individual modules (Combo, AI, UI, Game Engine).
   - Uses mock data for timing and input validation.

2. **Integration Testing**
   - Ensures that all modules interact correctly.
   - Tests real combos involving both player and AI.

3. **System Testing**
   - Verifies the complete gameplay loop.
   - Tests user interface, input handling, and final output accuracy.

4. **Acceptance Testing**
   - Confirms that the simulator meets all project requirements.
   - Performed on the final integrated build.

## Test Scenarios
| ID | Scenario Description | Expected Result |
|----|----------------------|-----------------|
| T1 | Player performs `Cold Snap + Tornado + Sun Strike + Meteor + Blast` combo | Correct timing feedback displayed |
| T2 | AI executes the same combo automatically | Timing accuracy compared with baseline |
| T3 | Player inputs incorrect spell order | Error message and failed combo shown |
| T4 | UI displays score after each attempt | Correct result output |

## Tools
- Manual testing via simulator interface.
- Logging utilities for timing accuracy.
- GoogleTest for unit and integration testing.

## Evaluation Criteria
A test is considered successful if:
- All combos execute within the defined timing tolerance.
- No runtime errors or crashes occur.
- Feedback to the player is accurate and responsive.

