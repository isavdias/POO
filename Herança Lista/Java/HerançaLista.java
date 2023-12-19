
class Lista<T> {
    private No<T> head;

    public void insere(T data) {
        No<T> novoNo = new No<>(data);
        novoNo.next = head;
        head = novoNo;
    }

    public int tamanho() {
        int count = 0;
        No<T> temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        return count;
    }

    public T primeiro() {
        if(head != null){
        return head;
        }
    }
}


class Fila<T> {
    private Lista<T> lista = new Lista<>();

    public void enfileirar(T data) {
        lista.insere(data);
    }

    public T desenfileirar() {
        if (lista.tamanho() == 0) {
            return null;
        }

        No<T> temp = lista.head;
        No<T> prev = null;

        while (temp.next != null) {
            prev = temp;
            temp = temp.next;
        }

    
        if (prev != null) {
            prev.next = null;
        } else {
            lista.head = null;
        }

        return temp.data;
    }

    public int tamanho() {
        return lista.tamanho();
    }

    public T primeiro() {
        return lista.primeiro();
    }
}


class Pilha<T> {
    private Lista<T> lista = new Lista<>();

    public void push(T data) {
        lista.insere(data);
    }

    public T pop() {
        if (lista.tamanho() == 0) {
            return null;
        }

        No<T> temp = lista.head;
        lista.head = temp.next;

        return temp.data;
    }

    public int tamanho() {
        return lista.tamanho();
    }

    public T topo() {
        return lista.primeiro();
    }
}
