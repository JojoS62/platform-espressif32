
// Camera Pin's for OV3660 M5Stack Timer Camera X
#if defined(T_Camera_M5)
#define PWDN_GPIO_NUM  -1
#define RESET_GPIO_NUM 15
#define XCLK_GPIO_NUM  27
#define SIOD_GPIO_NUM  25
#define SIOC_GPIO_NUM  23

#define Y9_GPIO_NUM    19
#define Y8_GPIO_NUM    36
#define Y7_GPIO_NUM    18
#define Y6_GPIO_NUM    39
#define Y5_GPIO_NUM    5
#define Y4_GPIO_NUM    34
#define Y3_GPIO_NUM    35
#define Y2_GPIO_NUM    32
#define VSYNC_GPIO_NUM 22
#define HREF_GPIO_NUM  26
#define PCLK_GPIO_NUM  21


#define CAMERA_LED_GPIO 2                                                                         // Camera Build In LED
#define CAMERA_Button_GPIO 2                                                                      // Button

#define RXD2_PIN 13                                                                               // RXD Grove Pin (RXD TXD VCC GND)
#define TXD2_PIN 4                                                                                // TXD Grove Pin (RXD TXD VCC GND)

#define BAT_OUTPUT_HOLD_PIN 33
#define BAT_ADC_PIN         38



#elif defined(T_Camera_PLUS_VERSION)
#define PWDN_GPIO_NUM       -1
#define RESET_GPIO_NUM      -1
#define XCLK_GPIO_NUM       4
#define SIOD_GPIO_NUM       18
#define SIOC_GPIO_NUM       23

#define Y9_GPIO_NUM         36
#define Y8_GPIO_NUM         37
#define Y7_GPIO_NUM         38
#define Y6_GPIO_NUM         39
#define Y5_GPIO_NUM         35
#define Y4_GPIO_NUM         26
#define Y3_GPIO_NUM         13
#define Y2_GPIO_NUM         34
#define VSYNC_GPIO_NUM      5
#define HREF_GPIO_NUM       27
#define PCLK_GPIO_NUM       25

#define I2C_SDA             18
#define I2C_SCL             23

#define IIS_SCK             14
#define IIS_WS              32
#define IIS_DOUT            33

#define TFT_CS_PIN          12
#define TFT_DC_PIN          15
#define TFT_MOSI_PIN        19
#define TFT_MISO_PIN        22
#define TFT_SCLK_PIN        21
#define TFT_BL_PIN          2

#define CAMERA_LED_GPIO     -1                                                                         // Camera Build In LED


//#define SDCARD_CS_PIN       0

#define ENABLE_IP5306
#define ENABLE_TFT

#elif defined(CAMERA_MODEL_AI_THINKER)
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

#define CAMERA_LED_GPIO   4                                                                      // Camera Build In LED

#endif