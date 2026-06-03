# API Reference

## GPIO Driver

### gpio_init()

```c
void gpio_init(void);
```

#### Description

Initializes GPIO Port D and configures PD6 as output.

#### Parameters

None

#### Returns

None

#### Example

```c
gpio_init();
```

---

### led_on()

```c
void led_on(void);
```

#### Description

Sets PD6 HIGH and turns LED ON.

#### Parameters

None

#### Returns

None

#### Example

```c
led_on();
```

---

### led_off()

```c
void led_off(void);
```

#### Description

Clears PD6 and turns LED OFF.

#### Parameters

None

#### Returns

None

#### Example

```c
led_off();
```

---

## UART Driver

### uart_init()

```c
void uart_init(void);
```

#### Description

Initializes UART1 peripheral for serial communication.

#### Parameters

None

#### Returns

None

#### Example

```c
uart_init();
```

---

### uart_tx()

```c
void uart_tx(char c);
```

#### Description

Transmits a single character through UART.

#### Parameters

| Parameter | Description |
|------------|-------------|
| c | Character to transmit |

#### Returns

None

#### Example

```c
uart_tx('A');
```

---

### uart_rx()

```c
char uart_rx(void);
```

#### Description

Receives a single character from UART.

#### Parameters

None

#### Returns

Received character.

#### Example

```c
char c = uart_rx();
```

---

### uart_print()

```c
void uart_print(char *str);
```

#### Description

Transmits a null-terminated string through UART.

#### Parameters

| Parameter | Description |
|------------|-------------|
| str | String to transmit |

#### Returns

None

#### Example

```c
uart_print("Hello\r\n");
```

---

## Pattern Engine

### play_pattern()

```c
void play_pattern(char *buf);
```

#### Description

Executes an LED pattern sequence.

Character meanings:

| Character | Action |
|------------|---------|
| 1 | LED ON |
| 0 | LED OFF |

#### Parameters

| Parameter | Description |
|------------|-------------|
| buf | Pattern string |

#### Returns

None

#### Example

```c
play_pattern("101010");
```

#### Notes

Each bit is executed for 500 ms.
