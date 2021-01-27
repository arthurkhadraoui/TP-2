#include "magasin.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>

namespace vente {

	Magasin::Magasin(){

	}

	std::vector<Commande> Magasin::getOrders() const{
		return m_orders;
	}

	void Magasin::addProduct(std::string name, std::string description, int quantity, double price){
		Produit produit(name,description,quantity,price);//Création du produit à partir des données
		m_products.push_back(produit);//Ajout du produit au stock
	}

	void Magasin::updateQuantity(std::string prodname, int quantity){
		auto it = m_products.begin(); //Iterateur pour parcourir le vector
		it = std::find_if(it, m_products.end(),
			[prodname](const Produit produit) {
				return produit.getName() == prodname;
		}); //Retrouve le produit souhaité
		int index = std::distance(m_products.begin(), it); //Stock la position du produit dans la liste
		m_products.at(index).setQuantity(quantity); //Modifie la quantité du produit dans le stock
	}

	void Magasin::displayAllProducts() const {
		//Préparation de l'affichage
		for (int i = 0; i < 75; i++){
			std::cout << "-";
		}
		std::cout << std::endl;
		std::cout << "|Produits";
		for (int i = 0; i<65 ; i++){
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
		std::cout << "|";
		for (int i = 0; i < 73; i++){
			std::cout << "-";
		}
		std::cout << "|" << std::endl;
		std::cout << "|Name             Description                       Quantity      Price   |" << std::endl;

		std::cout << "|";
		for (int i = 0; i < 73; i++){
			std::cout << "-";
		}
		std::cout << "|" << std::endl;
		//Pour chaque produit du magasin
		for(int i = 0; i < int(m_products.size()); i++){
			std::cout << "|";
			std::cout << m_products.at(i); //Affichage du produit
			std::cout << "|";
			std::cout << std::endl;
		}
		for (int i = 0; i < 75; i++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}

	void Magasin::displayProduct(std::string name){
		auto it = m_products.begin(); //Iterateur dans le vector
		it = std::find_if(it, m_products.end(),
			[name](const Produit produit) {
				return produit.getName()==name;
			}); //récupération du produit souhaité
		int index = std::distance(m_products.begin(), it); //Stock la position du produit dans la liste
		//Préparation de l'affichage
		for (int i = 0; i < 75; i++){
			std::cout << "-";
		}
		std::cout << std::endl;
		std::cout << "|Details du produit";
		for (int i = 0; i < 55 ; i++){
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
		std::cout << "|";
		for (int i = 0; i < 73; i++){
			std::cout << "-";
		}
		std::cout << "|" << std::endl;
		std::cout << "|Name             Description                       Quantity      Price   |" << std::endl;

		std::cout << "|";
		for (int i = 0; i < 73; i++){
			std::cout << "-";
		}
		std::cout << "|" << std::endl;
		std::cout << "|";
		std::cout << m_products.at(index); //Affichage du produit
		std::cout << "|";
		std::cout << std::endl;

		for (int i = 0; i < 75; i++){
			std::cout << "-";
		}
		std::cout << std::endl;
	}

	bool Magasin::checkUids(int testnb){
		auto it = std::find(m_uids.begin(), m_uids.end(), testnb);
		if (it != m_uids.end()){ //Si l'id existe retourne true
			return true;
		}
		return false;
	}

	void Magasin::addCustomer(std::string prenom, std::string nom){
		std::ofstream fichier;
		int uid=rand(); //Génère l'ID de l'utilisateur
		while(checkUids(uid)==true){ //Vérifie son unicité
			uid=rand();
		}
		fichier.open("clients.txt", std::ios_base::app); //Ouvre le fichier pour enregistrer les clients
		fichier<<uid<<" "<<prenom<<" "<<nom<<std::endl;
		fichier.close(); //Referme le fichier
		vente::Client client(uid,nom,prenom);//Créer le client en fonction des informations
		m_uids.push_back(uid); //Ajout de l'ID à la liste des ID
		m_clients.push_back(client); //Ajout du client à la liste des clients
	}

	void Magasin::displayCustomers()const {
		//Préparation de l'affichage
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Clients";
		for (int i=0; i<66 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;
		for(int i=0; i<int(m_clients.size());i++){
			std::cout<<"|";
			std::cout<<m_clients.at(i); //Afichage du client
			std::cout<<"|";
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayCustomer(std::string prenom, std::string nom){
		auto it = m_clients.begin(); //Iterateur pour le vecteur
		it = std::find_if(it, m_clients.end(),
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int index = std::distance(m_clients.begin(), it); //Position du client dans la liste

		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Client";
		for (int i=0; i<67 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;

		std::cout<<"|";
		std::cout<<m_clients.at(index); //Affichage du client
		std::cout<<"|";
		std::cout<<std::endl;

		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayCustomer(int uid){
		if (checkUids(uid)==true){ //Création de l'iterateur du vector
			auto it = m_clients.begin();
			it = std::find_if(it, m_clients.end(),
				[uid](const Client client) {
					return client.getID()==uid;
				});
			int index = std::distance(m_clients.begin(), it); //Récupère la position du client
			//Préparation de l'affichage
			for (int i=0; i<75;i++){
				std::cout<<"-";
			}
			std::cout<<std::endl;
			std::cout<<"|Client";
			for (int i=0; i<67 ;i++){
				std::cout<<" ";
			}
			std::cout<<"|"<<std::endl;
			std::cout<<"|";
			for (int i=0; i<73;i++){
				std::cout<<"-";
			}
			std::cout<<"|"<<std::endl;
			std::cout<<"|ID            Full name                                                  |"<<std::endl;
			std::cout<<"|";
			std::cout<<m_clients.at(index); //Affichage du client
			std::cout<<"|";
			std::cout<<std::endl;
			for (int i=0; i<75;i++){
				std::cout<<"-";
			}
			std::cout<<std::endl;
		}
		else{
			std::cout<<"Client non trouve!"<<std::endl; //Message d'erreur si le client demandé n'existe pas
		}
	}

	bool Magasin::checkOrderNum(int testnb){
		auto it = std::find(orders_num.begin(), orders_num.end(), testnb);
		if (it != orders_num.end()){ //Vérifie si le numéro de commande existe
			return true;
		}
		return false;
	}

	void Magasin::addOrder(std::string prenom, std::string nom){
		int num=rand(); //Génère le numéro de commande
		while(checkOrderNum(num)==true){ //Vérifie son unicité
			num=rand();
		}
		auto it = m_clients.begin(); //Recherche du clients
		it = std::find_if(it, m_clients.end(),
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int index = std::distance(m_clients.begin(), it); //Position du client dans la lsite des clients
		Commande order(num,m_clients.at(index)); //Création de la commande
		m_orders.push_back(order); //Ajoute la commande
		clearCart(prenom,nom); //Vide le panier du client une fois le bon de commande fait
	}

	void Magasin::validateCommande(int orderNum){
		auto it = m_orders.begin(); //Retrouve la commande
		it = std::find_if(it, m_orders.end(),
			[orderNum](const Commande order) {
				return (order.getNumero()==orderNum);
			});
		int index = std::distance(m_orders.begin(), it); //Position de la commande dans la liste
		m_orders.at(index).setStatut(Commande::Statut::Valide); //Change le statut de la commande pour la validé
		for (int i=0;i<int(m_orders.at(index).getProducts().size());i++){ //Boucle qui retire la quantité de chaque produit dans le stock
			std::string name = m_orders.at(index).getProducts().at(i).getName();
			auto itP = m_products.begin();
			itP = std::find_if(itP, m_products.end(),
				[name](const Produit produit) {
					return (produit.getName()==name);
				});
			int indexP = std::distance(m_products.begin(), itP);
			int less =(m_products.at(indexP).getQuantity())-(m_orders.at(index).getProductQuantity().at(indexP));
			m_products.at(indexP).setQuantity(less); //Retire la quantité du stock
		}
	}

	void Magasin::switchStatuts(int orderNum, int s){
		auto it = m_orders.begin(); //Récupère la commande
		it = std::find_if(it, m_orders.end(),
			[orderNum](const Commande order) {
				return (order.getNumero()==orderNum);
			});
		int index = std::distance(m_orders.begin(), it); //Position de la commande dans la liste
		switch (s) { //Change le statut par celui souhaité
			case 0: m_orders.at(index).setStatut(Commande::Statut::Valide);break;
			case 1: m_orders.at(index).setStatut(Commande::Statut::EnAttente);break;
			case 2: m_orders.at(index).setStatut(Commande::Statut::Refuse);break;
			default: break;
		}

	}

	void Magasin::displayOrders(){
		//Préparation de l'affichage
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Commandes";
		for (int i=0; i<64 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Numero      Client                   Statut          Produits            |"<<std::endl;
		for(int i=0;i<int(m_orders.size());i++){
			std::cout<<"|";
			std::cout<<m_orders.at(i); //Affichage de la commande

			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayOrdersFromCustomer(std::string prenom, std::string nom){
		std::vector<Commande> ordersFromCustomer; //Liste des commandes d'un client
		auto it = m_orders.begin();
		while(it!=m_orders.end()){ //Recherche toutes les commandes du clients
			it = std::find_if(it, m_orders.end(),
				[nom,prenom](const Commande order) {
					return (order.getClient().getName()==nom && order.getClient().getFirstName()==prenom);
				});
			int index = std::distance(m_orders.begin(), it);
			ordersFromCustomer.push_back(m_orders.at(index)); //Ajoute les commandes à la liste
			it++;
		}
		//Préparation de l'affichage
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Commandes";
		for (int i=0; i<64 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Numero      Client                   Statut          Produits            |"<<std::endl;
		for(int i=0;i<int(ordersFromCustomer.size());i++){
			std::cout<<"|";
			std::cout<<ordersFromCustomer.at(i); //Affichage des commandes de l'utilisateur

			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::addProductCart(std::string nproduit, std::string prenom, std::string nom){
		auto itC = m_clients.begin(); //Iterator du vector client
		itC = std::find_if(itC, m_clients.end(), //Récupération du client
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int indexClient = std::distance(m_clients.begin(), itC); //Position du client dans la liste

		auto itP = m_products.begin(); //Iterator du vector produit
		itP = std::find_if(itP, m_products.end(), //Récupération du produit
			[nproduit](const Produit produit) {
				return produit.getName()==nproduit;
			});
		int indexproduct = std::distance(m_products.begin(), itP); //Position du produit dans le panier

		m_clients.at(indexClient).add(m_products.at(indexproduct)); //Ajout du produit à la commande du client
	}

	void Magasin::addProductCart(std::string nproduit,int uid){
		auto itC = m_clients.begin(); //Iterator du vector client
		itC = std::find_if(itC, m_clients.end(), //Récupération du client
			[uid](const Client client) {
				return client.getID()==uid;
			});
		int indexC = std::distance(m_clients.begin(), itC); //Position du client dans la liste

		auto itP = m_products.begin(); //Iterator du vector produit
		itP = std::find_if(itP, m_products.end(), //Récupération du produit
			[nproduit](const Produit produit) {
				return produit.getName()==nproduit;
			});
		int indexproduct = std::distance(m_products.begin(), itP); //Position du produit dans la liste

		m_clients.at(indexC).add(m_products.at(indexproduct)); //Ajout du produit à la commande du client
	}

	void Magasin::updateProductQuantityCart(std::string nproduit,int quantity ,std::string prenom, std::string nom){
		auto itC = m_clients.begin(); //Iterator du client
		itC = std::find_if(itC, m_clients.end(), //récupération du client
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int indexClient = std::distance(m_clients.begin(), itC); //Position du client dans la liste

		auto itP = m_products.begin(); //Iterator du vector produit
		itP = std::find_if(itP, m_products.end(), //Récupération du produit
			[nproduit](const Produit produit) {
				return produit.getName()==nproduit;
			});
		int indexproduct = std::distance(m_products.begin(), itP); //Position du produit dans la liste
		m_clients.at(indexClient).modifyQuantity(m_products.at(indexproduct),quantity); //Mise à jour de la quantité du produit dans la commande
	}

	void Magasin::removeProductCart(std::string nproduit, std::string prenom, std::string nom){
		auto itC = m_clients.begin(); //Iterator du client
		itC = std::find_if(itC, m_clients.end(), //Récupération du client
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int indexClient = std::distance(m_clients.begin(), itC); //Position du client dans la liste

		auto itP = m_products.begin(); //Iterator du vector produit
		itP = std::find_if(itP, m_products.end(), //Récupération du produit
			[nproduit](const Produit produit) {
				return produit.getName()==nproduit;
			});
		int indexproduct = std::distance(m_products.begin(), itP);  //Position du produit dans la liste
		m_clients.at(indexClient).deleteProduct(m_products.at(indexproduct)); //Suppression du produit dans la commande
	}

	void Magasin::clearCart(std::string prenom, std::string nom){
		auto itC = m_clients.begin(); //Iterator du client
		itC = std::find_if(itC, m_clients.end(), //Récupération du client
			[nom,prenom](const Client client) {
				return (client.getName()==nom && client.getFirstName()==prenom);
			});
		int indexClient = std::distance(m_clients.begin(), itC); //Position du produit dans la liste
		m_clients.at(indexClient).clearProducts(); //Suppression de tout les produits de la commande
	}

	void Magasin::loadCustomers(){
		std::ifstream fichier ("clients.txt"); //Chargement du fichiers de sauvegarde des clients
		std::string prenom, nom;
		int uid;
		while (fichier>>uid>>prenom>>nom){ //Ajout des données de chaque client dans la liste des clients
			Client client(uid,nom,prenom);
			m_clients.push_back(client);
			m_uids.push_back(uid);
		}
	}

}
