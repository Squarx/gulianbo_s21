sudo apt install nginx
service nginx status
sudo apt-get install build-essential

Подключение к nginx VM Win 10

## 7 Таск мануал

## 1. Установка Graphana

https://grafana.com/grafana/download?pg=oss-graf&plcmt=resources
Нужен VPN (18.05.2023 заблокирован доступ) (https://dl.grafana.com/enterprise/release/grafana-enterprise_9.4.7_amd64.deb)

```bash
sudo apt-get install -y adduser libfontconfig1
wget https://dl.grafana.com/enterprise/release/grafana-enterprise_9.4.7_amd64.deb
sudo dpkg -i grafana-enterprise_9.4.7_amd64.deb
```

```bash
sudo /bin/systemctl daemon-reload
sudo /bin/systemctl enable grafana-server
sudo /bin/systemctl start grafana-server
sudo /bin/systemctl status grafana-server
```

Graphana слушает порт 3000, так что надо в виртуалке прокинуть порт допустим
Ip host 127.0.0.1
Port host 3333
Port Guest 3000
Соответсвенно в браузере вводим `http://127.0.0.1:3333/` и нас выбрасывает на главное окно сервиса (admin admin)

## 2. Устанока Prometheus

```bash
cd ~
wget https://github.com/prometheus/prometheus/releases/download/v2.37.6/prometheus-2.37.6.linux-amd64.tar.gz 
tar zxvf prometheus-2.37.6.linux-amd64.tar.gz
cd prometheus-2.37.6.linux-amd64/
pwd
```

Нам нужны пути до файлов

* prometheus
* prometheus.yml

  => /home/g/prometheus-2.37.6.linux-amd64/prometheus
  => /home/g/prometheus-2.37.6.linux-amd64/prometheus.yml

Далее создаем файл сервиса

`sudo touch /etc/systemd/system/prometheus.service`

 В нем указываем следующее :

```
[Unit]
Description=Prometheus Server

[Service]
User=root
Restart=on-failure

ExecStart=/home/g/prometheus-2.37.6.linux-amd64/prometheus \
    --config.file=/home/g/prometheus-2.37.6.linux-amd64/prometheus.yml \

[Install]
WantedBy=multi-user.targe
```

После чего запускаем сервис

```bash
sudo /bin/systemctl daemon-reload
sudo systemctl restart prometheus
sudo systemctl status prometheus
```

Сервис слушает порт по умолчанию порт 9090  Не забыть прокинуть порты !
Ip host 127.0.0.1
Port host 4444
Port Guest 9090

И подключение  `http://127.0.0.1:4444/` оно выкинет на главное окно prometheus

## 3. Установка Node explorer

Сервис позволяющий юзать больше метрич чем в обычном prometheus

```
wget https://github.com/prometheus/node_exporter/releases/download/v1.2.2/node_exporter-1.2.2.linux-amd64.tar.gz
tar xvfz node_exporter-1.2.2.linux-amd64.tar.gz
cd node_exporter-1.2.2.linux-amd64/
```

По аналогии создаем
`sudo touch /etc/systemd/system/node_exporter.service` | | `sudo vim /etc/systemd/system/node_exporter.service`

Поле чего копируем туда следующее (заменить путь!)

```
[Unit]
Description=Node Exporter Server

[Service]
User=root
Restart=on-failure

ExecStart=/home/g/node_exporter-1.2.2.linux-amd64/node_exporter

[Install]
WantedBy=multi-user.targe
```

```bash
sudo /bin/systemctl daemon-reload
sudo systemctl restart node_exporter
sudo systemctl status node_exporter
```

node_exporter слушает порт `9100`

## 4. Добавление данных с Node Exporter  в Prometheus

  Для этого необходимо открыть

```
  /home/g/prometheus-2.37.6.linux-amd64/prometheus.yml
```

  И добавить job
  Было

```
  scrape_configs:
    # The job name is added as a label `job=<job_name>` to any timeseries scraped from this config.
    - job_name: "prometheus"

      # metrics_path defaults to '/metrics'
      # scheme defaults to 'http'.

      static_configs:
        - targets: ["localhost:9090"]


```

  Стало

```
scrape_configs:
  # The job name is added as a label `job=<job_name>` to any timeseries scraped from this config.
  - job_name: "prometheus"

    # metrics_path defaults to '/metrics'
    # scheme defaults to 'http'.

    static_configs:
      - targets: ["localhost:9090"]
  
  - job_name: "node"
    scrape_interval: 5s
    static_configs:
      - targets: ["localhost:9100"]
```

После чего перезапустить сервис Prometeus и узнать статус

Зайдите в интерфейс Grafana, используя логин и пароль, созданные при установке или настройке Grafana.
для отображения информации о ЦПУ можно использовать следующий запрос:
100 - (avg by(instance) (irate(node_cpu_seconds_total{mode="idle"}[5m])) * 100)
Для отображения информации об оперативной памяти можно использовать следующий запрос:
node_memory_MemAvailable_bytes / node_memory_MemTotal_bytes * 100
Для отображения информации о свободном месте на жестком диске можно использовать следующий запрос:
node_filesystem_avail_bytes{fstype="ext4"} / node_filesystem_size_bytes{fstype="ext4"} * 100

Для отображения информации о количестве операций ввода/вывода на жестком диске можно использовать следующий запрос:
irate(node_disk_io_time_seconds_total{device="sda",job="node"}[5m])

1. CPU

```
100 - (avg by (instance) (rate(node_cpu_seconds_total{job="node",mode="idle"}[1m])) * 100)

```

2. Available RAM

   ```
   node_memory_MemAvailable_bytes
   ```
3. Free memory

   ```
   node_filesystem_free_bytes{mountpoint="/",fstype!="tmpfs"}
   ```
4. IO

   ```
   rate(node_disk_io_now{device=~"sda.*", job="node"}[1m])
   ```
