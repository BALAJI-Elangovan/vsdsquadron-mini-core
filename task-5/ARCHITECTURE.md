# System Architecture

## High-Level Architecture

+-------------------+
| UART Terminal |
+---------+---------+
|
v
+-------------------+
| Command Parser |
| main.c |
+---------+---------+
|
v
+-------------------+
| Pattern Engine |
| pattern.c |
+---------+---------+
|
v
+-------------------+
| GPIO Driver |
+---------+---------+
|
v
+-------------------+
| PD6 LED Hardware |
+-------------------+

---

## Software Layers

### Application Layer

Responsible for:

- Receiving commands
- Parsing user input
- Managing pattern execution
- Handling STOP requests

Files:

- main.c
- pattern.c

---

### Driver Layer

Provides hardware abstraction.

Components:

- GPIO Driver
- UART Driver

Files:

- gpio.c
- gpio.h
- uart.c
- uart.h

---

### Hardware Layer

CH32V003 peripherals:

- UART1
- GPIO Port D

---

## Data Flow

User Command

↓

UART Driver

↓

Command Parser

↓

Pattern Engine

↓

GPIO Driver

↓

LED Output

---

## Control Flow

System Reset

↓

GPIO Initialization

↓

UART Initialization

↓

Wait for Command

↓

Execute Pattern

↓

Return to Wait State

---

## Design Rationale

The layered architecture separates application logic from hardware-specific code.

Benefits:

- Reusability
- Maintainability
- Easier debugging
- Better scalability
- Industry-standard firmware structure
