/*
Невірна назва об'єкта списку, Порядок операцій у виразі виводу cout, 
Оператор << має нижчий пріоритет, ніж тернарний оператор ?:
виправлений код
List<Cat> Cat_List;
Cat Felix;
Cat_List.append(Felix);
cout << "Felix is "
     << (Cat_List.is_present(Felix) ? "" : "not ")
     << "present\n";
*/