# ⚡ E-Moto Data Logger: Current Profiler

> **Sistema de monitoramento e perfilagem de corrente para veículos elétricos de alta tensão.**

Este projeto visa desenvolver uma ferramenta de baixo custo e alta precisão para registrar o consumo real (Amperes) de uma motocicleta elétrica em movimento. O objetivo é gerar gráficos de **Perfil de Direção** para análise de eficiência, saúde da bateria e dimensionamento de componentes.

---

## 📅 Roadmap do Projeto

O desenvolvimento está dividido em duas fases tecnológicas. Atualmente, o projeto encontra-se na **Fase 1**.

### ✅ Fase 1: Data Logger Offline (Status: Ativo)
Foco na validação do circuito analógico e gravação robusta de dados locais.
- [x] Leitura de Shunt com Amplificador Operacional (LM358/OPA333).
- [x] Processamento via **Arduino Uno/Nano** (5V).
- [x] Gravação de dados em **Cartão SD** (.CSV).
- [x] Indicador visual de status (LED Heartbeat).

### 🚧 Fase 2: Telemetria IoT (Próximos Passos)
Evolução para conectividade e monitoramento remoto.
- [ ] Migração para **ESP32** (Lógica 3.3V).
- [ ] Implementação de protocolo **MQTT** via WiFi/Hotspot.
- [ ] Criação de *Buffer* de dados para áreas sem sinal.
- [ ] Dashboard em Tempo Real (Grafana/Smartphone).

---

## 🧠 Como Funciona (Teoria de Operação)

O sistema baseia-se na leitura indireta de corrente através da Lei de Ohm ($V=R \times I$). O fluxo de dados ocorre em 4 estágios:

1.  **Sensoriamento (Shunt):** A corrente do motor passa por um resistor de precisão ($0.75m\Omega$). A passagem de corrente gera uma queda de tensão minúscula (mV) nos terminais.
2.  **Amplificação Diferencial:** Um Amplificador Operacional (Op-Amp) lê a *diferença* de tensão no Shunt e a amplifica (Ganho ~33x a 100x), elevando o sinal para níveis de Volts (0V-5V).
3.  **Filtragem (Hardware):** Filtros RC na entrada e na saída do Op-Amp eliminam o ruído de alta frequência gerado pelo chaveamento (PWM) do controlador do motor.
4.  **Digitalização:** O Arduino converte o sinal analógico em digital, calcula a corrente real e salva o registro com data/hora no Cartão SD.

### Diagrama

<img width="1175" height="684" alt="image" src="https://github.com/user-attachments/assets/39850a6d-4de9-4672-b61e-28cbf2b161c6" />
