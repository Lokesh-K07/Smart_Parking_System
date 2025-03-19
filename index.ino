#define BLYNK_TEMPLATE_ID "ADD_YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "ADD_YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "ADD_YOUR_BLYNK_AUTH_TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define Ir1 D7
#define Ir2 D6

#include <Servo.h>

Servo myServo;  // Create servo object

#define SERVO_PIN D4  // Servo connected to GPIO2 (D4 on NodeMCU)

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width
#define SCREEN_HEIGHT 64  // OLED display height

#define OLED_RESET -1  // Reset pin (not used)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "WIFI_NAME";
char pass[] = "WIFI_PASSWORD";

void setup()
{
  
  // Debug console
  Serial.begin(115200);
  pinMode(Ir1,INPUT);
  pinMode(Ir2,INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

   myServo.attach(SERVO_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is the I2C address
        Serial.println("SSD1306 allocation failed");
        for (;;);  // Stop execution if display initialization fails
    }

}

void loop()
{
  Blynk.run();
  int s1=digitalRead(Ir1);
  int s2=digitalRead(Ir2);

  if (s1==0)
  {
    s1=1;
    }
   else
   {
    s1=0;
    }
  if (s2==0)
  {
    s2=1;
    }
   else
   {
    s2=0;
    }
  Blynk.virtualWrite(V0,s1);
  Blynk.virtualWrite(V1,s2);
  delay(300);
  if (s1==0 && s2==0)
  {
    Blynk.virtualWrite(V2,"Two SLots Available");
    myServo.write(180);
    display.clearDisplay();
    display.setTextSize(2);       // Text size
    display.setTextColor(WHITE);  // White text
    display.setCursor(10, 20);    // Position
    display.println("Two SLots Available");
    display.display();
    delay(300);
    }
   if (s1==1 && s2==0)
  {
    Blynk.virtualWrite(V2,"One SLot Available");
          myServo.write(180);
       display.clearDisplay();
    display.setTextSize(2);       // Text size
    display.setTextColor(WHITE);  // White text
    display.setCursor(10, 20);    // Position
    display.println("One SLot Available");
    display.display();
    delay(300);
    }
   if (s1==0 && s2==1)
  {
    Blynk.virtualWrite(V2,"One SLot Available");
        myServo.write(180);
         display.clearDisplay();
    display.setTextSize(2);       // Text size
    display.setTextColor(WHITE);  // White text
    display.setCursor(10, 20);    // Position
    display.println("One SLot Available");
    display.display();
    delay(300);
    }
   if (s1==1 && s2==1)
  {
    Blynk.virtualWrite(V2,"No SLots Available");
      myServo.write(0);
         display.clearDisplay();
    display.setTextSize(2);       // Text size
    display.setTextColor(WHITE);  // White text
    display.setCursor(10, 20);    // Position
    display.println("No SLots Available");
    display.display();
    delay(300);
    }
}
