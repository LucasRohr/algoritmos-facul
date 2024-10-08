#include "./person/person.h"
#include "./person/programmer/programmer.h"
#include "./person/student/student.h"

#include "./fruit/fruit.h"
#include "./fruit/banana/banana.h"
#include "./fruit/watermelon/watermelon.h"

int main() {
    // Inheritance tests

    Banana banana = Banana("banana massa", "prata");
    Watermelon watermelon = Watermelon("melancia do juca", 2.50, false);

    banana.set_price(9.90);
    watermelon.set_price(7.50);

    cout << "Banana with tax price: " << banana.calculate_price(0.1) << endl;
    cout << "Watermelon final price: " << watermelon.calculate_final_price() << endl;

    // Polymorphism tests

    Person* person;
    int option = -1;

    string name_input;
    int age_input;
    string fav_language_input;
    double grade_input;

    while (option != 0) {
        Programmer programmer = Programmer();
        Student student = Student();

        cout << "Digite uma opcao de pessoa (1 - Programador, 2 - Aluno, 0 - Sair):" << endl;
        cin >> option;

        if (option == 0) {
            return 0;
        }

        if (option == 1) {
            cout << "Digite o nome do programador: " << endl;
            cin >> name_input;
            programmer.set_name(name_input);

            cout << "Digite a idade do programador: " << endl;
            cin >> age_input;
            programmer.set_age(age_input);

            cout << "Digite a linguagem favorita do programador: " << endl;
            cin >> fav_language_input;
            programmer.set_fav_language(fav_language_input);

            person = &programmer;
        }

        if (option == 2) {
            cout << "Digite o nome do aluno: " << endl;
            cin >> name_input;
            student.set_name(name_input);

            cout << "Digite a idade do aluno: " << endl;
            cin >> age_input;
            student.set_age(age_input);
            
            cout << "Digite a nota do aluno: " << endl;
            cin >> grade_input;
            student.set_grade(grade_input);

            person = &student;
        }

        person->print_data();
    }

    return 0;
}
