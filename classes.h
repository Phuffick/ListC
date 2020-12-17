#pragma once
#include <iostream>


class Node{
	friend class List;

private:
	int data;
	int key;
	Node* last;
	Node* next;

public:
	Node(int data, Node* last, Node* next) {
		this->data = data;
		this->last = last;
		this->next = next;
	};

	Node(int data) {
		this->data = data;
	};
};


class List{
private:
	Node* begin;
	Node* end;

public:
	List() : begin(NULL), end(NULL) {};
	
	void AddToEnd(int data) {
		Node* New = new Node(data, end, NULL);
		end = New;

		if (begin) {
			Node* curr = begin;
			
			while (curr->next) {
				curr = curr->next;
			};
			curr->next = New;
		}
		else{
			begin = New;
		}

		Counter();
	};

	void AddToBegin(int data) {
		Node* New = new Node(data, NULL, begin);
		begin = New;

		if (end) {
			Node* curr = end;

			while (curr->last) {
				curr = curr->last;
			}

			curr->last = New;
		}
		else {
			end = New;
		}

		Counter();
	};

	void DeleteNodeEnd() {
		if (end) {
			Node* curr = end->last;
			delete curr->next;
			curr->next = NULL;
			end = curr;
		}
		else{
			std::cout << "The list is empty. " << '\n';
		}

		Counter();
	};

	void DeleteNodeBeg() {
		if (begin) {
			Node* curr = begin->next;
			delete curr->last;
			begin = curr;
		}
		else{
			std::cout << "The list is empty. " << '\n';
		}

		Counter();
	
	};

	int Remove(int d, int key) {
		Node* New = new Node(d);
		Node* curr = begin;

		while (curr) {
			if (curr->key == key){
				break
			}
			curr = curr->next;
		}

		if (!curr) {
			std::cout << "The is not key " << key << '\n';
			return -1;
		}

		(curr->last)->next = New;
		(curr->next)->last = New;
		New->last = (curr->last);
		New->next = (curr->next);
		New->key = key;
	};

	int Insert(int d, int key) {
		Node* New = new Node(d);
		Node* curr = begin;

		while (curr) {
			if (curr->key == key){
				break;
			}

			curr = curr->next;
		}

		if (!curr) {
			std::cout << "The is not key " << key << '\n';
			
			return -1;
		}

		(curr->last)->next = New;
		curr->last = New;
		New->last = (curr->last);
		New->next = curr;

		Counter();
	};

	void Find(int key) {
		Node* curr = begin;
	
		while (curr) {
			if (curr->key == key){
				std::cout << key << " --- " << curr->data << '\n';
			}

			curr = curr->next;
		}

		std::cout << '\n';
	};

	void ForwardPrint() {
		Node* curr = begin;
	
		while (curr){
			std::cout << curr->key << " - " << curr->data << '\n';
			curr = curr->next;
		}

		std::cout << "\n\n";
	
	};

	void BackPrint() {
		Node* curr = end;

		while (curr) {
			std::cout << curr->key << " - "<< curr->data << '\n';
			curr = curr->last;
		}
		
		std::cout << "\n\n";
	};

	void Counter() {
		Node* curr = begin;
		int i = 0;

		while (curr) {
			curr->key = ++i;
			curr = curr->next;
		}
	};

};
