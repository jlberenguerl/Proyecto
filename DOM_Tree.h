/* 
 * Autores: 
 * Jose Luis Berenguer. C.I: 20.982.443
 * Felicia Jardim. 	C.I: 21.480.129
 */ 

#ifndef DOM_TREE_H
#define DOM_TREE_H

#include <iostream>
#include "Node.h"
#include <list>


class DOM_Tree
{
	private:
		Node *document; // este es el nombre por defecto que nos dice el enunciado
		
		static Node* copiarNodos(Node* ptr);
		static void borrar(Node *aux);
		
	public:
	
	///---------Constructores--------///
		
	DOM_Tree(): document(NULL){};
	DOM_Tree(const Element &e,list<DOM_Tree> H);
	
	//constructor copia 
	DOM_Tree(const DOM_Tree &D);
	
	///------------------- Consultores ----------------///
	
	
	
	///------------------ Modificadores----------------///
	void copiar(const DOM_Tree &D);
	void removeChild(int pos);
	
	// Sobrecarga del = 
	DOM_Tree& operator = (const DOM_Tree &orig);
	
	
	//destructores
	void destruir();
	~DOM_Tree();

};

DOM_Tree::DOM_Tree(const Element &e, list<DOM_Tree> H)
{
	/*** Crea un arbol cuyos hijos vienen en la lista.**/
	
	Node *aux;
	DOM_Tree arbol_aux;
	
	document = new Node(e, NULL, NULL);
	
	if(!H.empty()) // si no esta vacia la lista
	{
		arbol_aux.copiar(H.front());
		document->setFirstChild(arbol_aux.document);
		aux = document->first_Child();
		H.pop_front();
		
		while(!H.empty())
		{
			arbol_aux.copiar(H.front());
			H.pop_front();
			aux->setNextSibling(arbol_aux.document);
			aux = aux->next_Sibling();
		}
	}
	
	arbol_aux.document = NULL; //DE LO CONTRARIO SE DESTRUIRA EL ULTIMO SUBARBOL QUE ACABAMOS DE COPIAR	
}

void DOM_Tree::copiar(const DOM_Tree &D)
{
    if(D.document == NULL)
		document = NULL;
	else
		document = new Node(D.document->element(), copiarNodos(D.document->first_Child()), NULL);
}

Node* DOM_Tree::copiarNodos(Node *ptr)
{
	/*** Procedimiento recursivo que se usa en el constructor copia del arbol.**/
	Node *nuevo;
	
	if(ptr == NULL)
		nuevo = NULL;
	else
		nuevo = new Node(ptr->element(),copiarNodos(ptr->first_Child()),copiarNodos(ptr->next_Sibling()));
	return (nuevo);
}

//Constructor copia
DOM_Tree::DOM_Tree(const DOM_Tree &D)
{
	copiar(D);
	
}

//sobrecarga del operador de igualdad
DOM_Tree& DOM_Tree::operator=(const DOM_Tree &orig)
{
	copiar(orig);
	
   return *this;
}

//removeChild
void DOM_Tree::removeChild(int pos)
{
	Node *aux;
	DOM_Tree elim;
	int i;
	
	if(pos == 1){
		elim.document = document->first_Child();
		if(document->first_Child() != NULL)
		{
			document->setFirstChild(document->first_Child()->next_Sibling());
		}
			}else{
				aux = document->first_Child();
					for(i=2; i<pos; i++ )
					{
						if(aux != NULL)
						{	
							aux = aux->next_Sibling();
						}
					}
		if(aux != NULL)
		{
			elim.document = aux->next_Sibling();
			aux->setNextSibling(aux->next_Sibling()->next_Sibling());
		}
	}
	elim.destruir();
}

///-----Destructores-----///

void DOM_Tree::destruir()
{
	borrar(document);
	document = NULL;
} 
  
void DOM_Tree::borrar(Node *aux) // privado de la clase por los apuntadores a nodo
{
	Node *ptr;
	if(aux != NULL)
	{
		borrar(aux->first_Child());
		ptr = aux;
		aux = aux->next_Sibling();
		delete (ptr);
		borrar(aux);
	}
}

DOM_Tree::~DOM_Tree()
{
   destruir();
}

#endif 
