# 📌 Sistema de Gerenciamento de Projetos (TP1)

## 📖 Descrição

Este projeto foi desenvolvido como trabalho final da disciplina de Técnicas de Programação 1.
O sistema implementa um ambiente completo de gerenciamento de projetos ágeis, incluindo:

* cadastro de usuários
* autenticação e controle de acesso
* gerenciamento de projetos
* planos de sprint
* histórias de usuário
* associações entre entidades
* regras de negócio completas

---

## 🧠 Arquitetura do Projeto

O sistema foi estruturado em camadas, seguindo boas práticas de organização:

```
dominio → validações
entidade → objetos do sistema
servico → regras de negócio
associacao → relacionamentos
container → armazenamento em memória
apresentacao → interface (menus)
```

---

## 📁 Estrutura de Pastas

```
TP1/
│
├── include/
│   ├── dominio/
│   ├── entidade/
│   ├── interface/
│   ├── associacao/
│   ├── servico/
│   └── apresentacao/
│
├── src/
│   ├── dominio/
│   ├── entidade/
│   ├── associacao/
│   ├── servico/
│   └── apresentacao/
│
├── sqlite/ (opcional - banco de dados)
├── main.cpp
```

---

## ⚙️ Funcionalidades

### 👤 Usuários

* Criar, ler, atualizar e excluir
* Papéis:

  * Desenvolvedor
  * Mestre Scrum
  * Proprietário de Produto

### 🔐 Autenticação

* Login e logout
* Controle de acesso por papel

### 📂 Projetos

* Criados por Product Owner
* Associados a um Mestre Scrum

### 📅 Planos de Sprint

* Criados por Mestre Scrum
* Restrição de capacidade baseada na duração do projeto

### 🧾 Histórias de Usuário

* Criadas por Product Owner
* Estado inicial: `A FAZER`
* Movimentação entre sprints

### 🔗 Associações

* Pessoa ↔ Projeto
* História ↔ Projeto
* História ↔ Pessoa
* História ↔ Sprint

---

## 📏 Regras de Negócio

O sistema implementa validações importantes, como:

* senha com padrão específico
* papéis válidos
* limite de capacidade de sprint
* não permitir exclusão com dependências
* controle de acesso por tipo de usuário

---

## 🚀 Como executar o projeto

### 🔹 Pré-requisitos

* Code::Blocks
* Compilador C++
* (Opcional) SQLite

---

### 🔹 Passo a passo

1. Clone o repositório:

```bash
git clone [https://github.com/Eduardo734-ai/Trabalho_de_T-cnicas_de_Programa-o_1.git]
```

2. Abra o projeto no Code::Blocks

3. Compile o projeto

4. Execute o programa

---

### 🔹 Execução

O sistema roda via terminal com menus interativos:

```
===== MENU INICIAL =====
1 - Cadastrar usuário
2 - Login
0 - Sair
```

---

## 🗄️ Banco de Dados (SQLite - opcional)

O projeto pode ser adaptado para uso com SQLite.

### Para configurar:

1. Baixar SQLite:
   https://www.sqlite.org/download.html

2. Adicionar arquivos:

```
sqlite3.c
sqlite3.h
sqlite3.dll
```

3. Incluir no projeto no Code::Blocks

---

## 🧪 Testes

O sistema pode ser testado com o seguinte fluxo:

1. Criar usuário (Product Owner)
2. Criar usuário (Mestre Scrum)
3. Login como Product Owner
4. Criar projeto
5. Login como Scrum Master
6. Criar sprint
7. Criar história
8. Associar dados
9. Mover história para sprint
10. Alterar estado
11. Listar dados

---

## 📌 Observações

* O sistema foi inicialmente implementado com armazenamento em memória
* Estrutura preparada para futura integração com banco de dados
* Código organizado para facilitar manutenção e expansão

---

## 👨‍💻 Autor

Carlos Eduardo
Universidade de Brasília (UnB)
