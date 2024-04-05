# Sprint 3 Edge Computing e Computer Systems 💻📊

## Integrantes do Grupo 🧑‍💼

- **Matheus Farias** (RM554254)
- **Miguel Parrado** (RM554007)
- **Pedro Henrique** (RM553988)
- **Vitor Pinheiro** (RM553693)

## Projeto de Feedback e Geração de Gráficos com ESP32 🏥📈

Este é um projeto de feedback e geração de gráficos desenvolvido como parte do trabalho da disciplina de Edge Computing e Computer Systems. O projeto utiliza um ESP32 para coletar feedback dos pacientes em um ambiente hospitalar e gera gráficos para análise dos dados.

## Problema ❗

Hospitais frequentemente enfrentam desafios em garantir uma experiência satisfatória para os pacientes e acompanhantes durante o atendimento médico. A falta de comunicação eficaz, a demora nos procedimentos e a ansiedade dos pacientes são algumas das questões a serem abordadas para melhorar a experiência hospitalar.

## Solução 🛠️

A solução proposta é um sistema de Feedback e Geração de Gráficos desenvolvido para coletar feedback dos pacientes e acompanhantes em um ambiente hospitalar, bem como gerar gráficos para análise dos dados. O projeto foi dividido em quatro fases para demonstrar um compromisso contínuo com a melhoria da experiência do usuário e a eficiência do atendimento no hospital:

1. **Fase 1: Feedback Simples (Início Descomplicado):** Implementação inicial com HTML e um formulário simples em JavaScript para coletar feedback básico dos pacientes e acompanhantes, abordando aspectos como atendimento, pré e pós-atendimento, com perguntas de resposta opcional e campo de observação.

2. **Fase 2: Armazenamento de Dados e Indicadores-chave (Explorando o SQLite):** Integração do SQLite para armazenar dados coletados, estabelecimento de indicadores-chave de desempenho (KPIs) para avaliação contínua e configuração de parâmetros para melhorar a interpretação dos resultados.

3. **Fase 3: Campanhas de Análise e Evolução das Perguntas (Afinando Detalhes):** Implementação de campanhas de análise alinhadas às demandas específicas do hospital, dinâmica de ajuste nas perguntas conforme a evolução temporal e necessidades identificadas, promovendo uma abordagem mais estratégica e contextualizada.

4. **Fase 4: Criação de Gráficos KPIs (Visualizando o Progresso):** Utilização dos dados acumulados para criar gráficos visualmente informativos, apresentação visual dos indicadores-chave de desempenho para proporcionar ao hospital uma compreensão clara e instantânea dos resultados.

Este sistema visa melhorar a experiência do usuário, fornecendo uma maneira eficaz de coletar feedback, analisar dados e identificar áreas de melhoria no atendimento hospitalar.

## Execução do Projeto 🚀

Para rodar o projeto e visualizar a Dashboard gerada, siga os passos abaixo:

### Passo 1: Acesso ao Wokwi 🌐

1. Acesse o [Wokwi](https://wokwi.com/) em seu navegador.

### Passo 2: Carregar o Projeto 🛠️

1. Clique em "Simulate Arduino" no canto superior direito.
2. Cole o código do projeto contido no arquivo `sketch.ino`.
3. Clique em "Start Simulation" para iniciar a simulação.

### Passo 3: Acesso ao Node-RED 🔄

1. Na barra de ferramentas superior, clique em "Embed Code" e selecione "Node-RED".
2. Clique em "Start Node-RED" para iniciar o serviço.

### Passo 4: Configuração do Fluxo no Node-RED ⚙️

1. No Node-RED, crie um novo fluxo.
2. Adicione um nó MQTT para receber os dados de feedback e temperatura.
3. Adicione nós de processamento e gráficos para processar e visualizar os dados recebidos.

### Passo 5: Configuração da Dashboard 📊

1. Crie uma Dashboard no Node-RED.
2. Adicione gráficos e widgets para exibir os dados processados.
3. Personalize a aparência da Dashboard conforme desejado.

### Passo 6: Visualização da Dashboard 👀

1. Abra a URL da Dashboard gerada pelo Node-RED em seu navegador.
2. Visualize os gráficos e widgets que exibem os dados de feedback e temperatura em tempo real.

Agora você pode interagir com a simulação no Wokwi e visualizar os dados processados na Dashboard criada no Node-RED.

## Simulação do Projeto 🎮

Você pode visualizar e simular o projeto no Wokwi usando o seguinte link:

[Simulação do Projeto no Wokwi](https://wokwi.com/projects/393636297720326145)

## Códigos-fonte 💻

O código-fonte do projeto está disponível no arquivo `sketch.ino` neste repositório.




