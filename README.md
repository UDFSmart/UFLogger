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

---

## Pushing to Main & Creating Releases

UFLogger is set up with a GitHub Action to automatically:

  1. Compile the library examples for supported platforms (ESP32, AVR)
  2. Build a ZIP archive of the library
  3. Attach the ZIP to a GitHub release

### Workflow

  * Push code to main branch:
    * Automatically compiles the library on GitHub Actions to verify it builds correctly.
    * Detects errors before creating a release.

  * Create a release (via GitHub UI or git tags):
    * GitHub Actions automatically packages the library into UFLogger.zip.
    * The ZIP is attached to the release for download.

### Example: Creating a new release

```bash
# Push changes to main
git add .
git commit -m "Update UFLogger"
git push origin main

# Tag a new release
git tag vX.X.X
git push origin vX.X.X
```

After creating the tag, GitHub Actions will build the ZIP automatically and attach it to the release.
Users can then download UFLogger.zip and add it in Arduino IDE via Sketch → Include Library → Add .ZIP Library.
