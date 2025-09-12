#!/bin/bash
# CTF Environment Setup Script for Ubuntu
# Installs common tools + sets up CTF domains for reverse proxy

set -euo pipefail
trap 'echo "[!] Error on line $LINENO. Exiting."; exit 1' ERR

# Change this to the IP address of your Nginx reverse proxy
REVERSE_PROXY_IP="10.0.9.132"

# Define your CTF domains (all mapped to REVERSE_PROXY_IP)
HOST_ENTRIES=(
    "$REVERSE_PROXY_IP   dashboard.ctf.prayag"
    "$REVERSE_PROXY_IP   welcome.ctf.prayag"
    "$REVERSE_PROXY_IP   webexploit.ctf.prayag"
    "$REVERSE_PROXY_IP   netscan.ctf.prayag"
)

echo "[*] Updating package list..."
sudo apt update -y

echo "[*] Installing essentials..."
sudo apt install -y firefox vim curl wget jq git make cmake unzip

echo "[*] Installing VSCode..."
if ! command -v code &>/dev/null; then
    wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
    sudo install -o root -g root -m 644 microsoft.gpg /etc/apt/trusted.gpg.d/
    echo "deb [arch=amd64] https://packages.microsoft.com/repos/code stable main" | \
        sudo tee /etc/apt/sources.list.d/vscode.list
    sudo apt update -y
    sudo apt install -y code
    rm microsoft.gpg
fi

echo "[*] Installing compilers/interpreters..."
sudo apt install -y gcc g++ python3 python3-pip openjdk-21-jdk golang rustc perl ruby

echo "[*] Installing Ghidra (Decompiler)..."
if [ ! -d "/opt/ghidra" ]; then
    GHIDRA_VERSION="11.0.3"
    GHIDRA_DATE="20240515"
    wget "https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${GHIDRA_VERSION}_build/ghidra_${GHIDRA_VERSION}_PUBLIC_${GHIDRA_DATE}.zip" -O /tmp/ghidra.zip
    sudo unzip /tmp/ghidra.zip -d /opt/
    sudo mv /opt/ghidra_* /opt/ghidra
    sudo ln -sf /opt/ghidra/ghidraRun /usr/local/bin/ghidra
    rm /tmp/ghidra.zip
fi

echo "[*] Installing binary exploitation tools..."
sudo apt install -y gdb radare2
pip3 install --upgrade pwntools ropper ROPgadget

echo "[*] Installing reverse engineering tools..."
sudo apt install -y apktool
wget -q https://github.com/java-decompiler/jd-gui/releases/download/v1.6.6/jd-gui-1.6.6.jar -O /opt/jd-gui.jar
echo 'alias jdgui="java -jar /opt/jd-gui.jar"' >> ~/.bashrc

echo "[*] Installing cryptography tools..."
sudo apt install -y john hashcat sagemath
pip3 install pycryptodome

echo "[*] Installing forensics/stego tools..."
sudo apt install -y steghide foremost ffmpeg exiftool binwalk
gem install zsteg || true  # zsteg needs Ruby

echo "[*] Installing web exploitation tools..."
sudo apt install -y sqlmap gobuster nmap nikto
# Burp Suite (Community)
if [ ! -f "/opt/burpsuite_community.jar" ]; then
    wget -q https://portswigger.net/burp/releases/download?product=community&version=2024.5.2&type=Jar -O /opt/burpsuite_community.jar
    echo 'alias burpsuite="java -jar /opt/burpsuite_community.jar"' >> ~/.bashrc
fi

echo "[*] Installing networking tools..."
sudo apt install -y wireshark tshark tcpdump net-tools socat openvpn

echo "[*] Installing OSINT/misc tools..."
sudo apt install -y whois dnsutils
pip3 install theHarvester

echo "[*] Adding CTF server entries to /etc/hosts..."
for entry in "${HOST_ENTRIES[@]}"; do
    if ! grep -q "$entry" /etc/hosts; then
        echo "$entry" | sudo tee -a /etc/hosts >/dev/null
        echo "    [+] Added: $entry"
    else
        echo "    [-] Already present: $entry"
    fi
done

echo
echo "[*] All CTF tools installed and hosts updated successfully!"
echo "[*] Restart your terminal or run 'source ~/.bashrc' to enable jdgui and burpsuite aliases."
