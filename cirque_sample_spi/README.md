Cirque Trackpad を使うファームウェアのサンプル

* mcuconf.h
  * SDA、SCL で使用するピンの I2C0 か I2C1 によって、TRUE/FALSE を変える
* config.h
  * I2C_DRIVER
    * SDA、SCL で使用するピンの I2C0 か I2C1 によって設定する値が変わる
      * I2C0: I2CD0
      * I2C1: I2CD1
  * `XXX_SCL_PIN`、`XXX_SDA_PIN`
    * SDA、SCL で使用するピンの I2C0 か I2C1 によって、XXX の部分を置き換える

```
curl -X POST -H "Content-Type: application/json" -d "{\"kb\": \"cirque_sample\", \"km\": \"default\", \"tag\": \"0.21.6\"}" 127.0.0.1:3123/build/qmk
```