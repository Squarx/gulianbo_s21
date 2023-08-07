FROM nginx

COPY server.c /home/
COPY nginx/nginx.conf /etc/nginx/
COPY configure.sh /docker-entrypoint.d/
RUN apt-get update -y;\
    apt-get upgrade -y; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    rm -rf /var/lib/apt/lists/*; \
    gcc -o /home/server /home/server.c -lfcgi -Wall -Werror; \
    chmod u-s bin/mount; \
    chmod u-s usr/bin/chsh; \
    chmod u-s usr/bin/passwd; \
    chmod u-s bin/umount; \
    chmod u-s usr/bin/chfn; \
    chmod u-s bin/su; \
    chmod u-s usr/bin/gpasswd; \
    chmod u-s usr/bin/newgrp; \
    chmod g-s usr/bin/wall;\
    chmod g-s usr/bin/chage;\
    chmod g-s usr/bin/expiry;\
    chmod g-s sbin/unix_chkpwd; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid;
USER nginx
HEALTHCHECK --interval=5m --timeout=3s \
CMD curl -f http://localhost/ || exit 1
CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["/docker-entrypoint.sh"]