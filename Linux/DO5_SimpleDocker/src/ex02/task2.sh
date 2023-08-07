#!/bin/bash
set -e
docker pull nginx
docker run -p 80:80 -p 443:443 -d nginx
dockerId=$(docker ps | awk '{print $1}' | head -2 | tail -1)
imageId=$(docker images | grep -e "^nginx " |  awk '{print $3}' | head -2 | tail -1)
echo $dockerId
docker exec $dockerId cat /etc/nginx/nginx.conf
docker cp ./nginx/nginx.conf $dockerId:/etc/nginx/nginx.conf
docker exec $dockerId service nginx reload
docker exec $dockerId curl curl 127.0.0.1:80/status
docker container export -o ${PWD}/container.tar $dockerId

docker stop $dockerId
docker rmi -f $imageId
echo "rm dockerID"
docker rm $dockerId
echo "Importing"
docker import -c 'cmd ["nginx", "-g", "daemon off;"]' \
                -c 'ENTRYPOINT ["/docker-entrypoint.sh"] ' container.tar  nginx_v2
docker images
imageId=$(docker images | grep -e "^nginx_v2" |  awk '{print $3}' | head -2 | tail -1)
echo "New image id" $imageId
sudo docker run -p 80:80 -p 443:443 -d $imageId
sleep 2
curl 127.0.0.1:80/status
exit 0