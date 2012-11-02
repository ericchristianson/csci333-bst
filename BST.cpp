#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** temp = &root;
  //Find the Node
  while(temp != 0 && (*temp)->getValue() != v) {
    if(v < (*temp)->getValue()){
      temp = &((*temp)->getLeftChild());
    }
    else{
      temp = &((*temp)->getRightChild());
    }
  }
  if(temp!= 0){
    Node<T>* nodeToRemove = *temp;
    //Leaf node
    if(nodeToRemove->getLeftChild() == 0 && nodeToRemove->getRightChild() == 0){
      delete nodeToRemove;
      *temp = 0;
    }
    //No right child
    else if(nodeToRemove->getRightChild() == 0){
      *temp = nodeToRemove->getLeftChild();
      delete nodeToRemove;
    }
    //No left child
    else if(nodeToRemove->getLeftChild() == 0){
      *temp = nodeToRemove->getRightChild();
      delete nodeToRemove;
    }
    //Node has two children, use ios
    else{
      //right once
      Node<T>* ios = nodeToRemove->getRightChild();
      //then all the way left
      while(ios->getLeftChild() != 0){
        ios = ios->getLeftChild();
      }
      ios->setLeftChild(*(nodeToRemove->getLeftChild()));
      *temp = nodeToRemove->getRightChild();
      delete nodeToRemove;
    }
  }
}
/*
  //Find the Node
  while(temp != 0 && temp->getValue() != v){
    parent = temp;
    if(v > temp->getRightChild()){
      temp = temp->getRightChild();
    }
    else{
      temp = temp->getLeftChild();
    }
  }

//Node has two children:
  if(temp->getLeftChild() != 0 && temp->getRightChild() != 0){
    //Go right once, check for kids
    Node<T>* curr = temp->getRightChild();
    if(curr->getLeftChild == 0 && curr->getRightChild == 0){
      temp = curr;
      delete temp;
      curr->getRightChild = NULL;
    }
    else{//if right child haz children, go all the way left.
      if(temp->getRightChild()->getLeftChild != 0){
        Node<T>* leftChild;
        Node<T>* leftChildParent;
        leftChildParent = temp->getRightChild();
        leftChild = temp->getRightChild()->getLeftChild();
        while(leftChildParent->getLeftChild() != 0){
          leftChildParent = leftChild;
          leftChild = leftChild->getLeftChild();
        }
//?????
        temp->getValue() = leftChild->getValue();
        delete leftChild;
        leftChildParent->getLeftChild() = NULL;
      }
      else{
        Node<T>* curr;
        curr = temp->getRightChild();
        temp->getValue() = curr->getValue();
        temp->getRightChild() = curr->getRightChild();
        delete temp;
      }
    }
    return;    
  }

//Node has 1 child:
  if(temp->getLeftChild()==0 && temp->getRightChild() != 0 || temp->getLeftChild() != 0 && temp->getRightChild()==0){
    //No left child
    if(temp->getLeftChild()==0 && temp->getRightChild()!=0){
      if(parent->getLeftChild() == temp){
        parent->getLeftChild() = temp->getRightChild();
        delete temp;
      }
      else{
        parent->getRightChild() = temp->getRightChild();
        delete temp;
      }
    }
  
    else{ //No right child
      if(parent->getLeftChild() == temp){
        parent->getLeftChild() = temp->getLeftChild();
        delete temp;
      }
      else{
        parent->getRightChild() = temp->getLeftChild();
        delete temp;
      }
    }
    return;
  }

//Node is a leaf
  if(parent->getLeftChild() == temp){
    parent->getLeftChild() = NULL;
  }
  else{
    parent->getRightChild() = NULL;
  }
  delete temp;
  return;
}
*/
template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
