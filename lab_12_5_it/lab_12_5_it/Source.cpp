#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Elem {
    Elem* link;
    double x, y;

    Elem(double x_val = 0.0, double y_val = 0.0, Elem* link_val = nullptr) {
        x = x_val;
        y = y_val;
        link = link_val;
    }
};

void push(Elem*& top, double x, double y) {
    Elem* new_elem = new Elem(x, y, top);
    top = new_elem;
}

Elem pop(Elem*& top) {
    Elem* tmp = top->link;
    Elem elem_to_return = *top;
    delete top;
    top = tmp;
    return elem_to_return;
}

void print_stack(Elem* top) {
    cout << "Stack contents:" << endl;
    Elem* current = top;
    while (current != nullptr) {
        cout << "(" << current->x << ", " << current->y << ")" << endl;
        current = current->link;
    }
}

void center_of_mass(Elem* top, double& x_cm, double& y_cm) {
    double x_sum = 0.0, y_sum = 0.0, m_sum = 0.0;
    Elem* current = top;
    while (current != nullptr) {
        double m = 1.0;
        x_sum += m * current->x;
        y_sum += m * current->y;
        m_sum += m;
        current = current->link;
    }
    x_cm = x_sum / m_sum;
    y_cm = y_sum / m_sum;
}

int main() {
    Elem* top = nullptr;

    ofstream output_file("points.txt");
    output_file << "2.5 3.7" << endl;
    output_file << "1.0 2.0" << endl;
    output_file << "1.4 2.5" << endl;
    output_file << "6.0 3.0" << endl;
    output_file << "4.0 1.0" << endl;
    output_file.close();

    ifstream input_file("points.txt");
    double x, y;

   while (input_file >> x >> y) {
        push(top, x, y);
    }
    input_file.close();

    print_stack(top);

    double x_cm, y_cm;
    center_of_mass(top, x_cm, y_cm);
    cout << "Center of mass: (" << x_cm << ", " << y_cm << ")" << endl;

    while (top != nullptr) {
        pop(top);
    }

    return 0;
}
