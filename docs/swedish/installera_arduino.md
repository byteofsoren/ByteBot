# Installera programmera på Windows och Mac datorer
Programvaran vi använder för att programmera robot med heter Arduino.
Gå till sidan [Arduino](https://www.arduino.cc/en/software).
Klicka på länken för den dator typ du har.

1. Windows
2. macOS
3. Linux

Då laddas en zip fil ned som innehåller programmet.
Packa upp filen och dubbel klicka på installera.

# Installation för linux

## ArchLunux
``` bash
$ sudo pacman -s arduino

```
## Fedora
``` bash
$ flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
$ flatpak install cc.arduino.arduinoide
```
## Ubuntu
``` bash
$ sudo apt update && sudo apt upgrade
$ sudo apt install arduino

```
