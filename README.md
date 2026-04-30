# 🚀 Sistema de Gerenciamento de Projetos  
### C++ | SQLite | Arquitetura em Camadas

---

## 📌 Visão Geral

Este projeto implementa um sistema completo de gerenciamento de projetos utilizando **C++** com persistência em **SQLite**.

O sistema foi projetado seguindo princípios de **separação de responsabilidades**, evoluindo de uma solução inicial em memória para uma arquitetura com **persistência total de dados**, incluindo entidades e associações.

---

## 🎯 Objetivo

Desenvolver um sistema robusto capaz de:

- Gerenciar usuários e autenticação  
- Controlar projetos e suas sprints  
- Gerenciar histórias de usuário  
- Manter relacionamentos entre entidades  
- Garantir persistência completa dos dados  

---

## 🧱 Arquitetura

O sistema segue uma arquitetura em camadas bem definida:

```
include/
├── dominio/        → Validação e regras básicas
├── entidade/       → Modelos do sistema
├── servico/        → Lógica de negócio
├── banco/          → Persistência (SQLite)
├── associacao/     → Relacionamentos
└── apresentacao/   → Interface (menu)

src/
├── dominio/
├── entidade/
├── servico/
├── banco/
├── associacao/
└── apresentacao/
```

---

## ⚙️ Tecnologias Utilizadas

- C++
- SQLite3
- GCC (Code::Blocks)

---

## 💾 Persistência de Dados

O sistema utiliza SQLite para garantir persistência completa.

### Entidades:
- Pessoa  
- Projeto  
- Plano de Sprint  
- História de Usuário  

### Associações:
- Projeto ↔ Pessoa  
- Projeto ↔ História  
- Projeto ↔ Plano  
- História ↔ Pessoa  
- História ↔ Plano  

✔ Os dados permanecem salvos mesmo após fechar o sistema.

---

## 🚀 Funcionalidades

- Cadastro e autenticação de usuários  
- Controle de permissões (papéis)  
- Criação e gerenciamento de projetos  
- Associação de usuários a projetos  
- Criação de planos de sprint  
- Validação de capacidade de sprint  
- Criação de histórias de usuário  
- Associação de histórias a projetos, usuários e sprints  
- Atualização e exclusão com validação  
- Persistência completa em banco  

---

## 🧠 Regras de Negócio

- Projeto deve ter um **Mestre Scrum**  
- Capacidade total das sprints ≤ duração do projeto  
- Soma das histórias ≤ capacidade da sprint  
- Não é possível excluir entidades associadas  

---

## ▶️ Como Executar

### 1. Clonar o repositório

```bash
git clone [https://github.com/Eduardo734-ai/Trabalho_de_T-cnicas_de_Programa-o_1.git]
```

### 2. Abrir no Code::Blocks

- Abra o arquivo `.cbp`  
- Configure o compilador (GCC)  

### 3. Compilar

```
Build → Build
```

### 4. Executar

```
Build → Run
```

---

## 📌 Observações

- O banco é criado automaticamente  
- Para resetar, exclua o arquivo `.db`  
- Entradas são validadas pelas classes de domínio  

---

## 📈 Evolução do Projeto

1. Implementação em memória  
2. Criação das entidades  
3. Aplicação de regras de negócio  
4. Migração para SQLite  
5. Persistência das associações  
6. Testes completos  

---

## 🧪 Testes

- Fluxo completo validado (usuário → projeto → sprint → história)  
- Associação entre entidades  
- Persistência confirmada após reiniciar o sistema  

---

## 👨‍💻 Autor

Carlos Eduardo de Oliveira Cardoso
Engenharia de Computação — UnB  

---

## 📬 Contato

GitHub: https://github.com/Eduardo734-ai
