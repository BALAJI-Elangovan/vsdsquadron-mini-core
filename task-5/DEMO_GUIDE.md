# Demo Guide

## Hardware Required

- VSDSquadron Mini
- USB Cable
- PC with PlatformIO

---

## Build Firmware

```bash
pio run
```

## Flash Firmware

```bash
pio run -t upload
```

## Open UART Terminal

```bash
pio device monitor
```

## UART Configuration

Baud Rate : 115200

Data Bits : 8

Parity : None

Stop Bits : 1

---

## Expected Startup Message

```text
Pattern Sequencer Ready
```

---

## Demo 1

Input:

```text
PLAY 101010
```

Expected UART Output:

```text
PLAYING
DONE
```

Expected Hardware Result:

LED blinks ON/OFF repeatedly.

---

## Demo 2

Input:

```text
PLAY 11110000
```

Expected Result:

LED remains ON for 2 seconds.

LED remains OFF for 2 seconds.

---

## Demo 3

Input:

```text
STOP
```

Expected UART Output:

```text
STOPPED
```

Expected Hardware Result:

LED turns OFF immediately.

---

## Verification Checklist

✓ Build successful

✓ Flash successful

✓ UART communication functional

✓ PLAY command functional

✓ STOP command functional

✓ LED pattern execution verified
