#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printStack(stack<int> s) {
    if (s.empty())
        return;

    int x = s.top();
    s.pop();

    printStack(s);

    cout << x << " ";

    s.push(x);
}


void printStack(stack<double> s) {
    if (s.empty())
        return;

    double x = s.top();
    s.pop();

    printStack(s);

    cout << x << " ";

    s.push(x);
}


int main() {
    setlocale(LC_ALL, "Russian");
    stack<int> стек;
    stack<double> стек2;
    int минимальное_значение = -50;
    int количество_элементов = 0;

    cout << "Как вы хотите получить стек? Рандомайзер(Для выбора введите 1)/Заполнение(Для выбора введите 2)";
    int a;
    cin >> a;

    if (a == 1) {

        srand(time(0));

        for (int i = 0; i < 101; i++) {
            int randomNumber = rand() % 101 - 50;
            стек2.push(randomNumber);
        }
        cout << "Стек: ";
        printStack(стек2);
        cout << endl;

        while (!стек2.empty()) {
            if (стек2.top() == минимальное_значение) {
                break;
            }
            стек2.pop();
            количество_элементов++;
        }
        cout << "Количество элементов от вершины до минимального значения: " << количество_элементов << endl;
    }

    if (a == 2) {
        for (int i = -50; i <= 50; i++) {
            стек.push(i);
        }
        cout << "Стек: ";
        printStack(стек);
        cout << endl;

        while (!стек.empty()) {
            if (стек.top() == минимальное_значение) {
                break;
            }
            стек.pop();
            количество_элементов++;
        }
        cout << "Количество элементов от вершины до минимального значения: " << количество_элементов << endl;
    }
}
