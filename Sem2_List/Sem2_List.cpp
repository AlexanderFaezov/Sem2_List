#include<iostream>
using namespace std;

struct Node {
    char key;
    Node* next;
};

struct List {
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
};

void pushBack(List& list, char key) {
    Node* new_node = new Node;
    new_node->key = key;
    new_node->next = nullptr;
    if (list.head_node == nullptr) {
        list.head_node = new_node;
        list.tail_node = new_node; // Устанавливаем хвост равным новому узлу для списка с одним элементом
    }
    else {
        list.tail_node->next = new_node;
        list.tail_node = new_node; // Обновляем хвост списка
    }
}

void InsertItems(List& list, char k, char b) {
    Node* current = list.head_node;
    while (current != nullptr) {
        if (current->key == k) {
            Node* new_node = new Node;
            new_node->key = b;
            new_node->next = current->next;
            current->next = new_node;
            return; // Выходим из функции, когда вставили элемент после первого вхождения k
        }
        current = current->next;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    List list;
    cout << "Введите размер списка:" << endl;
    int n;
    cin >> n;
    cout << endl << "Введите элементы списка:" << endl;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        pushBack(list, k);
    }

    Node* current_node = list.head_node;
    cout << "Список: ";
    while (current_node != nullptr) {
        cout << current_node->key << ' ';
        current_node = current_node->next;
    }
    cout << endl;

    cout << "Введите символ, после которого нужно добавить новый символ: ";
    char after_key;
    cin >> after_key;

    cout << "Введите символ, который нужно добавить: ";
    char new_symbol;
    cin >> new_symbol;

    InsertItems(list, after_key, new_symbol);

    current_node = list.head_node;
    cout << "Итоговый список: ";
    while (current_node != nullptr) {
        cout << current_node->key << ' ';
        current_node = current_node->next;
    }

    return 0;
}
