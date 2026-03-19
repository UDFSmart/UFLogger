# UFLogger


UfLogger is a lightweight and flexible logging library for Arduino projects,
compatible with ESP8266, ESP32, and classic Arduino boards.

The library provides a unified logging interface with support for levels:
error, warning, info, debug, and verbose.

Features:
- ESP32 support via built-in esp32-hal-log
- Arduino compatibility via Serial
- Configurable logging level using USER_DEBUG_LEVEL
- Minimal memory usage (compile-time macros)
- Unused log levels are automatically stripped during compilation
- Output includes file and line information (for errors and warnings)

Logging levels:
1 — errors (log_e)
2 — warnings (log_w)
3 — info (log_i)
4 — debug (log_d)
5 — verbose (log_v)

Usage example:

```cpp
#include <UFLogger.h>

void setup() {
  Serial.begin(115200);

  log_e("Error occurred: %d", 1);
  log_w("Warning message");
  log_i("System started");
  log_d("Debug value: %d", 42);
}
```

Setting the logging level:

```cpp
#define USER_DEBUG_LEVEL 3
#include <UfLogger.h>

```

UfLogger automatically removes unused log levels at compile time,
making it fast and efficient even for memory-constrained devices.
