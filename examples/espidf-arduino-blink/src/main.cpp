#include <Arduino.h>
#include <esp_camera.h>                                                                           // ESP Camera https://github.com/espressif/esp32-camera
#include "camera_pins.h"                                                                          // Camera Pins OV3660
                                                                      // Camera config
#include "camera_functions.h"                                                                     // Camera Funktionen

unsigned long Timer_Millis;


void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(3000);
  Serial.println("setup start V1");
  
  camera_config_jpg();
  // camera_config_gray();
  
  Serial.println("setup done");
  //camera_config_jpg();

  bool hasPSRam = psramFound();
  printf("has PSRam %d\n", hasPSRam);
}

void Take_Pictures(){                                                           // Aktualisieren Winsocks Clients
  if ((Timer_Millis + 2000) < millis()){                                                 // Alle ?? mS
    int framecount = 10;
    unsigned long start = millis();

    change_Picture_Format_to_JPEG();

    unsigned long stop = millis();
    unsigned long diff = stop - start;

    printf("change to UXGA took: %ld ms\n", diff);

    start = millis();
    for (int i = 0; i < framecount; i++) {
      take_Camera_Image_JPG();                                                                       // Bild aufnehmen JPG
      Serial.print("Jpg Buffer Len ");
      Serial.println(fb_jpg->len);
      esp_camera_fb_return(fb_jpg);
    }

    stop = millis();
    diff = (stop - start) / framecount;

    printf("time per frame for %d frames is %ld ms\n", framecount, diff);    

    // 2nd resolution
    start = millis();

    change_Picture_Format_to_GRAYSCALE();

    stop = millis();
    diff = stop - start;

    printf("change to CIF took: %ld ms\n", diff);

    
    start = millis();
    for (int i = 0; i < framecount; i++) {
      take_Camera_Image_GRAY();
      Serial.print("Gray Buffer Len ");
      Serial.println(fb_gray->len);
      esp_camera_fb_return(fb_gray);
    }

    stop = millis();
    diff = (stop - start) / framecount;

    printf("time per frame for %d frames is %ld ms\n", framecount, diff);   

    Timer_Millis = millis();                                                            // Zeit merken
  }
}

void loop() {
  Take_Pictures();
}  

