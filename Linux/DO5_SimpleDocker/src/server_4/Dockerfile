FROM nginx

COPY server.c /home/
COPY nginx/nginx.conf /etc/nginx/
COPY configure.sh /docker-entrypoint.d/
RUN apt-get update -y; \
    apt-get upgrade -y; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    rm -rf /var/lib/apt/lists/*; \
    gcc -o /home/server /home/server.c -lfcgi -Wall -Werror
CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["/docker-entrypoint.sh"]

