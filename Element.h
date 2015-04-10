
 /* Autores: 
 * Jose Luis Berenguer. C.I: 20.982.443
 * Felicia Jardim. 	C.I: 21.480.129
 */ 

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
#include <list> 

using namespace std;


class Element
{
	private:
		string tagName,innerHTML;
		std::list<string> attrList;
		
	public:
		///-------------Constructores--------------///
		Element(const string name,std::list<string> l , string inner);	
		Element(const Element &e); // Constructor copia
		
		///------------------- Consultores ----------------///
		string tag_Name() const {return (tagName);}	
		std::list<string> attributeList() const {return (attrList);}
		string inner_HTML() const {return (innerHTML);}
		
		///------------------ Modificadores----------------///	
		void setTagName(const string name) {tagName=name;}
		void setAttributeList(std::list<string> l);
		void setInnerHTML(const string texto) {innerHTML=texto;}
		
		///-----Sobrecarga del operador de = -------///
		Element& operator = (const Element &p);
		
};

inline Element::Element(const Element &e): tagName(e.tagName) ,innerHTML(e.innerHTML), attrList(e.attrList) {} // const copia

Element::Element(const string name, std::list<string> l , string inner)
{
	this->tagName = name;
	l.clear();//  vacia la lista
	inner= ""; // vacio por defecto
	this->attrList = l; // lista vacia por defecto
	this->innerHTML=inner;
}

void Element::setAttributeList(std::list<string> l)
{

	this->attrList.clear();
	string aux;
	while(!l.empty()){
		aux=l.front(); // consulta el primer elemento
		this->attrList.push_back(aux);
		l.pop_front(); // elimina el primer elemento
	}
}

Element& Element::operator = (const Element &p)
{
    if(this!=&p){ //Comprueba que no se esté intentando igualar un objeto a sí mismo
        this->tagName = p.tagName;
        this->innerHTML = p.innerHTML;
        this->attrList = p.attrList;
    }
    return *this;
}

#endif 
