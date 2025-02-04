#include "List.h"
#include <string>
#include <iostream>


List::List(){
	head = nullptr;
}

List::List(const List& other){
	head = nullptr;
	Node* tracer = other.head;
	while(tracer != nullptr){
	insert(tracer->data);
	tracer = tracer->next;
	}

}

List::~List(){
	size_t cou = count();
	std::cout << "Count is "<< cou << "\n";
	Node* tracer;
	for(size_t i = 0; i < cou; i++){
	tracer = head;
	head = head->next;
		delete tracer;
		std::cout << "Deleted prev\n";
	}
}

void List::insert(const std::string& value){
	Node* hinitial = head;
	Node* prev = head;
	bool changed = 0;
	size_t pos = 0;

	//insert at beginning of list
	if(count() == 0|| value < head->data){
		Node* temp = new Node;
    		temp->data = value;
		temp->next = head;

		head = temp;
		return;
	}

	//insert at the middle of the list
	while(head != nullptr){
		if(value < head->data){
			Node* temp = new Node;
                	temp->data = value;
                	temp->next = head;
			
                	prev->next = temp;
			head = hinitial;
			changed = 1;
                	break;
		}
		prev = head;
		head = head->next;
		pos++;
	}
	
	//insert at the end of the list
	if(pos != 0 && !changed){
	Node* temp = new Node;
        temp->data = value;
        temp->next = head;

        prev->next = temp;
	}
	head = hinitial;

	
	std::cout << "Test Call";
	
}

size_t List::count() const{
	Node* tracer = head;
	size_t cou = 0;
	if(tracer == nullptr){
		return 0;	
	}
	tracer = tracer->next;
	cou++;
	while(tracer != nullptr){
		cou++;
		tracer = tracer->next;
	}
	return cou;
}

void List::print(bool reverse) const{
	size_t cou = count();
	std::string* list = new std::string[cou];
        Node* tracer = head;
	for(size_t i = 0; i < cou; i++){
		list[i] = tracer->data;
		tracer = tracer->next;
	}	
	std::cout << "[";
	if(reverse == 0){
		for(size_t i = 0; i < cou-1; i++){
		std::cout << list[i] << ", "; 
		}
		std::cout << list[cou-1] << "]\n";
	}
	 if(reverse == 1){
                for(size_t i = cou-1; i > 0; i--){
			std::cout << list[i] << ", ";
		}
			std::cout << list[0] << "]\n";
		
	 }
	 delete [] list;
}

const std::string& List::lookup(size_t index) const{
	size_t cou = count();
		if(index > cou-1 || cou == 0){
                throw (std::out_of_range("Index out of range."));
                }

	Node* tracer = head;
	for(size_t i = 0; i < index; i++){
	tracer = tracer->next;
	}
	return tracer->data;
}

std::string List::remove(size_t index){
	return "Stub";
	
}
size_t List::remove(const std::string& value){
	return 0;
	
}
