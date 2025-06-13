
# Tarefa: Roteiro de FreeRTOS #1 - EmbarcaTech 2025

Autor: **Marina Donaire**

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Campinas, 13 de junho de 2025

---

Projeto: Sistema Multitarefa com FreeRTOS no Raspberry Pi Pico
**Descrição**
Este projeto tem como objetivo demonstrar o uso do sistema operacional de tempo real FreeRTOS em um ambiente embarcado, utilizando a placa Raspberry Pi Pico (ou Pico W) com o kit BitDogLab. O sistema multitarefa foi desenvolvido em linguagem C, com foco no controle simultâneo de periféricos (LED RGB, buzzer e botões físicos) usando tarefas concorrentes.

A aplicação simula um pequeno sistema embarcado com três funcionalidades principais:

Um LED RGB que alterna ciclicamente entre vermelho, verde e azul.

Um buzzer que emite bipes em intervalos regulares.

Dois botões físicos:

Botão A: pausa e retoma a tarefa do LED.

Botão B: pausa e retoma a tarefa do buzzer.

As tarefas são executadas de forma independente e paralela, controladas pelo escalonador do FreeRTOS.

**Objetivos de Aprendizagem**
Compreender o funcionamento básico de um RTOS (Real-Time Operating System).

Criar e gerenciar tarefas com FreeRTOS usando vTaskCreate(), vTaskDelay(), vTaskSuspend() e vTaskResume().

Utilizar polling para leitura de botões com controle de tarefas.

Integrar periféricos de hardware com GPIO no Raspberry Pi Pico.

Organizar e compilar projetos com CMake e o Pico SDK no VSCode.

**Tecnologias e Ferramentas**
Linguagem: C

Placa: Raspberry Pi Pico / Pico W

SDK: pico-sdk

RTOS: FreeRTOS (kernel)

Toolchain: ARM GCC (arm-none-eabi)

IDE: Visual Studio Code

Sistema de build: CMake


---

## 📜 Licença
GNU GPL-3.0.
