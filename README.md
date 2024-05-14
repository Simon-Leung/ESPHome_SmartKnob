# ESPHome_SmartKnob
Home Assistant integration using ESPHome on an esp32-S3 knob screen board, featuring knob and screen functionalities

## Introduction
This repository contains some experimental setup for using the esp32-S3 knob screen board within Home Assistant.

## Hardware
### ZX2D10GE01R-V4848
WT32-S3-WROVER-N16R8 + 2.1 inch RGB LCD(480*480) +16MB NOR FLASH + 8MB PSRAM + MT8901 hall sensor(knob)

![knob_screen.png](https://s2.loli.net/2024/05/10/dVN1E2aLirB8tlU.png)

See more on: http://doc.panel-tag.cn/ESP32-S3/ZX2D10GE01R-V4848.html

example: https://github.com/wireless-tag-com/ZX2D10GE01R-V4848

Schematic:
![Schematic](https://s2.loli.net/2024/05/10/NwW6PuQT9mIaZC3.jpg)

[product manual download](http://doc.panel-tag.cn/_static/espboard/ESP32S3/ZX2D10GE01R-V4848.pdf)

## Software
Environment:
- pythone version - 3.12.3
- esphome version - 2024.5.0b3

Initially inspired by @[lukasz-tuz](https://github.com/lukasz-tuz)'s [esphome-gui](https://github.com/lukasz-tuz/esphome-gui).

With spi interface and RGB interface Pin Reuse, after display is initialized, we need to free the spi bus.
