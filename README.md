# 🔒 Bloqueador de Sinal Bluetooth e Wi-Fi com ESP32 + NRF24L01+

Este projeto utiliza um ESP32 e dois módulos NRF24L01+ para interferir seletivamente em canais Bluetooth, Bluetooth BLE e Wi-Fi, explorando a sobreposição de frequências de 2.4GHz.

> ⚠️ Este projeto é apenas para fins **educacionais** e **experimentais**. O uso inadequado pode violar leis locais de telecomunicação.

---

## 📸 Demonstração
Iremos utilizar uma placa padrão de ESP32 + NRF24L01+
![image](https://github.com/user-attachments/assets/aac3ba4d-ca61-428d-b074-e78014b7ac05)

---

## 🧰 Requisitos de Hardware

- ✅ 1x ESP32 DevKit
- ✅ 2x Módulos **NRF24L01+**
- ✅ 1x Placa padrão para dois modulos **NRF24L01+**
- ✅ Antenas (recomendado: 3 dBi ou superior)
- ✅ Botão (opcional, para mudar de modo, iremos usar o butão "0" do esp para facilitar)
- ✅ Cabo USB para programar e/ou uma fonte

---

## 📦 Bibliotecas utilizadas

- [`RF24`](https://github.com/nRF24/RF24) – controle dos módulos NRF24L01
- [`ezButton`](https://github.com/ArduinoGetStarted/ezButton) – gerenciamento de botão
- `SPI` (padrão da ESP32)
- esp_bt e esp_wifi (padrão da ESP32)

---

## 📁 Estrutura do Código

| Pasta / Arquivo | Descrição |
|------------------|-----------|
| `src/`           | Códigos principais |
| `radioRF24.*`    | Classe que encapsula configuração e controle do NRF24 |
| `modeRF24.*`     | Classe de modos de operação (Bluetooth, BLE, Wi-Fi, todos) |
| `MyJammer.ino`   | Código principal Arduino (setup/loop) |
| `README.md`      | Este arquivo |

---

## ⚙️ Modo de Operação

O botão conectado (ou como default, botão "0" / BOOT) ao ESP32 alterna entre os modos:

| Modo | Descrição |
|------|-----------|
| `MODE_BLUETOOTH`       | Canais clássicos de Bluetooth |
| `MODE_BLUETOOTH_BLE`   | Canais de advertising do BLE (2, 26, 80) |
| `MODE_WIFI`            | Faixa total de Wi-Fi 2.4GHz |
| `MODE_WIFI_COMMOM`     | Apenas canais Wi-Fi mais comuns |
| `MODE_ALL_CHANNELS`    | Varredura total de 0 a 80 |
| `MODE_DISABLE`         | Desativa a interferencia |

---

## 🧪 Como funciona

- O ESP32 configura os dois módulos NRF24L01+ para **enviar sinal contínuo (`startConstCarrier`)** em canais específicos.
- Um canal é selecionado de forma sequencial ou aleatória.
- A emissão contínua interfere nas comunicações Bluetooth/Wi-Fi naquele canal.

---

## 🚀 Upload e Execução

1. Instale as bibliotecas mencionadas.
2. Conecte os módulos conforme o mapeamento de pinos.
3. Compile e envie o código para o ESP32.
4. Monitore pelo `Serial Monitor` (115200 baud).
5. Pressione o botão para mudar o modo de bloqueio.

---

## 🔒 Aviso Legal

Este projeto é **exclusivamente educacional**. Emitir sinais intencionais de interferência em frequências licenciadas **pode ser ilegal** em sua região. Verifique as leis locais antes de qualquer uso prático.

---

## 📃 Licença

MIT License – sinta-se livre para estudar, modificar e compartilhar. Apenas use com responsabilidade.

---

## ✉️ Contato

Desenvolvido por **Socramsss**  
📧 [socramsss@ucl.com]  
💬 Contribuições e sugestões são bem-vindas!
# 🔒 Bloqueador de Sinal Bluetooth e Wi-Fi com ESP32 + NRF24L01+

Este projeto utiliza um ESP32 e dois módulos NRF24L01+ para interferir seletivamente em canais Bluetooth, Bluetooth BLE e Wi-Fi, explorando a sobreposição de frequências de 2.4GHz.

> ⚠️ Este projeto é apenas para fins **educacionais** e **experimentais**. O uso inadequado pode violar leis locais de telecomunicação.

---

## 📸 Demonstração
*(Adicione aqui uma foto ou GIF do projeto em funcionamento, se tiver)*
