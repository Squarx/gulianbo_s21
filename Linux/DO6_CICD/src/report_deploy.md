## Part 5. Этап деплоя

Написать bash-скрипт, который при помощи **ssh** и **scp** копирует файлы, полученные после сборки (артефакты), в директорию */usr/local/bin* второй виртуальной машины

```bash
#!/bin/bash
set -e
scp  cat/s21_cat grep/s21_grep \
root@192.168.100.10:/usr/local/bin
```

Для переброса файлов по ssh
зайти на пользователя gitlab-runner

```bash
sudo su gitlab-runner
```

Сгенерировать ssh-ключ и прочитать его

```bash
ssh-keygen
```

```bash
cat /home/gitlab-runner/.ssh/<keyname>.pub
```

![1686405347414](image/report/1686405347414.png)

Данный ключ необходим на машине для деплоя

На ней необходимо зайти на root и найти authorized_keys

```bash
cd /root/.ssh
```

![1686405507652](image/report/1686405507652.png)

И вставить туда полученный ключ с нашего хоста

![1686405673845](image/report/1686405673845.png)

Так же отключить вход на root при помощи ssh по паролю

```bash
vim /etc/ssh/sshd_config
```

И поставить в строке `PasswordAuthentication no`

![1686405871762](image/report/1686405871762.png)

После перезагрузить службы ssh

```bash
service ssh restart
```

```bash
systemctl restart ssh
```

Теперь заходим на первую машину и пробуем

```bash
ssh root@<ip_machine>
```

![1686406087238](image/report/1686406087238.png)

Если пароль не спрашвиает, то все верно

Конфиги машин

![1686406245436](image/report/1686406245436.png)
