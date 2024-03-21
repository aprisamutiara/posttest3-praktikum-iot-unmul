#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include <DHT.h> 

// hotspot
#define SSID "Infinix NOTE 30" //Hotspot yang dipakai
#define SSID_PASSWORD "2209106013"

// konfig thinger
#define USERNAME "juniververonikalili"
#define DEVICE_ID "IOT_PRAK" // Lihat pada setting dari device yang sudah dibuat di thinger.io
#define DEVICE_CREDENTIAL "8Liwa4!xvNCqXFYt" // Lihat pada setting dari device yang sudah dibuat di thinger.io (Generate random saja)

// penggunaan pin
#define DHT_PIN D4      // Pin DHT11
#define DHT_TYPE DHT11 
#define PIN_BUZZER D2 // Pin BUZZER
#define LED_MERAH D5   // Pin LED MERAH
#define LED_KUNING D6  // Pin LED KUNING
#define LED_HIJAU D7     // Pin LED HIJAU

// Inisialisasi objek untuk terhubung ke Thinger.io
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Inisialisasi objek untuk DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// variabel suhu 
float suhu, suhu_kelvin, suhu_fahrenheit;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);

  // mengaktifkan sensor dht
  dht.begin();

  // menghubungkan esp ke thinger.io
  thing.add_wifi(SSID, SSID_PASSWORD);
  
  // untuk membaca suhu di thinger
  thing["Suhu"] >> [](pson& out){
    // float suhu_celcius = dht.readTemperature(); // Baca suhu dari sensor DHT
    suhu_fahrenheit = (suhu * 9 / 5) + 32; // Konversi ke Fahrenheit
    suhu_kelvin = suhu + 273; // Konversi ke Kelvin

    // Menyimpan nilai suhu dalam objek out
    out["Celcius"] = suhu;
    out["Fahrenheit"] = suhu_fahrenheit;
    out["Kelvin"] = suhu_kelvin; 
  };
}

void loop() {
  thing.handle();
  suhu = dht.readTemperature();
  if(suhu < 30) {
      digitalWrite(LED_HIJAU, HIGH);  // LED hijau menyala
      digitalWrite(LED_KUNING, LOW);
      digitalWrite(LED_MERAH, LOW);
      noTone(PIN_BUZZER);
  }else if(suhu >= 30 && suhu <= 36) {
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(LED_KUNING, HIGH);  // LED kuning menyala
    digitalWrite(LED_MERAH, LOW);
    noTone(PIN_BUZZER);
  }else {
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(LED_KUNING, LOW);
    digitalWrite(LED_MERAH, HIGH);     // LED merah menyala
    tone (PIN_BUZZER, 100);
  }
}