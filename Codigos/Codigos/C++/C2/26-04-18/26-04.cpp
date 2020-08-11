class Node{
private: 
	int info;
	Node* prox;
public:
	Node(int info, Node* prox = null);
	void insereFim(Node* node);
	void insereOrdenado(Node** ant, Node* node);
	void removeFim(Node**ant){ // void Node::removeFim(Node**ant)
		if(!this->prox){
			delete this; // delete (*ant)
			(*ant) = NULL;
		}else
			prox->removeFim(&prox);

		/*
	bool Node ::removeFim(){
		if(this->prox){
			bool b = this->prox->removeFim();
			if(b)
				this->prox = NULL;
			return false;
		}else{
			delete this;
			return true;
		}
	}
		*/
	}

	bool removeInfo(Node** ant, int info){
		if(this->info == info){
			(*ant) = prox;
			prox = NULL;
			delete this;
			return true;
		}else{
			if(this->prox){
				return this->prox->removeInfo(&prox, info);
			}
			return false;
		}
	}

	int getInfo();
	Node* getProx(){ // Node* Node::getProx()
		return this->prox;
	}
	void setProx(Node* prox){ // void Node::setProx(...)
		this->prox = prox;
	}
	~Node();
};

class Lista{
private: 
	Node * H;
	// mesmo .h declarar a classe Node dentro da classe Lista
public:
	void removeInicio(){ // void Lista::removeInicio();
		if(H){ // H != NULL
			Node* aux = H;
			H = H->getProx();
			aux->setProx(NULL);
			delete aux;
		}
	}

	void removeFim(Node**ant){ // void Lista::removeFim(Node**ant)
		if(H){
			H->removeFim(&H);
		}
		/*
		if((H) && H -> removeLista()){
			H = NULL;
		}
		*/

	bool removeInfo(int info){
		if(H){
			return H->removeInfo(&H, info);
		}else{
			return false;
		}
	}




}