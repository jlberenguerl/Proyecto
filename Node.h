/* 
 * Autores: 
 * Jose Luis Berenguer. C.I: 20.982.443
 * Felicia Jardim. 	C.I: 21.480.129
 */ 

#ifndef NODE_H
#define NODE_H

#include "Element.h"

class Node
{	
	private:
		Element e;
		Node *firstChild,*nextSibling;
		
	public:
		///-------------Constructores--------------///
		Node(const Element x):e(x),firstChild(NULL),nextSibling(NULL){};
		Node(const Element x,Node* const hi,Node* const hd):e(x),firstChild(hi),nextSibling(hd){};
		Node(const Node &n); // Constructor copia
		
		///------------------- Consultores -----------------///
		Element element() const {return (e);}
		Node *first_Child() const {return (firstChild);}
		Node *next_Sibling() const {return (nextSibling);}
			
		///------------------ Modificadores----------------///	
	    void setElement(const Element x){e=x;}
	    void setFirstChild(Node* const hi = NULL) {firstChild=hi;}
	    void setNextSibling(Node* const hd = NULL) {nextSibling=hd;}
	    
	    ///--------Sobrecarga del operador de igualdad-----///
		Node& operator = (const Node &p);

};

inline Node::Node(const Node &n): e(n.e) ,firstChild(n.firstChild) , nextSibling(n.nextSibling) {} //const copia

Node& Node::operator = (const Node &p)
{
    if(this!=&p){ //el Comprueba que no se esté intentando igualar un objeto a sí mismo
		
        this->e = p.e;
        this->firstChild = p.firstChild;
        this->nextSibling = p.nextSibling;
    }
    
   return *this;
}

#endif
