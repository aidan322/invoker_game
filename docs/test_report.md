Test Report
General Information

Testing Framework: Google Test (gtest)

Test Types: Unit tests, Integration tests, Edge case tests

Tested Components: Invoker, Spell hierarchy, GameMode subclasses (ClassicMode, RankMode, AIMode), and AIPlayer logic

Unit Tests
Spell Tests

Tested all core spell subclasses:

ColdSnap, GhostWalk, EMP, Tornado, Alacrity, SunStrike, etc.

Validated:

Correct spell names and combos (getName(), getCombo())

Combo matching logic (matchesCombo())

Proper output formatting in Invoker::castSpell()

Invoker Tests

Verified key Invoker functionality:

Adding spells (addSpell)

Listing available spells (listSpells)

Combo lookup by name (getComboByName)

Combo validation (validateComboByName)

Casting known and unknown spells (castSpell)

GameMode Tests

Checked correct initialization and interaction flow for:

ClassicMode – free spell casting mode

RankMode – ranking system logic with score tracking

AIMode – timed spell casting and basic AI response

Each mode was tested for:

Correct prompts and user interaction structure

Proper use of Invoker methods

Mode name reporting (name())

Integration Tests
Mode Switching

Simulated sequential launching of all modes

Verified that internal state resets properly and invoker spell list persists

Spell Casting Sequence

Casted multiple spells in sequence (QWE, QQQ, WQE)

Confirmed correct output and absence of segmentation faults

AI Interaction

Simulated AIMode behavior

Verified AI chooses valid spells from the available list

Measured timing consistency and AI reaction handling

Edge Case Tests
Unknown Spells

Attempted to cast an unregistered spell name

Confirmed graceful handling with > (unknown spell: <name>) output

Empty Spell List

Invoked methods on Invoker without any added spells

Confirmed that listing and casting handle empty state without crash

Invalid Input Handling

Checked for stability on unexpected input values (empty string, lowercase spell name)

System remains stable and outputs consistent error messages

Summary

All tests compiled and passed successfully

No memory leaks detected during runtime (checked via valgrind)

Game core behaves as expected across all three modes

AI timing logic stable under repeated test runs