#include <iostream>
#include "ListElement.h"

shared_ptr<ListElement> head;
shared_ptr<ListElement> tail;


void addToHead(shared_ptr<ListElement> element){
    if(head.get()){
        element->next = head;
        head->prev = element;
    }

    head = move(element);

    if(!tail.get()){
        tail = head;
    }

    cout<<"Nowy adres glowy: "<<head.get()<<endl;
}

void addToTail(shared_ptr<ListElement> element){
    if (tail.get()){
        tail->next = element;
        element->prev = tail;
    }

    tail = move(element);

    if(!head.get()){
        head = tail;
    }

    cout<<"Nowy adres ogona: "<<tail.get()<<endl;
}

void removeFromHead(){
    if(!head.get()) return;

    if(head.get() == tail.get()){
        head.reset();
        tail.reset();
        cout<<"Lista pusta"<<endl;
        return;
    }

    head = head->next;
    cout<<"Nowy adres glowy: "<<head.get()<<endl;
}

void removeFromTail(){
    if(!tail.get()) return;

    if(head.get() == tail.get()){
        head.reset();
        tail.reset();
        cout<<"Lista pusta"<<endl;
        return;
    }

    tail = shared_ptr<ListElement>(tail->prev);

    cout<<"Nowy adres ogona: "<<tail.get()<<endl;
}

int main() {
    addToHead(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    removeFromTail();
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    addToHead(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;
    addToHead(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;
    addToTail(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    removeFromTail();
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;
    removeFromTail();
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    addToHead(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;
    addToHead(make_shared<ListElement>());
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    removeFromHead();
    cout<<"Glowa: "<<head.get()<<" Ogon: "<<tail.get()<<endl;

    return 0;
}
