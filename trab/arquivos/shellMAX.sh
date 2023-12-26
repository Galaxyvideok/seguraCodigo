#!/bin/bash

comandos=$(<../arquivos/saida.bin)

case $comandos in
    ls|pwd|du|ps|df|uptime|date)
        $comandos >../arquivos/entrada.bin ;;
    *)
        echo "Comando não reconhecido." ;;
esac