# ESP32-S3-Eye Projects - Basics

This repository contains basic projects and examples for learning ESP32-S3-Eye development using PlatformIO and Arduino framework.

## Hardware Overview

The ESP32-S3-Eye is a development board featuring:
- **ESP32-S3** dual-core processor (240MHz)
- **8MB PSRAM** (Octal SPI)
- **8MB Flash** memory
- **2MP Camera** (OV2640)
- **1.3" LCD Display** (240x240 pixels)
- **Microphone** for audio input
- **MicroSD card** slot
- **USB-C** connector (native USB support)
- **WiFi & Bluetooth** connectivity
- **Accelerometer** (3-axis)

## Learning Path - Basics

### 1. **Environment Setup & Board Configuration** ✅
- [x] PlatformIO configuration for ESP32-S3-Eye
- [x] Board-specific settings (Flash, PSRAM, USB CDC)
- [x] Basic GPIO and serial communication

### 2. **Core Functionality**
- [ ] **GPIO Control**: LEDs, buttons, digital I/O
- [ ] **Analog Input**: Reading sensors, ADC usage
- [ ] **PWM Output**: Motor control, LED dimming
- [ ] **Timers & Interrupts**: Precise timing, event handling

### 3. **Communication Protocols**
- [ ] **UART**: Serial communication with external devices
- [ ] **I2C**: Sensor communication (accelerometer, etc.)
- [ ] **SPI**: High-speed peripheral communication
- [ ] **USB CDC**: Native USB serial communication

### 4. **Wireless Connectivity**
- [ ] **WiFi Basics**: Connection, scanning, AP mode
- [ ] **HTTP Client**: REST API calls, web requests
- [ ] **HTTP Server**: Creating web interfaces
- [ ] **WebSocket**: Real-time communication
- [ ] **Bluetooth Classic**: Device pairing and communication
- [ ] **BLE (Bluetooth Low Energy)**: Efficient wireless communication

### 5. **Memory Management**
- [ ] **PSRAM Usage**: Large data handling, image buffers
- [ ] **Flash Storage**: SPIFFS, LittleFS file systems
- [ ] **EEPROM Emulation**: Persistent data storage
- [ ] **Memory Optimization**: Heap management, stack usage

### 6. **Display & Graphics**
- [ ] **LCD Control**: Basic display operations
- [ ] **Graphics Library**: Drawing shapes, text, images
- [ ] **Touch Interface**: Touch screen interaction
- [ ] **UI Framework**: LVGL integration

### 7. **Camera Basics**
- [ ] **Camera Initialization**: OV2640 setup and configuration
- [ ] **Image Capture**: Taking photos, streaming
- [ ] **Image Processing**: Basic filters, format conversion
- [ ] **Motion Detection**: Simple computer vision

### 8. **Audio Processing**
- [ ] **Microphone Input**: Audio capture and processing
- [ ] **Audio Analysis**: FFT, frequency detection
- [ ] **Voice Activity Detection**: Sound level monitoring
- [ ] **Audio Streaming**: Real-time audio transmission

### 9. **Sensors & Peripherals**
- [ ] **Accelerometer**: Motion detection, orientation
- [ ] **MicroSD Card**: File storage and retrieval
- [ ] **External Sensors**: Temperature, humidity, etc.
- [ ] **Actuators**: Servos, motors, relays

### 10. **Advanced Topics**
- [ ] **FreeRTOS Tasks**: Multitasking, task management
- [ ] **Deep Sleep**: Power management, wake-up sources
- [ ] **OTA Updates**: Over-the-air firmware updates
- [ ] **Security**: Encryption, secure communication
- [ ] **Performance Optimization**: CPU usage, memory efficiency

## Project Structure

```
esp32-s3-eye-projects/
├── basic/                          # Current basic examples
│   ├── src/main.cpp               # Basic demo (GPIO, WiFi, PSRAM)
│   ├── platformio.ini             # Board configuration
│   └── README.md                  # This file
├── gpio-control/                  # GPIO and basic I/O examples
├── communication/                 # UART, I2C, SPI examples
├── wifi-examples/                 # WiFi connectivity projects
├── display-graphics/              # LCD and graphics examples
├── camera-basics/                 # Camera capture and processing
├── audio-processing/              # Microphone and audio examples
├── sensors/                       # Sensor integration examples
├── advanced/                      # FreeRTOS, OTA, optimization
└── docs/                         # Documentation and guides
```

## Getting Started

### Prerequisites
- **PlatformIO IDE** (VS Code extension recommended)
- **ESP32-S3-Eye** development board
- **USB-C cable** for programming and power
- **WiFi network** for connectivity examples

### Quick Start
1. Clone this repository
2. Open the `basic` folder in PlatformIO
3. Update WiFi credentials in `src/main.cpp`
4. Build and upload to your ESP32-S3-Eye
5. Open Serial Monitor (115200 baud) to see output

### Board Configuration Notes
- Uses `esp32s3camlcd` board profile
- Configured for 8MB Flash + 8MB PSRAM
- USB CDC enabled for serial communication
- QIO flash mode for optimal performance

## Hardware Connections

### Built-in Components
- **LED**: GPIO 3 (built-in status LED)
- **Button**: GPIO 0 (BOOT button)
- **Camera**: Connected via dedicated camera interface
- **Display**: Connected via SPI interface
- **Microphone**: Connected via I2S interface
- **Accelerometer**: Connected via I2C interface

### External Connections
- **GPIO Pins**: Available for custom sensors/actuators
- **I2C**: SDA/SCL pins for additional sensors
- **SPI**: MISO/MOSI/SCK for high-speed peripherals
- **UART**: TX/RX pins for serial communication

## Troubleshooting

### Common Issues
1. **Upload Failed**: Hold BOOT button while uploading
2. **No Serial Output**: Ensure USB CDC is enabled in platformio.ini
3. **WiFi Connection Issues**: Check credentials and signal strength
4. **PSRAM Not Detected**: Verify board configuration and memory_type setting

### Useful Commands
```bash
# Build project
pio run

# Upload firmware
pio run --target upload

# Open serial monitor
pio device monitor

# Clean build files
pio run --target clean
```

## Next Steps

After completing the basics, you can explore:
- **Computer Vision**: Face detection, object recognition
- **IoT Integration**: Cloud connectivity, data logging
- **Machine Learning**: TensorFlow Lite integration
- **Real-time Applications**: Video streaming, live audio processing

## Resources

- [ESP32-S3 Technical Reference](https://www.espressif.com/sites/default/files/documentation/esp32-s3_technical_reference_manual_en.pdf)
- [ESP32-S3-Eye Hardware Guide](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-eye/index.html)
- [PlatformIO ESP32 Documentation](https://docs.platformio.org/en/latest/platforms/espressif32.html)
- [Arduino ESP32 Core](https://github.com/espressif/arduino-esp32)

## Contributing

Feel free to contribute examples, improvements, or additional learning materials. Please follow the existing project structure and include proper documentation.

## License

This project is open source and available under the MIT License. 