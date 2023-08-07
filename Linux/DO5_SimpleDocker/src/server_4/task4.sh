#!/bin/sh
docker pull nginx
docker build . -t my_container:1.0
sleep 1
docker images
docker run -v ${PWD}/nginx/nginx.conf:/etc/nginx/nginx.conf \
            -p 80:81 -d my_container:1.0
sleep 2          
curl localhost:80
curl localhost:80/status