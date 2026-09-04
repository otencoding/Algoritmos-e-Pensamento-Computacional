# 🎓 Algoritmos e Pensamento Computacional

Repositório criado com a intenção de subir e organizar os trabalhos acadêmicos da matéria de Algoritmos da professora Karla.

## 🛠️ Tecnologias e Ferramentas Principais
* **Linguagem Principal:** C
* **IDE:** VS Code
* **Modelagem:** Flowgorithm v4.2

## 📁 Organização Estrutural do Repositório
* **`CalculadoraFlow/`**: Primeiro projeto de calculadora multifuncional desenvolvida visualmente através de fluxogramas.
* **`CalculadoraC/`**: Segundo projeto de calculadora desenvolvido em linguagem C.

---

## 📖 Guia de Estudos: Comandos Git Utilizados

Abaixo está o resumo prático e a explicação de todos os comandos que utilizamos para estruturar e salvar este repositório do absoluto zero através do terminal:

### 1. Inicialização e Sincronização
* `git init`: Inicializa um repositório Git vazio localmente na pasta do computador.
* `git remote add origin <link>`: Cria uma ponte de conexão vinculando a sua pasta local ao seu repositório remoto lá no GitHub.
* `git pull origin main`: Puxa todos os arquivos que existiam no GitHub e sincroniza/mescla diretamente com a sua pasta local.

### 2. Manipulação de Arquivos e Pastas
* `mkdir <nome>`: Comando do sistema para criar novas pastas físicas.
* `git mv <arquivo> <pasta/>`: Move arquivos salvando o histórico. Informa ao Git que o arquivo mudou de endereço (evitando que ele ache que o arquivo foi deletado).
* `rm -rf <caminho>`: Deleta arquivos ou pastas permanentemente (utilizamos para apagar arquivos indesejados e limpar pastas ocultas `.git` duplicadas).
* `ls <nome_da_pasta>`: Lista todos os arquivos presentes dentro de um diretório para conferência rápida.

### 3. Limpeza de Erros de Submódulos (Cache)
* `git rm --cached -r <nome>`: Remove arquivos ou pastas do índice/cache de rastreamento do Git sem deletar o arquivo físico do computador. Foi crucial para corrigir o bug de pasta travada.

### 4. Fluxo de Salvamento e Envio (O ciclo principal do desenvolvedor)
* `git add .` ou `git add <pasta/>`: Adiciona os arquivos modificados ou novos à "área de preparação" (Staging Area), avisando ao Git o que deve ser empacotado.
* `git commit -m "Mensagem"`: Cria um ponto na história (uma foto do estado atual do código), salvando as alterações permanentemente no histórico local com uma mensagem descritiva.
* `git push origin main`: Pega todos os commits salvos no computador e envia/sobe de fato para o servidor do GitHub na ramificação principal (`main`).

