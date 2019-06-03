#include "List.h"
#include <unordered_map>
#include <cstdio>
#include <vector>

//prev next rand data

void List::InsertTail(std::string data) {
    auto a = new ListNode(tail, nullptr, nullptr, data);
    if (tail) {
        tail->next = a;
        tail = a;
        ++count;
    } else {
        tail = a;
        head = a;
        count = 1;
    }
}

void List::InsertHead(std::string &data) {
    auto a = new ListNode(nullptr, head, nullptr, data);
    if (head) {
        head->prev = a;
        head = a;
        ++count;
    } else {
        tail = a;
        head = a;
        count = 1;
    }
}

void List::InsertAfter(ListNode *pointer, std::string &data) {
    if (pointer == tail) {
        InsertTail(data);
        return;
    }
    auto a = new ListNode(pointer, pointer->next, nullptr, data);
    pointer->next->prev = a;
    pointer->next = a;
    ++count;
}

void List::Serialize(std::ostream &stream) {
    stream << count << std::endl;
    if (count == 0) {
        return;
    }
    int number = 0;
    std::unordered_map<ListNode *, int> map;
    for (auto node = head; node != nullptr; node = node->next) {
        map.emplace(node->next, number++);
    }
    for (auto node = head; node != nullptr; node = node->next) {
        stream << node->data << std::endl;
        //stream.write((char*)&node->rand, sizeof(node->rand));
    }
    for (auto node = head; node != nullptr; node = node->next) {

        number = node->rand ? map.find(node->rand->next)->second : -1;
        stream << number << std::endl;
    }
}

void List::Deserialize(std::istream &stream) {
    int length = -1;
    stream >> length;
    if (length <= 0) {
        return;
    }
    std::vector<ListNode *> refs;
    refs.reserve(static_cast<unsigned long>(length));
    std::string data;
    for (int index = 0; index < length; ++index) {
        stream >> data;
        //stream.getline(data,);
        InsertTail(data);
        refs.push_back(tail);
    }
    int index;
    for (auto node = head; node != nullptr; node = node->next) {
        stream >> index;
        if (index != -1) {
            node->rand = refs[index];
        }
    }
}

ListNode::ListNode(ListNode *prev, ListNode *next, ListNode *rand, const std::string &data) : prev(prev), next(next),
                                                                                              rand(rand), data(data) {}

ListNode::ListNode(ListNode *rand, const std::string &data) : rand(rand), data(data) {}

List::~List() {
    if(head) {
        for (auto node = head->next; node != nullptr; node = node->next) {
            delete node->prev;
        }
        delete tail;
    }
}