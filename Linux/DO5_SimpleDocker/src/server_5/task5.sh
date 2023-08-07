#!/bin/bash
docker pull nginx
imageId=$(docker images | grep -e "^my_container " |  awk '{print $3}' | head -2 | tail -1)
docker rmi -f $imageId
echo "Start building"
export DOCKER_CONTENT_TRUST=1
docker build . -t my_container:1.0
docker images
imageId=$(docker images | grep -e "^my_container " |  awk '{print $3}' | head -2 | tail -1)
echo "Checking $imageId:"
dockle -ak NGINX_GPGKEY -ak NGINX_GPGKEY_PATH my_container:1.0
echo "Docker run..."   
sudo docker run -v ${PWD}/nginx/nginx.conf:/etc/nginx/nginx.conf \
            -p 80:81 -d my_container:1.0
sleep 1
echo "curls ..."            
curl localhost:80
curl localhost:80/status