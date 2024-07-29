
## 制限事項

- zephyr version 3.6なら動作可能（ESP32S2-saolaの場合）
- v3.7だと、s11059センサが動作しなくなる。(ESP32-devkitc-wroomの場合)
- hc-sr04のドライバで使用している関数の中でv3.6以降でないとビルドできないものがある。

- wio lite riscvのi2cが動作しない。

## ビルド

```
west build -p -d test_hc_sr04/ -b esp32s2_saola ./zephyr/samples/syuukyou/test_hc-sr04/

west build -p -d test_s11059 -b esp32s2_saola ./zephyr/samples/syuukyou/test_s11059/
```

## Flash

```
west flash -d ./test_hc_sr04/
cu -s 115200 -l /dev/ttyUSB0

west flash -d ./test_s11059/
cu -s 115200 -l /dev/ttyUSB0
```
