#pragma once
#include <iostream>

template <typename T>
class Vector {
private:
   T* data;
   size_t size;
   size_t capacity;

   void copy(const Vector<T>& other);
   void erase();
   void resize();

public:
   Vector();
   Vector(const Vector<T>& other);
   Vector& operator=(const Vector<T>& other);
   ~Vector();

   void push_back(T& element);
   void pop_back();
   void push_front(T& element);

   bool is_empty() const;
   int get_size() const;
   void print() const;


   T& operator[](size_t index);
   const T& operator[](size_t index) const;

   /* friend std::ostream& operator<<(std::ostream& out, const Vector<T>& other);
   friend std::istream& operator>>(std::istream& in, Vector<T>& other); */
};

template <typename T>
void Vector<T>::copy(const Vector<T>& other) {
   this->capacity = other.capacity;
   this->size = other.size;
   this->data = new T[other.capacity];
   for(size_t i = 0; i < this->size; ++i) {
      this->data[i] = other.data[i];
   }
}

template <typename T>
void Vector<T>::erase() {
   delete[] this->data;
}

template <typename T>
void Vector<T>::resize() {
   this->capacity *= 2;
   T* temp = new T[this->capacity];

   for(size_t i = 0; i < this->size; ++i) {
      temp[i] = this->data[i];
   }
   delete[] this->data;
   this->data = temp;
}

template <typename T>
Vector<T>::Vector() {
   this->size = 0;
   this->capacity = 8;
   this->data = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
   copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
   if(this != &other) {
      erase();
      copy(other);
   }

   return *this;
}

template <typename T>
Vector<T>::~Vector() {
   erase();
}

template <typename T>
void Vector<T>::push_back(T& element) {
   this->size++;
   if(this->size >= this->capacity) {
      this->resize();
   }

   this->data[this->size - 1] = element;
}

template <typename T>
void Vector<T>::pop_back() {
   if(this->size == 0) {
      std::cerr << "The vector is empty" << std::endl;
      return;
   }

   T* new_array = new T[this->size - 1];
   for(size_t i = 0; i < this->size - 1; ++i) {
      new_array[i] = this->data[i];
   }

   delete[] this->data;
   --this->size;
   this->data = new_array;
}

template <typename T>
void Vector<T>::push_front(T& element) {
   this->size++;
   if(this->size >= this->capacity) {
      this->resize();
   }

   for(size_t i = this->size - 1; i > 0; --i) {
      this->data[i] = this->data[i - 1];
   }
   this->data[0] = element;
}

template <typename T>
bool Vector<T>::is_empty() const {
   if(this->size == 0) {
      return true;
   }
   else {
      return false;
   }
}

template <typename T>
int Vector<T>::get_size() const {
   return this->size;
}

template <typename T>
void Vector<T>::print() const {
   for(size_t i = 0; i < this->size; ++i) {
      std::cout << this->data[i] << ", ";
   }
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
   return this->data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
   return this->data[index];
}

/* template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& other) {
   for(size_t i = 0; i < other.get_size(); ++i) {
         in >> other.data[i];
   }

   return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& other) {
   for(size_t i = 0; i < other.get_size(); ++i) {
      out << other.data[i] << ", ";
   }

   return out;
} */