#include <Arduino.h>
#include <esp_camera.h>                                                                           // ESP Camera https://github.com/espressif/esp32-camera
#include "camera_pins.h"                                                                          // Camera Pins OV3660
#include "camera_config.h"                                                                        // Camera config
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
    Serial.print("Start ms ");
    Serial.println(millis());

    // esp_camera_deinit();
    // camera_config_jpg();
    
    change_Picture_Format_to_JPEG();
    
    take_Camera_Image_JPG();                                                                       // Bild aufnehmen JPG
    Serial.print("Jpg Buffer Len ");
    Serial.println(fb_jpg->len);
    esp_camera_fb_return(fb_jpg);
    take_Camera_Image_JPG();                                                                       // Bild aufnehmen JPG
    Serial.print("Jpg Buffer Len ");
    Serial.println(fb_jpg->len);
    esp_camera_fb_return(fb_jpg);
    take_Camera_Image_JPG();                                                                       // Bild aufnehmen JPG
    Serial.print("Jpg Buffer Len ");
    Serial.println(fb_jpg->len);
    esp_camera_fb_return(fb_jpg);
    fb_jpg = NULL;

    //esp_camera_deinit();
    //camera_config_gray();

#if 1
    change_Picture_Format_to_GRAYSCALE();
    
    take_Camera_Image_GRAY();
    Serial.print("Gray Buffer Len ");
    Serial.println(fb_gray->len);
    esp_camera_fb_return(fb_gray);
    take_Camera_Image_GRAY();
    Serial.print("Gray Buffer Len ");
    Serial.println(fb_gray->len);
    esp_camera_fb_return(fb_gray);
    take_Camera_Image_GRAY();
    Serial.print("Gray Buffer Len ");
    Serial.println(fb_gray->len);
    esp_camera_fb_return(fb_gray);
    fb_gray = NULL;
    Serial.print("Ende ms ");
    Serial.println(millis());
#endif

    Timer_Millis = millis();                                                            // Zeit merken
  }
}

void loop() {
  Take_Pictures();
}  

