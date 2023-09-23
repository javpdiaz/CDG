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

#define reset_button 33

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
  bounce_juez3_botton_izq.attach(juez3_botton_izq, INPUT);
  bounce_juez3_botton_der.interval(30);

  bounce_reset_button.attach(juez2_botton_izq, INPUT);
  bounce_reset_button.interval(30);

  //inicio de la configuracion de pantalla
  tft.begin();
  tft.setRotation(1);
  //tft.drawRect(0, 0, 106, 120, ILI9341_BLUE);
  tft.fillRect(0, 0, 106, 120, ILI9341_BLUE);
  tft.fillRect(106, 0, 107, 120, ILI9341_RED);
  tft.fillRect(213, 0, 107, 120, ILI9341_BLUE);
  tft.fillRect(0, 120, 106, 120, ILI9341_RED);
  tft.fillRect(106, 120, 107, 120, ILI9341_BLUE);
  tft.fillRect(213, 120, 107, 120, ILI9341_RED);


  /* tft.begin();

  tft.setCursor(26, 120);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello, TFT!");

  tft.setCursor(20, 160);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("I can has colors?"); */
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
    
  }

  if (bounce_juez1_botton_der.rose())
  {
    
  }

  if (bounce_juez2_botton_izq.rose())
  {
    
  }

  if (bounce_juez2_botton_der.rose())
  {
    
  }

  if (bounce_juez3_botton_izq.rose())
  {
    
  }

  if (bounce_juez3_botton_der.rose())
  {
    
  }

  if (bounce_reset_button.rose())
  {
    
  }
  

  // if(digitalRead(juez1_botton_izq) == 1){
  //   while (digitalRead(juez1_botton_izq) == 1)
  //   {
  //     delay(10);
  //   }

  //   BI_Cont ++;
    
  // }

}