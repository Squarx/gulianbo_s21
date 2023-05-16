#!/bin/bash


sudo /bin/systemctl enable grafana-server
sudo /bin/systemctl start grafana-server
sudo systemctl restart prometheus
sudo systemctl restart node_exporter
systemctl status nginx 
systemctl status grafana-server 
systemctl status prometheus 
systemctl status node_exporter 