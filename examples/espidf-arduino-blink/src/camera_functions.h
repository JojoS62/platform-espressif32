#include <Arduino.h>
camera_config_t config;

void camera_config_gray(){
    pinMode(CAMERA_LED_GPIO, OUTPUT);                                                               // LED
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer   = LEDC_TIMER_0;
    config.pin_d0       = Y2_GPIO_NUM;
    config.pin_d1       = Y3_GPIO_NUM;
    config.pin_d2       = Y4_GPIO_NUM;
    config.pin_d3       = Y5_GPIO_NUM;
    config.pin_d4       = Y6_GPIO_NUM;
    config.pin_d5       = Y7_GPIO_NUM;
    config.pin_d6       = Y8_GPIO_NUM;
    config.pin_d7       = Y9_GPIO_NUM;
    config.pin_xclk     = XCLK_GPIO_NUM;
    config.pin_pclk     = PCLK_GPIO_NUM;
    config.pin_vsync    = VSYNC_GPIO_NUM;
    config.pin_href     = HREF_GPIO_NUM;
    config.pin_sccb_sda = SIOD_GPIO_NUM;
    config.pin_sccb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn     = PWDN_GPIO_NUM;
    config.pin_reset    = RESET_GPIO_NUM;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_GRAYSCALE;                                                    // Graustufen Bild
    config.frame_size   = FRAMESIZE_CIF;                                                        // Auflösung 96x96 Pixel
    config.jpeg_quality = 12;                                                                     // Qualität 
    config.fb_count     = 2;                                                                      // Anzahl Framerbuffer
    config.fb_location  = CAMERA_FB_IN_PSRAM;
    config.grab_mode    = CAMERA_GRAB_WHEN_EMPTY;
       
    esp_err_t err = esp_camera_init(&config);                                                      // camera init
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err);
        return;
    }
    sensor_t *s = esp_camera_sensor_get();
    // initial sensors are flipped vertically and colors are a bit saturated
    s->set_vflip(s, 1);        // flip it back
    s->set_brightness(s, 1);   // up the blightness just a bit
    s->set_saturation(s, -2);  // lower the saturation
    //s->set_framesize(s, FRAMESIZE_QVGA); // drop down frame size for higher initial frame rate

}

void camera_config_jpg(){
    pinMode(CAMERA_LED_GPIO, OUTPUT);                                                               // LED
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer   = LEDC_TIMER_0;
    config.pin_d0       = Y2_GPIO_NUM;
    config.pin_d1       = Y3_GPIO_NUM;
    config.pin_d2       = Y4_GPIO_NUM;
    config.pin_d3       = Y5_GPIO_NUM;
    config.pin_d4       = Y6_GPIO_NUM;
    config.pin_d5       = Y7_GPIO_NUM;
    config.pin_d6       = Y8_GPIO_NUM;
    config.pin_d7       = Y9_GPIO_NUM;
    config.pin_xclk     = XCLK_GPIO_NUM;
    config.pin_pclk     = PCLK_GPIO_NUM;
    config.pin_vsync    = VSYNC_GPIO_NUM;
    config.pin_href     = HREF_GPIO_NUM;
    config.pin_sccb_sda = SIOD_GPIO_NUM;
    config.pin_sccb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn     = PWDN_GPIO_NUM;
    config.pin_reset    = RESET_GPIO_NUM;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG; 
    config.frame_size   = FRAMESIZE_UXGA;
    config.jpeg_quality = 12;                                                                     // Qualität 
    config.fb_count     = 2;                                                                      // Anzahl Framerbuffer
    config.fb_location  = CAMERA_FB_IN_PSRAM;
    config.grab_mode    = CAMERA_GRAB_WHEN_EMPTY;
    esp_err_t err = esp_camera_init(&config);                                                      // camera init
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err);
        return;
    }

    sensor_t *s = esp_camera_sensor_get();
    // initial sensors are flipped vertically and colors are a bit saturated
    s->set_vflip(s, 1);        // flip it back
    s->set_brightness(s, 1);   // up the blightness just a bit
    s->set_saturation(s, -2);  // lower the saturation

 
    //s->set_framesize(s, FRAMESIZE_QVGA); // drop down frame size for higher initial frame rate
}


camera_fb_t * fb_gray = NULL;                                                                     // Data structure of camera frame buffer
camera_fb_t * fb_jpg = NULL;                                                                      // Data structure of camera frame buffer

bool change_Picture_Format_to_JPEG() {
  sensor_t *s = esp_camera_sensor_get();
  if (s == NULL) {
    Serial.println("Error: problem reading camera sensor settings");
    return 0;
  }
  
  // s->set_pixformat(s,PIXFORMAT_JPEG); 
  s->set_framesize(s, FRAMESIZE_UXGA);

    esp_camera_change_resolution(&config, FRAMESIZE_UXGA);


  return 1;
}

bool change_Picture_Format_to_GRAYSCALE() {
  sensor_t *s = esp_camera_sensor_get();
  if (s == NULL) {
    Serial.println("Error: problem reading camera sensor settings");
    return 0;
  }
  // s->set_pixformat(s,PIXFORMAT_GRAYSCALE); 
  s->set_framesize(s,FRAMESIZE_CIF);

  esp_camera_change_resolution(&config, FRAMESIZE_CIF);

  return 1;
}

void take_Camera_Image_JPG(){                                                                         // Bild aufnehmen
  //change_Picture_Format_to_JPEG();
  fb_jpg = esp_camera_fb_get();                                                                       // Bild in Framerbuffer
  if (!fb_jpg){                                                                                       // Bei Fehler
    Serial.println("photo failed");
    while(1);                                                                                     //stop
  }
}

void take_Camera_Image_GRAY(){                                                                         // Bild aufnehmen
  //change_Picture_Format_to_GRAYSCALE();
  fb_gray = esp_camera_fb_get();                                                                       // Bild in Framerbuffer
  if (!fb_gray){                                                                                       // Bei Fehler
    Serial.println("photo failed");
    while(1);                                                                                     //stop
  }
}