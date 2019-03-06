#include <iostream>

using namespace std;

#define count_string 8

class prototype_string{
private:
    char *strng;
    int length;
    bool padding[4];
public:
    prototype_string(){
        padding[0] = false;
    }
    bool set_Length(int new_length){
        length = new_length;
        return true;
    }
    bool set_Max_Size(int new_Size){
        strng = new char[new_Size];
        return true;
    }
    bool set_value(){
        char *kesh = new char[10];
        cin.getline(kesh, 10);
        int *i = new int;
        *i = 0;
        while(kesh[*i]){
           *i = *i + 1;
           if (*i > 10) break;
        }
        length = *i;
        *i = 0;
        strng = new char[length];
        while(kesh[*i]){
            strng[*i] = kesh[*i];
            *i = *i +1;
            if (*i>10) break;
        }
        delete [] kesh;
        delete i;
        return true;
    }
    int get_Length(){
        return length;
    }
    bool get_String(char *out){
        int i = 0;
        while(strng[i]){
            out[i]=strng[i];
            i++;
        }
        out[i] = '\0';
        return true;
    }
    int find(char substr){
        int i;
        for (i = 0; i < length; i++){
            if (strng[i] == substr) return i;
        }
        return -1;
    }
    bool replace(char *simbol, char *substr){
        int position = find(simbol[0]);
        if (-1 == position) return false;
        int i = 0;
        char *kesh = new char[20];
        for (i = 0; i<position;i++){
            kesh[i] = strng[i];
        }
        int j = 0;
        if ('0' != *substr){
            while (substr[j]) {
                kesh[i] = substr[j];
                i++;
                j++;
            }
        }
        position++;
        for (j = position; strng[j] != '\0';j++){
            kesh[i] = strng[j];
            i++;
        }
        kesh[i] = '\0';
        set_Length(i);
        delete[] strng;
        strng = new char[length];
        i = 0;
        while (kesh[i]) {
            strng[i] = kesh[i];
            i++;
        }
        delete[] kesh;
        //cout << "Полученная строка: " << strng << endl;
        return true;
    }
    bool set_Char(char *new_char){
        int i = 0;
        while (new_char[i]) {
            i++;
        }
        length = i;
        strng = new char[length];
        for (i = 0; i<length;i++){
            strng[i] = new_char[i];
        }
        i++;
        strng[i] = '\0';
        return true;
    }
};

int main() {
    prototype_string *main_string = new prototype_string;
    prototype_string *left_Path = new prototype_string[count_string];
    prototype_string *right_Path = new prototype_string[count_string];
    int *i = new int;
    cout << "Введите левый столбец" << endl;
    for (*i = 0;*i<count_string;*i=*i+1){
      left_Path[*i].set_value();
    }
    cout << "Введите правый столбец" << endl;
    for (*i = 0;*i<count_string;*i=*i+1){
      right_Path[*i].set_value();
    }
    int size_posl;
    cout << "Размер последоватльности: " << endl;
    cin >> size_posl;
    char *kesh = new char [1];
    if (0 == size_posl){
        char *new_char2 = new  char[right_Path[0].get_Length()];
        right_Path[0].get_String(new_char2);
        main_string->set_Char(new_char2);
        delete [] new_char2;
        for (*i = 1;*i<count_string;*i=*i+1){
          char *new_char2 = new  char[right_Path[*i].get_Length()];
          right_Path[*i].get_String(new_char2);
          left_Path[*i].get_String(kesh);
          main_string->replace(kesh, new_char2);
          delete [] new_char2;
        }
    }else{
        int pos;
        cout << "Начните вводить последовательность: " << endl;
        cin >> pos;
        pos--;
        char *new_char2 = new  char[right_Path[pos].get_Length()];
        right_Path[pos].get_String(new_char2);
        main_string->set_Char(new_char2);
        delete [] new_char2;
        for (int j = 1; j< size_posl; j++){
            cin >> pos;
            pos--;
            char *new_char2 = new  char[right_Path[pos].get_Length()];
            right_Path[pos].get_String(new_char2);
            left_Path[pos].get_String(kesh);
            main_string->replace(kesh, new_char2);
            delete [] new_char2;
        }
    }
    delete i;
    char *new_char3 = new char[main_string->get_Length()];
    main_string->get_String(new_char3);
    cout << "Конечная послеовательность: " << new_char3 << endl;
    delete [] new_char3;
    delete main_string;
    delete[] left_Path;
    delete[] right_Path;
    return 0;
