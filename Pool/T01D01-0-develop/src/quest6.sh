#!/bin/bash
cd
cd T01D01-0/
cd src/
cd ai_help/
sh keygen.sh
cd key/
rm file*
cd ..
sh unifier.sh
cp main.key key
