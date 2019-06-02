//
// Created by Елена on 2019-06-02.
//

#ifndef SABER_LIST_H
#define SABER_LIST_H


#include <cstdio>
#include <string>
#include <iostream>

struct ListNode {
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *rand = nullptr; // указатель на произвольный элемент данного списка либо NULL
    std::string data;

    ListNode(ListNode *rand, const std::string &data);

    ListNode(ListNode *prev, ListNode *next, ListNode *rand, const std::string &data);
};


class List {
public:
    void Serialize(std::ostream &stream);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize(std::istream &stream);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
    void InsertTail(std::string data);

    void InsertAfter(ListNode *pointer, std::string &data);

    void InsertHead(std::string &data);

    virtual ~List();


    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int count = 0;

private:


};


#endif //SABER_LIST_H
