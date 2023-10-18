// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "Bounce2.h"

//configuracion de pines de ILI9341
#define TFT_DC 2
#define TFT_CS 15
#define TFT_RST 4
#define TFT_MOSI 18
#define TFT_SCK 5
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, -1);

//Botones
#define juez1_botton_izq 26
#define juez1_botton_der 25
#define juez2_botton_izq 14
#define juez2_botton_der 27
#define juez3_botton_izq 13
#define juez3_botton_der 12

#define reset_button 35

//Contadores
int BI_Cont = 0;
int GAr_Cont = 0;
int BD_Cont = 0;
int CD_Cont = 0;
int CI_Cont = 0;
int GAb_Count = 0;

//Bounce declaracion
Bounce bounce_juez1_botton_izq = Bounce();
Bounce bounce_juez1_botton_der = Bounce();
Bounce bounce_juez2_botton_izq = Bounce();
Bounce bounce_juez2_botton_der = Bounce();
Bounce bounce_juez3_botton_izq = Bounce();
Bounce bounce_juez3_botton_der = Bounce();

Bounce bounce_reset_button = Bounce();

void setup() {
  
  //Declaracion de funcionalidad de pines
  pinMode(juez1_botton_izq, INPUT);
  pinMode(juez1_botton_der, INPUT);
  pinMode(juez2_botton_izq, INPUT);
  pinMode(juez2_botton_der, INPUT);
  pinMode(juez3_botton_izq, INPUT);
  pinMode(juez3_botton_der, INPUT);
  
  pinMode(reset_button, INPUT);
  

  //Adjuntar pines al bounce
  bounce_juez1_botton_izq.attach(juez1_botton_izq, INPUT);
  bounce_juez1_botton_izq.interval(30);
  bounce_juez1_botton_der.attach(juez1_botton_der, INPUT);
  bounce_juez1_botton_der.interval(30);
  bounce_juez2_botton_izq.attach(juez2_botton_izq, INPUT);
  bounce_juez2_botton_izq.interval(30);
  bounce_juez2_botton_der.attach(juez2_botton_der, INPUT);
  bounce_juez2_botton_der.interval(30);
  bounce_juez3_botton_izq.attach(juez3_botton_izq, INPUT);
  bounce_juez3_botton_izq.interval(30);
  bounce_juez3_botton_der.attach(juez3_botton_der, INPUT);
  bounce_juez3_botton_der.interval(30);

  bounce_reset_button.attach(reset_button, INPUT);
  bounce_reset_button.interval(30);

  //inicio de la configuracion de pantalla
  tft.begin();
  tft.setRotation(1);
  
  tft.fillScreen(ILI9341_BLUE);

  //rectangulos de la columna izquierda
  tft.fillRect(38, 13, 117, 50, ILI9341_CYAN);
  tft.fillRect(38, 68, 117, 50, ILI9341_CYAN);
  tft.fillRect(38, 123, 117, 50, ILI9341_CYAN);
  tft.fillRect(38, 178, 117, 50, ILI9341_CYAN);

  //rectangulos de la columna derecha
  tft.fillRect(165, 13, 117, 50, ILI9341_CYAN);
  tft.fillRect(165, 68, 117, 50, ILI9341_CYAN);
  tft.fillRect(165, 123, 117, 50, ILI9341_CYAN);
  tft.fillRect(165, 178, 117, 50, ILI9341_CYAN);

  //Ovalos de la columna izquierda
  tft.fillRoundRect(19, 13, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(19, 68, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(19, 123, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(19, 178, 65, 50, 20, ILI9341_WHITE);

  //Ovalos de la columna derecha
  tft.fillRoundRect(236, 13, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(236, 68, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(236, 123, 65, 50, 20, ILI9341_WHITE);
  tft.fillRoundRect(236, 178, 65, 50, 20, ILI9341_WHITE);

  //texto de la columna izquierda
  tft.setCursor(34, 26);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("BI");

  tft.setCursor(34, 80);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("CI");

  tft.setCursor(34, 135);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("GAr");

  tft.setCursor(34, 190);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("X");

  //texto de la columna derecha
  tft.setCursor(251, 26);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("BD");

  tft.setCursor(251, 80);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("CD");

  tft.setCursor(251, 135);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("GAb");

  tft.setCursor(251, 190);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_BLACK);
  tft.print("X");


}

void loop() { 

  //actualiza la instancia Bounce en cada loop
  bounce_juez1_botton_izq.update();
  bounce_juez1_botton_der.update();
  bounce_juez2_botton_izq.update();
  bounce_juez2_botton_der.update();
  bounce_juez3_botton_izq.update();
  bounce_juez3_botton_der.update();

  bounce_reset_button.update();

  //si hay un cambio de estado de bajo a alto se cumple pa condicion del if
  if (bounce_juez1_botton_izq.rose())
  {
    GAr_Cont++;
  }

  if (bounce_juez1_botton_der.rose())
  {
    GAb_Count++;
  }

  if (bounce_juez2_botton_izq.rose())
  {
    BI_Cont++;
  }

  if (bounce_juez2_botton_der.rose())
  {
    BD_Cont++;
  }

  if (bounce_juez3_botton_izq.rose())
  {
    CI_Cont++;
  }

  if (bounce_juez3_botton_der.rose())
  {
    CD_Cont++;
  }

  if (bounce_reset_button.rose())
  {
    BI_Cont = 0;
    GAr_Cont = 0;
    BD_Cont = 0;
    CD_Cont = 0;
    CI_Cont = 0;
    GAb_Count = 0;
  }

  
}