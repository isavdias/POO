#include <iostream>


template <typename T>
class Lista {
private:
    No<T>* head;

public:
    Lista() : head(nullptr) {}

    void insere(T data) {
        No<T>* novoNo = new No<T>(data);
        novoNo->next = head;
        head = novoNo;
    }

    int tamanho() const {
        int count = 0;
        No<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    T primeiro() const {
        return head->data;
    }
};


template <typename T>
class Fila {
private:
    Lista<T> lista;

public:
    void enfileirar(T data) {
        lista.insere(data);
    }

    T desenfileirar() {
        if (lista.tamanho() == 0) {
            return T{};
        }

        No<T>* temp = lista.getHead();
        No<T>* prev = nullptr;

        
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        
        if (prev != nullptr) {
            prev->next = nullptr;
        } else {
            lista.setHead(nullptr);
        }

        T data = temp->data;
        delete temp;
        return data;
    }

    int tamanho() const {
        return lista.tamanho();
    }

    T primeiro() const {
        return lista.primeiro();
    }
};

template <typename T>
class Pilha {
private:
    Lista<T> lista;

public:
    void push(T data) {
        lista.insere(data);
    }

    T pop() {
        if (lista.tamanho() == 0) {
            return T{};
        }

        No<T>* temp = lista.getHead();
        lista.setHead(temp->next);

        T data = temp->data;
        delete temp;
        return data;
    }

    int tamanho() const {
        return lista.tamanho();
    }

    T topo() const {
        return lista.primeiro();
    }
};
