#!/bin/bash
# Создаем массивы характеристик агентов
browser_versions=("Chrome/90.0.4430.72" "Firefox/89.0" "Safari/14.1" "Opera/76.0" "Edge/91.0.864.37" "Brave/1.24.86")
os_versions=("Windows NT 10.0; Win64; x64" "Windows NT 6.1; Win64; x64" "Macintosh; Intel Mac OS X 10_15_7" "iPad; CPU OS 14_4 like Mac OS X" "Linux x86_64")
screen_resolutions=("1920x1080" "1440x900" "1366x768" "1280x1024")
languages=("ru-RU,ru;q=0.9,en-US;q=0.8,en;q=0.7" "en-US,en;q=0.5" "ja-JP")
methods=("GET" "POST" "PUT" "PATCH" "DELETE")
response_codes=("200" "201" "400" "401" "403" "404" "500" "501" "502" "503")
urls=(
"https://yandex.ru/"
"https://youtube.com/"
"https://google.com/"
"https://vk.com/"
"https://mail.ru/"
"https://ok.ru/"
"https://avito.ru/"
"https://instagram.com/"
"https://turbopages.org/"
"https://gismeteo.ru/"
"https://wildberries.ru/"
"https://facebook.com/"
"https://wikipedia.org/"
"https://google.ru/"
"https://market.yandex.ru/"
"https://kinopoisk.ru/"
"https://lenta.ru/"
"https://ria.ru/"
"https://gosuslugi.ru/"
"https://ozon.ru/"
"https://rambler.ru/"
"https://rbc.ru/"
"https://news.mail.ru/"
"https://xvideos.com/"
"https://aliexpress.ru/"
"https://drom.ru/"
"https://sberbank.ru/"
"https://twitter.com/"
"https://facebook.net/"
"https://championat.com/"
"https://mk.ru/"
"https://pikabu.ru/"
"https://whatsapp.com/"
"https://novostinedeli24.com/"
)
ext=(
"gif"
"png"
"jpg"
"mp4"
"mp3"
"html"
)


for i in {1..5}
do
  date=$(date +%Y-%m-%d -d "$i day ago")
  filename="access_$date.log"
  touch $filename

  num_records=$((RANDOM % 901 + 100))

  for (( j=0; j<$num_records; j++ ))
  do
  ip=$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256)).$((RANDOM % 256))
  method=${methods[$((RANDOM % ${#methods[@]}))]}
  ext_rand=${ext[$RANDOM % ${#ext[@]} ]}
  url="/page_$((RANDOM % 10)).$ext_rand"
  response_code=${response_codes[$((RANDOM % ${#response_codes[@]}))]}
  rand_browser_version=${browser_versions[$RANDOM % ${#browser_versions[@]} ]}
  rand_os_version=${os_versions[$RANDOM % ${#os_versions[@]} ]}
  rand_screen_resolution=${screen_resolutions[$RANDOM % ${#screen_resolutions[@]} ]}
  rand_language=${languages[$RANDOM % ${#languages[@]} ]}

  # Создаем строку агента клиента, объединяя выбранные случайным образом характеристики
  user_agent="Mozilla/5.0 ($rand_os_version) AppleWebKit/537.36 (KHTML, like Gecko) $rand_browser_version Safari/537.36"
  user_agent="$user_agent; resolution=$rand_screen_resolution; lang=$rand_language"

  curr_timestamp=$(date -u +%s)

  new_timestamp=$(echo "$curr_timestamp - (5 * 24 * 60 * 60)" | bc)

  random_timestamp=$(shuf -i "$new_timestamp-$curr_timestamp" -n 1)

  random_date=$(date -u -d @$random_timestamp +"%d/%b/%Y:%H:%M:%S %z")
  url_st=${urls[$RANDOM % ${#urls[@]}]}
  echo "$ip - - [$random_date] \"$method $url HTTP/1.0\" $response_code $((RANDOM % 1000)) $url_st \"$user_agent\"" >> $filename
  done
done