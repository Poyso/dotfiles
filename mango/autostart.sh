#!/bin/sh

wall=$(find ~/pic/wall/ -type f -name "*.jpg" -o -name "*.png" | shuf -n 1)
wal -c
wal -i $wall 
swaybg -i $wall -m fill&
change_border_colors_mango
wtype -M win r -m winnewlook

waybar&

