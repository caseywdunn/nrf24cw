# Arduino wireless


## NRF24

### Hardware

Pinout - https://tmrh20.github.io/RF24/

Purchased these:

- https://www.amazon.com/gp/product/B06WLH4ZG6/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1

- https://www.amazon.com/gp/product/B00O9O868G/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1

- https://www.ebay.com/itm/NRF24L01-PA-LNA-SMA-Antenna-Wireless-Transceiver-communication-module-2-4G-1100m/310651702557?ssPageName=STRK%3AMEBIDX%3AIT&_trksid=p2057872.m2749.l2649


### Tutorials

#### Electronoob

https://www.youtube.com/watch?v=vxF1N9asjts

http://electronoobs.com/eng_arduino_tut95.php

#### Mechatronics

Bidirectional communication -
- https://www.youtube.com/watch?v=7rcVeFFHcFM

- https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/


### Improving stability and range

https://web.archive.org/web/20180825143815/https://blog.blackoise.de/2016/02/fixing-your-cheap-nrf24l01-palna-module/

Included channel_scanner code. In my shop, last 30 or so channels were much more clear than the lower ones.


### Libraries

#### RF24

https://tmrh20.github.io/RF24/

### My project

D2 - button
D3 - LED
D4 - ID1
D5 - ID2
D6 - ID3
D7 - CE  NRF24
D8 - CSN NRF24

Using the RF24 library
