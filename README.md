# Motion Sensor with ESP32

## Description
This project uses an ESP32 along with a PIR Motion Sensor to detect motion in its environment. When motion is detected, the system sends a notification via Telegram. The project is ideal for security applications or automating tasks based on motion detection.

## Features
- Motion detection using PIR Motion Sensor.
- ESP32 used for processing and communication.
- Telegram integration to send notifications when motion is detected.
- Simple and easy setup for home automation or security alerts.

## Required Materials
- 1x ESP32
- 1x PIR Motion Sensor
- 1x Jumper wires (for connections)
- 1x Power supply (for the ESP32)

## Assembly Instructions
1. Connect the PIR Motion Sensor to the ESP32:
   - The VCC pin of the sensor goes to the 3V pin of the ESP32.
   - The GND pin of the sensor goes to the GND pin of the ESP32.
   - The OUT pin of the sensor goes to a digital pin on the ESP32 (e.g., D2).

2. Use the Arduino IDE or your preferred development platform to program the ESP32.
3. In the code, implement the connection to the Wi-Fi network and the Telegram Bot for notifications when motion is detected.
4. Insert the Bot Token from Telegram and the Chat ID in the code for message delivery.

## Telegram Setup
1. Create a new bot in Telegram by chatting with [BotFather](https://core.telegram.org/bots#botfather).
2. Get your **Bot Token** from BotFather.
3. Find your **Chat ID** by messaging your bot and using the [Telegram API](https://api.telegram.org/bot<YourBotToken>/getUpdates) to retrieve it.
4. Replace `YOUR_BOT_TOKEN` and `YOUR_CHAT_ID` in the code with your actual bot token and chat ID.

## Contributions
Feel free to contribute by opening an issue or creating a pull request with improvements or new features!