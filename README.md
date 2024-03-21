# posttest3-praktikum-iot-unmul

## Kelompok 4 IOT C 2022 
1. Aprisa Idma Mutiara (2209106001)
2. Narupa Rangga Goroguta (2209106004)
3. Juniver Veronika Lili (2209106013)
   
## Kontrol dan Monitor Value Suhu dengan Menggunakan Platform Thinger.io
**Deskripsi :** 
Proyek ini bertujuan untuk membuat sebuah sistem IoT yang menggunakan mikrokontroler ESP8266 untuk mengontrol sebuah LED, mengambil data dari sensor DHT11, dan mengintegrasikan semua informasi ini ke dalam dashboard platform Thinger.io. Pada proyek ini, hasil deteksi dari sensor DHT11 akan dikonversikan menjadi Celsius, Fahrenheit, dan Kelvin, dan ditampilkan juga pada dashboard Thinger.io.

**Cara kerja alat :** 
Pada proyek ini, LED digunakan untuk mengetahui perubahan suhu yang diterima oleh sensor DHT11 dari lingkungan sekitarnya. Jika suhu kurang dari 30°C, maka LED hijau akan menyala dan LED kuning, merah serta buzzer akan tetap mati. Jika suhu berada di antara 30°C sampai 36°C, maka LED kuning akan menyala dan LED hijau, merah serta buzzer akan tetap mati. Jika suhu lebih dari 36°C maka LED merah akan menyala dan buzzer akan bersuara. Sedangkan LED hijau dan kuning dalam kondisi mati. Suhu yang diterima oleh sensor akan dikirimkan ke thinger.io dan akan dikonversikan menjadi Celcius, Fahrenheit dan Kelvin yang ditampilkan ke dashboard Thinger.io. 
   
**Pembagian tugas :**
1. Aprisa Idma Mutiara : membuat struktur kodingan 
2. Narupa Rangga Goroguta : membuat rangkaian our schematic
3. Juniver Veronika Lili : membuat rangkaian board schematic
   
**Komponen yang Digunakan :**
1. Kabel jumper
2. LED
3. Resistor
4. Breadboard
5. ESP8266
6. Kabel MicroUSB
7. Buzzer
8. Sensor DHT11

**Board Schematic :**
![board skematik pt 3 iot](https://github.com/aprisamutiara/posttest3-praktikum-iot-unmul/assets/123526722/c3d9081c-8697-41f1-b81a-46e4419b026c)

**Our Schematic :**
![our skematik pt 3 iot](https://github.com/aprisamutiara/posttest3-praktikum-iot-unmul/assets/123526722/294ca03e-1c0a-4c29-8953-2d6b56db052d)
