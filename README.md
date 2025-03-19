# 🚗 Smart Parking System using IoT 🚦

## 📌 Overview
The **Smart Parking System** is an IoT-based solution designed to automate parking management. Using **IR sensors, an OLED display, a servo motor, and ESP8266**, the system detects available slots, updates real-time data on the **Blynk IoT platform**, and manages gate access efficiently. This project ensures seamless parking solutions with a user-friendly interface. 🚘✨

---

## 🌟 Features
✔ **Real-time Parking Slot Detection** using IR sensors  
✔ **OLED Display Integration** for instant slot updates  
✔ **Automated Gate Control** with a servo motor  
✔ **Blynk IoT Integration** for remote monitoring  
✔ **WiFi-Enabled (ESP8266)** for seamless communication  
✔ **Low Power Consumption** and cost-effective solution  

---

## 🛠 Components Used
🔹 **ESP8266 NodeMCU** – Microcontroller for IoT connectivity  
🔹 **IR Sensors (x2)** – Detect vehicle presence  
🔹 **Servo Motor** – Controls parking gate  
🔹 **OLED Display (SSD1306)** – Shows slot availability  
🔹 **Blynk IoT Platform** – Remote monitoring and notifications  
🔹 **Jumper Wires** – Essential wiring for connections  

---

## 🔌 Circuit Connections
| **Component**        | **ESP8266 NodeMCU Pin** |
|----------------------|-----------------------|
| **IR Sensor 1 (Out)** | D7 (GPIO13) |
| **IR Sensor 2 (Out)** | D6 (GPIO12) |
| **Servo Motor (Signal)** | D4 (GPIO2) |
| **OLED Display (SDA)** | D2 (GPIO4) |
| **OLED Display (SCL)** | D1 (GPIO5) |
| **VCC (IR Sensors, OLED, Servo)** | 3.3V / 5V |
| **GND (All Components)** | GND |

---

## 🚀 Installation & Setup Guide

### 2️⃣ Install Required Libraries
Ensure the following libraries are installed in **Arduino IDE**:
- `ESP8266WiFi.h`
- `BlynkSimpleEsp8266.h`
- `Servo.h`
- `Wire.h`
- `Adafruit_GFX.h`
- `Adafruit_SSD1306.h`

### 3️⃣ Update Credentials
Modify the following in **smart_parking.ino**:
```cpp
#define BLYNK_TEMPLATE_ID "ADD_YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "ADD_YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "ADD_YOUR_BLYNK_AUTH_TOKEN"
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";
```

### 4️⃣ Upload the Code
- Connect **NodeMCU** to your PC.
- Open **Arduino IDE** and select the correct board/port.
- Click **Upload** and wait for the process to complete.

### 5️⃣ Monitor System Output
- Open **Serial Monitor** (115200 baud rate) for debugging.
- Use the **Blynk app** to view real-time parking slot updates.

---

## 🎯 How It Works
1️⃣ **Vehicle Detection** – IR sensors detect vehicle presence.  
2️⃣ **OLED Display Update** – Available slots are shown dynamically.  
3️⃣ **Gate Operation** – If a slot is available, the servo motor opens the gate.  
4️⃣ **Blynk App Notification** – Users can check parking status remotely.  
5️⃣ **No Slots Available** – The gate remains closed until a slot is free.  

---

## 🔮 Future Enhancements
🚀 **Automated Payment System** – Smart billing integration  
🤖 **AI-based Slot Prediction** – Intelligent slot recommendation  
📷 **Camera-based Vehicle Recognition** – For security enhancement  
📡 **Cloud Data Storage** – Parking history & analytics  

---

**🌟 If you find this project useful, give it a ⭐ on GitHub!** 

**💡 Feel free to make changes and contribute!** 🚀

