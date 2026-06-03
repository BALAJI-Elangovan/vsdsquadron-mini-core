# Application Guide

## Objective

The application allows users to control LED blink patterns through UART commands.

---

## Startup Sequence

1. System boots
2. GPIO initialized
3. UART initialized
4. Welcome message displayed
5. System waits for commands

---

## Command Processing

### PLAY Command

Syntax:

PLAY <pattern>

Example:

PLAY 101010

Behavior:

- Stores pattern
- Starts execution
- Turns LED ON/OFF according to pattern bits

---

### STOP Command

Syntax:

STOP

Behavior:

- Stops active pattern execution
- Turns LED OFF
- Returns to idle state

---

## State Machine

INIT

↓

WAIT_FOR_COMMAND

↓

PLAY_RECEIVED

↓

PATTERN_EXECUTION

↓

PATTERN_COMPLETE

↓

WAIT_FOR_COMMAND

---

## Timing Behavior

Each character in pattern string:

500 ms

Example:

PLAY 101

Execution:

1 → LED ON → 500 ms

0 → LED OFF → 500 ms

1 → LED ON → 500 ms

---

## Edge Cases

### Empty Command

Ignored.

### Invalid Command

No action performed.

### STOP During Execution

Pattern immediately terminates.

### Pattern Completion

LED automatically turns OFF.
