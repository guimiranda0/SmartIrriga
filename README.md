# SmartIrriga

Sistema automatizado de irrigação para hortas urbanas utilizando ESP32, sensor de umidade do solo, módulo relé e comunicação MQTT via HiveMQ.

## Objetivo

O projeto tem como objetivo automatizar o processo de irrigação em hortas urbanas, promovendo o uso eficiente da água e contribuindo para práticas sustentáveis baseadas em Internet das Coisas (IoT).

## Funcionamento

O sistema realiza a leitura da umidade do solo por meio de um sensor conectado ao ESP32. Quando a umidade fica abaixo do valor definido, o Arduino aciona o módulo relé, responsável por ativar a bomba de água.

Além do funcionamento automático, o sistema utiliza o protocolo MQTT para envio de dados e controle remoto da irrigação utilizando o broker HiveMQ.

## Componentes Utilizados

- ESP32
- Sensor de Umidade do Solo
- Módulo Relé 5V
- Mini bomba d’água
- Protoboard
- Cabos jumper

## Protocolos e Comunicação

O projeto utiliza o protocolo MQTT para comunicação IoT.

Broker utilizado:
- broker.hivemq.com

Tópicos MQTT:
- horta/umidade
- horta/irrigacao

## Ferramentas Utilizadas

- Fritzing
- Wokwi
- Arduino IDE
- HiveMQ

## Estrutura do Projeto

- /codigo → código-fonte Arduino
- /imagens → diagramas e capturas de tela
- /documentacao → documentação complementar

## Autor

Guilherme Miranda
Universidade Presbiteriana Mackenzie
