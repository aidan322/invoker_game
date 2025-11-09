# Test Report

## General Information
**Testing Framework:** Google Test (gtest)  
**Test Type:** Unit Tests  
**Tested Components:**  
- `Spell` – spell logic and combo matching  
- `Invoker` – spell management and combo validation  
- `Player` – field and card management  
- `RankMode` – ranking system timing logic

---

## Unit Tests

### Spell Tests
**File:** `spell.hpp`  
**Test:** `MatchesComboIgnoresCaseAndSpaces`  
**Purpose:** Verify that combo matching works correctly regardless of case and spacing.  
**Validated:**  
- `qqq` and `Q Q Q` are recognized as equivalent  
- Incorrect combos (`QQE`, `q Q w e`) are properly rejected  

**Result:** Passed

---

### Invoker Tests
**File:** `invoker.hpp`  
**Test:** `CanFindComboByName`  
**Purpose:** Validate that the Invoker can correctly find and verify spell combos by name.  
**Validated:**  
- `getComboByName("tornado")` returns `"WWQ"`  
- `validateComboByName("sun_strike", "e e e")` returns true  
- Invalid combos are correctly rejected  

**Result:** Passed

---

### Player Tests
**File:** `player.hpp`  
**Test 1:** `FieldInitialization`  
**Purpose:** Ensure that the player field is initialized correctly.  
**Validated:**  
- The field starts empty  
- All slots initially contain `"EmptySlot"`  

**Result:** Passed  

**Test 2:** `MoveCardToFieldWorks`  
**Purpose:** Verify that cards can be successfully placed on the field.  
**Validated:**  
- `moveCardToField()` correctly places the `"Invoker"` card in the selected slot  

**Result:** Passed

---

### RankMode Tests
**File:** `rank_mode.hpp`  
**Test:** `RanksOutputTimeThresholds`  
**Purpose:** Check that the rank timing logic behaves correctly within defined limits.  
**Validated:**  
- Time value `12.0` seconds falls within the expected range (10–15 seconds)  

**Result:** Passed

---

## Summary

| Component | Test Count | Passed | Status |
|------------|-------------|---------|--------|
| Spell      | 1 | 1 | Passed |
| Invoker    | 1 | 1 | Passed |
| Player     | 2 | 2 | Passed |
| RankMode   | 1 | 1 | Passed |
| **Total**  | **5** | **5** | **All Passed** |

---

## Observations
- Tests cover the core gameplay logic (spells, invoker, player, ranking mode).  
- All tests compiled and executed successfully.  
- No crashes or memory leaks observed during test execution.  
- System behavior remains stable under tested scenarios.

---

## Recommendations
- Add unit tests for `AIMode` and `Card` classes.  
- Extend test coverage with integration tests to validate interactions between modules.  
- Include performance and stress testing for AI timing and spell-casting sequences.
