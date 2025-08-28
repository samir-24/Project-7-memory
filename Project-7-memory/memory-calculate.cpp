#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Student {
    T sid;
    string sname;

public:
    Student(T id, string name) {
        sid = id;
        sname = name;
    }

    void showData() {
        cout << sid << " " << sname << endl;
    }

    T getId() {
        return sid;
    }
};

int main() {
    vector<Student<int>> list;
    int option;

    while (1) {
        cout << endl;
        cout << "---- Student Management Menu ----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Show All Students" << endl;
        cout << "3. Delete Student by ID" << endl;
        cout << "4. Find Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int id;
                string name;
                cout << "Enter ID: ";
                cin >> id;

                bool exists = false;
                for (int i = 0; i < list.size(); i++) {
                    if (list[i].getId() == id) {
                        exists = true;
                        break;
                    }
                }

                if (exists) {
                    cout << "ID " << id << " already exists!" << endl;
                } else {
                    cout << "Enter Name: ";
                    cin >> name;
                    list.push_back(Student<int>(id, name));
                    cout << "Student added." << endl;
                }
                break;
            }

            case 2: {
                if (list.empty()) {
                    cout << "No students found." << endl;
                } else {
                    for (int i = 0; i < list.size(); i++) {
                        list[i].showData();
                    }
                }
                break;
            }

            case 3: {
                int id;
                bool found = false;
                cout << "Enter ID to delete: ";
                cin >> id;
                for (auto it = list.begin(); it != list.end(); it++) {
                    if (it->getId() == id) {
                        list.erase(it);
                        cout << "Student deleted." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "ID not found." << endl;
                }
                break;
            }

            case 4: {
                int id;
                bool found = false;
                cout << "Enter ID to find: ";
                cin >> id;
                for (int i = 0; i < list.size(); i++) {
                    if (list[i].getId() == id) {
                        list[i].showData();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "ID not found." << endl;
                }
                break;
            }

            case 5:
                cout << "Thank you." << endl;
                return 0;

            default:
                cout << "Wrong option." << endl;
        }
    }

    return 0;
}
