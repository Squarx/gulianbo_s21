FROM nginx

COPY nginx/nginx.conf /etc/nginx/
CMD ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["/docker-entrypoint.sh"] 