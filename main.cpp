#include <iostream>
#include <fstream>
#include "List.h"

int main() {
    List list;
    std::string a1 = "first";
    std::string a2 = "second";
    std::string a3 = "third";
    list.InsertTail(a1);
    list.InsertTail(a2);
    list.InsertTail(a3);


    std::ofstream fout("test.txt",std::ifstream::binary);
    list.head->rand = list.head;
    list.head->next->rand = list.head->next;
    list.head->next->next->rand = list.head;
    list.Serialize(fout);

    std::ifstream fin("test.txt",std::ifstream::binary);

    List list2;
    list2.Deserialize(fin);
    std::cout << list2.head->data << "\n";
    std::cout << list2.tail->data << "\n";
    std::cout << list2.tail->rand->data;

    List list3;
    std::ifstream fin2("test.txt",std::ifstream::binary);
    list3.Deserialize(fin2);
    std::cout << list3.head->data << "\n";
    std::cout << list3.tail->data << "\n";
    std::cout << list3.tail->rand->data;


    return 0;
}