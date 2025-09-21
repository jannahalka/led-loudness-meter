# Arduino Volume Meter (RMS) — PlatformIO
Realtime loudness meter using the Arduino Nano 33 BLE Sense.
Captures audio from the on-board PDM microphone, computes RMS loudness, and maps it to the on-board RGB LED brightness.

No external hardware required.

---

## Features
- Realtime audio capture @ 16 kHz (PDM mic)
- RMS calculation per frame
- Serial output for debugging values

---

## Requirements
- PlatformIO
- Arduino core for mbed_nano (PlatformIO auto-installs it)
- Board: `nano33ble`

---

## Quickstart
```
# 1) Clone this repo
git clone https://github.com/jannhalka/led-loudness-meter.git
cd led-loudness-meter

# 2) Build & upload (adjust port)
pio run --target upload

# 3) Open serial monitor
pio device monitor -b 115200
```

---

## Demo
- Clap or play music → LED brightness increases.
- Silence → LED dims.
- Serial Monitor shows RMS values in real time.
