
## 制限事項

- zephyr version 3.6なら動作可能（ESP32S2-saolaの場合）
- v3.7だと、s11059センサが動作しなくなる。(ESP32-devkitc-wroomの場合)
- hc-sr04のドライバで使用している関数の中でv3.6以降でないとビルドできないものがある。

- wio lite riscvのi2cが動作しない。
