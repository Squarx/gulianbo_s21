#!/bin/bash
cd
cd T01D01-0/
cd src/
chmod +x ai_door_control
mv door_management_fi door_management_files
cd door_management_files
mkdir door_configuration
mkdir door_logs
mkdir door_map
mv *.conf door_configuration
mv *.log door_logs
mv door_map_1.1 door_map
