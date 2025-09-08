#!/bin/bash
# Script to install common CTF/Reverse Engineering tools on Ubuntu

set -e

echo "[*] Updating package list..."
sudo apt update -y

echo "[*] Installing web browser (Firefox)..."
sudo apt install -y firefox

echo "[*] Installing text editors (vim, VSCode, Notepad++)..."
sudo apt install -y vim
# Install VSCode
if ! command -v code &>/dev/null; then
    echo "[*] Installing VSCode..."
    wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
    sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
    sudo sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
    sudo apt update -y
    sudo apt install -y code
    rm microsoft.gpg
fi
# Notepad++ (via snap, since no native Linux version)
sudo snap install notepad-plus-plus

echo "[*] Installing netcat..."
sudo apt install -y netcat-openbsd

echo "[*] Installing binwalk..."
sudo apt install -y binwalk

echo "[*] Installing exiftool..."
sudo apt install -y exiftool

echo "[*] Installing compilers/interpreters..."
sudo apt install -y gcc g++ python3 python3-pip openjdk-17-jdk

echo "[*] Installing Ghidra (Decompiler like Ghindra)..."
if [ ! -d "/opt/ghidra" ]; then
    wget https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_11.0.3_build/ghidra_11.0.3_PUBLIC_20240515.zip -O /tmp/ghidra.zip
    sudo unzip /tmp/ghidra.zip -d /opt/
    sudo mv /opt/ghidra_* /opt/ghidra
    sudo ln -sf /opt/ghidra/ghidraRun /usr/local/bin/ghidra
    rm /tmp/ghidra.zip
fi

echo "[*] All tools installed successfully!"

